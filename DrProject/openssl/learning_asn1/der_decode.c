#include <stdio.h>
#include <openssl/x509.h>
#include <stdlib.h>

int main()
{
    X509    *x;
    FILE    *fp;
    unsigned char buf[5000], *p;
    int     len, ret;
    BIO     *b;

    fp = fopen("cert.cer", "rb");
    if ( !fp )
        return -1;
    len = fread(buf, 1, 5000, fp);
    fclose(fp);

    p = buf;
    x = X509_new();
    d2i_X509(&x, (const unsigned char **)&p, len);
    b = BIO_new(BIO_s_file());
    BIO_set_fp(b, stdout, BIO_NOCLOSE);
    ret = X509_print(b, x);
    BIO_free(b);
    X509_free(x);

    return 0;
}
