#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 

#ifdef _WIN32
#define PRINTER_DEVICE "LPT1:"
#else  /* assume unix */
#define PRINTER_DEVICE "/dev/lp0"
#endif

/*
LPT1:
LPT
PRN :
PRN
*/

int main(void)
{
    FILE* prnt;

    prnt = fopen(PRINTER_DEVICE, "w");
    /* should check for errors if stdprn == NULL */

    if (prnt == NULL)
        printf("error opening printer\n");    
    else
        fprintf(prnt, "This is a test.\n");

    fclose(prnt);
    return 0;
}