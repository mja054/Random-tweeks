#include <stdio.h>
#include "xdr.h"
#include <string.h>
#include <errno.h>
//#include <rpc/xdr.h>
int
main ()
{
        char *a = "asap";
        int fd = 1;
        struct my_struct xdr_res, xdr_st = {.object = a, .fd = fd};
        XDR xdr, xdr1;
        char b[100];

        xdrmem_create (&xdr, b, sizeof (b), XDR_ENCODE);

        if (!xdr_my_struct (&xdr, &xdr_st)) {
                fprintf (stderr, "xdr conversion failed, %s\n", strerror (errno));
                return -1;
        }
        xdr_res.object=malloc(1000);
        xdrmem_create (&xdr1, b, sizeof (b), XDR_DECODE);
        if (!xdr_my_struct (&xdr1, &xdr_res)) {
                fprintf (stderr, "xdr conversion failed, %s\n", strerror (errno));
                return -1;
        }

        return 0;
}
