/*
 * asn1各种数据类型编码的展开
 */

/*
 * ASN1_INTEGER
 */
ASN1_INTEGER *ASN1_INTEGER_new()
{
    return (ASN1_INTEGER *)ASN1_item_new(ASN1_ITEM_rptr(ASN1_INTEGER));
}
ASN1_VALUE *ASN1_item_new(const ASN1_ITEM *it)
{
    ASN1_VALUE *ret = NULL;
    if ( ASN1_item_ex_new(&ret, it) > 0 )
        return ret;
    return NULL;
}
int ASN1_item_ex_new(ASN1_VALUE **pval, const ASN1_ITEM *it)
{
    return asn1_item_ex_combine_new(pval, it, 0);
}

static int asn1_item_ex_combine_new(ASN1_VALUE **pval, const ASN1_ITEM *it, int combine)
{
    const ASN1_TEMPLATE *tt = NULL;
    const ASN1_COMPAT_FUNCS *cf;
    const ASN1_EXTERN_FUNCS *ef;
    const ASN1_AUX *aux = it->funcs;
    ASN1_aux_cb *asn1_cb;
    ASN1_VALUE **pseqval;
    int i;
    if ( aux && aux->asn1_cb )
        asn1_cb = aux->asn1_cb;
    else
        asn1_cb = 0;

    if ( !combine )
        *pval = NULL;
#ifdef CRYPTO_MDEBUG
    if ( it->sname )
        CRYPTO_push_info(it->sname);
#endif
    //combine = ASN1_ITYPE_PRIMITIVE
    if ( it->templates )
    {
        if ( !ASN1_template_new(pval, it->templates) )
            goto memerr;
    }
    else if ( !ASN1_primitive_new(pval, it) )
        goto memerr;

#ifdef CRYPTO_MDEBUG
    if ( it->sname )
        CRYPTO_pop_info();
#endif
    return 1;

memerr:
    ASN1err(ASN1_F_ASN1_ITEM_EX_COMBINE_NEW, ERR_R_MALLOC_FAILURE);
#ifdef CRYPTO_MDEBUG
    if ( it->sname )
        CRYPTO_pop_info();
#endif
    return 0;

auxerr:
    ASN1err(ASN1_F_ASN1_ITEM_EX_COMBINE_NEW, ASN1_R_AUX_ERROR);
    ASN1_item_ex_free(pval, it);
#ifdef CRYPTO_MDEBUG
    if ( it->sname )
        CRYPTO_pop_info();
#endif
    return 0;
}

void ASN1_INTEGER_free(ASN1_INTEGER *a)
{
    ASN1_item_free((ASN1_VALUE *)a, ASN1_ITEM_rptr(ASN1_INTEGER));
}

void ASN1_item_free(ASN1_VALUE *val, const ASN1_ITEM *it)
{
    asn1_item_combine_free(&val, it, 0);
}

static void asn1_item_combine_free(ASN1_VALUE **pval, const ASN1_ITEM *it, int combine)
{
    const ASN1_TEMPLATE *tt = NULL, *seqtt;
    const ASN1_EXTERN_FUNCS *ef;
    const ASN1_COMPAT_FUNCS *cf;
    const ASN1_AUX *aux = it->funcs;
    ASN1_AUX_cb *asn1_cb;
    int i;

    if ( !pval )
        return;
    if ( (it->itype != ASN1_ITYPE_PRIMITIVE) && !*pval )
        return;
    if ( aux && aux->asn1_cb )
        asn1_cb = aux->asn1_cb;
    else
        asn1_cb = 0;

    if ( it->templates )
        ASN1_template_free(pval, it->templates);
    else
        ASN1_primitive_free(pval, it);
}

int ASN1_INTEGER_set(ASN1_INTEGER *a, long v)
{
    int j, k;
    unsigned int i;
    unsigned char buf[sizeof(long) + 1];
    long d;

    a->type = V_ASN1_INTEGER;
    if (a->length < (int)(sizeof(long) + 1)) {
        if (a->data != NULL)
            OPENSSL_free(a->data);
        if ((a->data =
             (unsigned char *)OPENSSL_malloc(sizeof(long) + 1)) != NULL)
            memset((char *)a->data, 0, sizeof(long) + 1);
    }
    if (a->data == NULL) {
        ASN1err(ASN1_F_ASN1_INTEGER_SET, ERR_R_MALLOC_FAILURE);
        return (0);
    }
    d = v;
    if (d < 0) {
        d = -d;
        a->type = V_ASN1_NEG_INTEGER;
    }

    for (i = 0; i < sizeof(long); i++) {
        if (d == 0)
            break;
        buf[i] = (int)d & 0xff;
        d >>= 8;
    }
    j = 0;
    for (k = i - 1; k >= 0; k--)
        a->data[j++] = buf[k];
    a->length = j;
    return (1);
}

int i2d_ASN1_INTEGER(const ASN1_INTEGER *a, unsigned char **out)
{
    return ASN1_item_i2d((ASN1_VALUE *)a, out, ASN1_ITEM_rptr(ASN1_INTEGER));
}

int ASN1_item_i2d(ASN1_VALUE *val, unsigned char **out, const ASN1_ITEM *it)
{
    return asn1_item_flags_i2d(val, out, it, 0);
}

static int asn1_item_flags_i2d(ASN1_VALUE *val, unsigned char **out,
                               const ASN1_ITEM *it, int flags)
{
    if (out && !*out) {
        unsigned char *p, *buf;
        int len;
        len = ASN1_item_ex_i2d(&val, NULL, it, -1, flags);
        if (len <= 0)
            return len;
        buf = OPENSSL_malloc(len);
        if (!buf)
            return -1;
        p = buf;
        ASN1_item_ex_i2d(&val, &p, it, -1, flags);
        *out = buf;
        return len;
    }

    return ASN1_item_ex_i2d(&val, out, it, -1, flags);
}

int ASN1_item_ex_i2d(ASN1_VALUE **pval, unsigned char **out,
                     const ASN1_ITEM *it, int tag, int aclass)
{
    const ASN1_TEMPLATE *tt = NULL;
    unsigned char *p = NULL;
    int i, seqcontlen, seqlen, ndef = 1;
    const ASN1_COMPAT_FUNCS *cf;
    const ASN1_EXTERN_FUNCS *ef;
    const ASN1_AUX *aux = it->funcs;
    ASN1_aux_cb *asn1_cb = 0;

    if ((it->itype != ASN1_ITYPE_PRIMITIVE) && !*pval)
        return 0;

    if (aux && aux->asn1_cb)
        asn1_cb = aux->asn1_cb;
	if (it->templates)
            return asn1_template_ex_i2d(pval, out, it->templates,
                                        tag, aclass);
        return asn1_i2d_ex_primitive(pval, out, it, tag, aclass);
	return 0;
}

static int asn1_i2d_ex_primitive(ASN1_VALUE **pval, unsigned char **out,
                                 const ASN1_ITEM *it, int tag, int aclass)
{
    int len;
    int utype;
    int usetag;
    int ndef = 0;

    utype = it->utype;

    /*
     * Get length of content octets and maybe find out the underlying type.
     */

    len = asn1_ex_i2c(pval, NULL, &utype, it);

    /*
     * If SEQUENCE, SET or OTHER then header is included in pseudo content
     * octets so don't include tag+length. We need to check here because the
     * call to asn1_ex_i2c() could change utype.
     */
    if ((utype == V_ASN1_SEQUENCE) || (utype == V_ASN1_SET) ||
        (utype == V_ASN1_OTHER))
        usetag = 0;
    else
        usetag = 1;

    /* -1 means omit type */

    if (len == -1)
        return 0;

    /* -2 return is special meaning use ndef */
    if (len == -2) {
        ndef = 2;
        len = 0;
    }

    /* If not implicitly tagged get tag from underlying type */
    if (tag == -1)
        tag = utype;

    /* Output tag+length followed by content octets */
    if (out) {
        if (usetag)
            ASN1_put_object(out, ndef, len, tag, aclass);
        asn1_ex_i2c(pval, *out, &utype, it);
        if (ndef)
            ASN1_put_eoc(out);
        else
            *out += len;
    }

    if (usetag)
        return ASN1_object_size(ndef, len, tag);
    return len;
}

ASN1_INTEGER *d2i_ASN1_INTEGER(ASN1_INTEGER **a, const unsigned char **in, long len)
{
    return (ASN1_INTEGER *)ASN1_item_d2i((ASN1_INTEGER **)a, in, len, ASN1_ITEM_rptr(ASN1_INTEGER));
}

ASN1_VALUE *ASN1_item_d2i(ASN1_VALUE **pval,
                          const unsigned char **in, long len,
                          const ASN1_ITEM *it)
{
    ASN1_TLC c;
    ASN1_VALUE *ptmpval = NULL;
    if (!pval)
        pval = &ptmpval;
    asn1_tlc_clear_nc(&c);
    if (ASN1_item_ex_d2i(pval, in, len, it, -1, 0, 0, &c) > 0)
        return *pval;
    return NULL;
}

int ASN1_item_ex_d2i(ASN1_VALUE **pval, const unsigned char **in, long len,
                     const ASN1_ITEM *it,
                     int tag, int aclass, char opt, ASN1_TLC *ctx)
{
    const ASN1_TEMPLATE *tt, *errtt = NULL;
    const ASN1_COMPAT_FUNCS *cf;
    const ASN1_EXTERN_FUNCS *ef;
    const ASN1_AUX *aux = it->funcs;
    ASN1_aux_cb *asn1_cb;
    const unsigned char *p = NULL, *q;
    unsigned char *wp = NULL;   /* BIG FAT WARNING! BREAKS CONST WHERE USED */
    unsigned char imphack = 0, oclass;
    char seq_eoc, seq_nolen, cst, isopt;
    long tmplen;
    int i;
    int otag;
    int ret = 0;
    ASN1_VALUE **pchptr, *ptmpval;
    if (!pval)
        return 0;
    if (aux && aux->asn1_cb)
        asn1_cb = aux->asn1_cb;
    else
        asn1_cb = 0;
	if (it->templates) {
            /*
             * tagging or OPTIONAL is currently illegal on an item template
             * because the flags can't get passed down. In practice this
             * isn't a problem: we include the relevant flags from the item
             * template in the template itself.
             */
            if ((tag != -1) || opt) {
                ASN1err(ASN1_F_ASN1_ITEM_EX_D2I,
                        ASN1_R_ILLEGAL_OPTIONS_ON_ITEM_TEMPLATE);
                goto err;
            }
            return asn1_template_ex_d2i(pval, in, len,
                                        it->templates, opt, ctx);
        }
        return asn1_d2i_ex_primitive(pval, in, len, it,
                                     tag, aclass, opt, ctx);
auxerr:
    ASN1err(ASN1_F_ASN1_ITEM_EX_D2I, ASN1_R_AUX_ERROR);
err:
    ASN1_item_ex_free(pval, it);
    if (errtt)
        ERR_add_error_data(4, "Field=", errtt->field_name,
                           ", Type=", it->sname);
    else
        ERR_add_error_data(2, "Type=", it->sname);
	return 0;
}
