/*
 * asn1基本类型asn1_string的基本操作 
 *
 */
//这个str应该改为src，意思才更符合
int ASN1_STRING_copy(ASN1_STRING *dst, const ASN1_STRING *str) 
{
    if ( str == NULL )
        return 0;
    dst->type = str->type;
    if ( !ASN1_STRING_set(dst, str->data, str->length) )
        return 0;
    dst->flags = str->flags;

    return 1;
}

ASN1_STRING *ASN1_STRING_dup(const ASN1_STRING *str)
{
    ASN1_STRING *ret;
    if ( !str )
      return NULL;
    ret = ASN1_STRING_new();
    if ( !ret )
      return NULL;
    if ( !ASN1_STRING_copy(ret, str) )
    {
      ASN1_STRING_free(ret);
      return NULL;
    }
    
    return ret;
}



