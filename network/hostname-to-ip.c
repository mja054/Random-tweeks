#include <netdb.h>
#include <stdio.h>

/* The hostent structure is defined in <netdb.h> as follows: */

/* struct hostent { */
/*         char  *h_name;            /\* official name of host *\/ */
/*         char **h_aliases;         /\* alias list *\/ */
/*         int    h_addrtype;        /\* host address type *\/ */
/*         int    h_length;          /\* length of address *\/ */
/*         char **h_addr_list;       /\* list of addresses *\/ */
/* } */
/* #define h_addr h_addr_list[0] */
int
main ()
{
        struct hostent* host;
        host = gethostbyname("lwn.net");
        if (!host)
                perror ("gethostbyname returned NULL\n");
        else {
                printf ("gethostbyname is successful\n");
                printf("IP address = %s\n", 
                       inet_ntoa(*(long*)host->h_addr_list[0]));
        }
}
