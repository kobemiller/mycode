#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define V_ASN1_UNIVERSAL        0x00
#define V_ASN1_PRIVATE          0xc0
#define V_ASN1_PRIMITIVE_TAG    0X1f
#define V_ASN1_CONSTRUCTED      0x20
#define V_ASN1_BOOLEAN          1
#define V_ASN1_OBJECT           6

int ASN1_object_size(int constructed, int length, int tag)
{
    int ret;

    ret = length;
    ret++;
    if (tag >= 31) {
        while (tag > 0) {
            tag >>= 7;
            ret++;
        }
    }
    if (constructed == 2)
        return ret + 3;
    ret++;
    if (length > 127) {
        while (length > 0) {
            length >>= 8;
            ret++;
        }
    }
    return (ret);
}

static void asn1_put_length(unsigned char **pp, int length)
{
    unsigned char *p = *pp;
    int i, l;
    if (length <= 127)
        *(p++) = (unsigned char)length;
    else {
        l = length;
        for (i = 0; l > 0; i++)
            l >>= 8;
        *(p++) = i | 0x80;
        l = i;
        while (i-- > 0) {
            p[i] = length & 0xff;
            length >>= 8;
        }
        p += l;
    }
    *pp = p;
}

void ASN1_put_object(unsigned char **pp, int constructed, int length, int tag,
                     int xclass)
{
    unsigned char *p = *pp;
    int i, ttag;

    i = (constructed) ? V_ASN1_CONSTRUCTED : 0;
    i |= (xclass & V_ASN1_PRIVATE);
    if (tag < 31)
        *(p++) = i | (tag & V_ASN1_PRIMITIVE_TAG);
    else {
        *(p++) = i | V_ASN1_PRIMITIVE_TAG;
        for (i = 0, ttag = tag; ttag > 0; i++)
            ttag >>= 7;
        ttag = i;
        while (i-- > 0) {
            p[i] = tag & 0x7f;
            if (i != (ttag - 1))
                p[i] |= 0x80;
            tag >>= 7;
        }
        p += ttag;
    }
    if (constructed == 2)
        *(p++) = 0x80;
    else
        asn1_put_length(&p, length);
    *pp = p;
}

int i2d_ASN1_BOOLEAN(int a, unsigned char **pp)
{
    int r;
    unsigned char *p;

    r = ASN1_object_size(0, 1, V_ASN1_BOOLEAN);
    if (pp == NULL)
        return (r);
    p = *pp;

    ASN1_put_object(&p, 0, 1, V_ASN1_BOOLEAN, V_ASN1_UNIVERSAL);
    *(p++) = (unsigned char)a;
    *pp = p;
    return (r);
}

/*
int d2i_ASN1_BOOLEAN(int *a, const unsigned char **pp, long length)
{
    int ret = -1;
    const unsigned char *p;
    long len;
    int inf, tag, xclass;
    int i = 0;

    p = *pp;
    inf = ASN1_get_object(&p, &len, &tag, &xclass, length);
    if (inf & 0x80) {
        i = ASN1_R_BAD_OBJECT_HEADER;
        goto err;
    }

    if (tag != V_ASN1_BOOLEAN) {
        i = ASN1_R_EXPECTING_A_BOOLEAN;
        goto err;
    }

    if (len != 1) {
        i = ASN1_R_BOOLEAN_IS_WRONG_LENGTH;
        goto err;
    }
    ret = (int)*(p++);
    if (a != NULL)
        (*a) = ret;
    *pp = p;
    return (ret);
 err:
    ASN1err(ASN1_F_D2I_ASN1_BOOLEAN, i);
    return (ret);
}
*/

int main()
{
    char *p[4];
    int i;
    for ( i = 0; i < 4; i++ )
    {
        p[i] = malloc(256);
        memset(p[i], 0, sizeof(p[i]));
    }

    p[1] = "kobe";
    p[2] = "michael";
    p[3] = "paul";
    unsigned char **pp = &p;
    int r = i2d_ASN1_BOOLEAN(3, pp);
    printf("%d\n", r);

    return 0;
}
