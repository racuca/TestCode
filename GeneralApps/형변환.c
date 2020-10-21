
#include <stdio.h>

void sssss(char* ch)
{
    printf("%02x %02x\n", ch[0], ch[1]);
}

void test(void)
{
    int jari = 255 * 2 + 1;

    unsigned char jari2 = 0;

    jari2 = *(char*)&jari; 
    sssss(&jari2);

    char* p = (char*)&jari;
    sssss(p);
}

void main()
{
    test();

}