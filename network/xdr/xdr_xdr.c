/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "xdr.h"

bool_t
xdr_my_struct (XDR *xdrs, my_struct *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->object, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->fd))
		 return FALSE;
	return TRUE;
}
