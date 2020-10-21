#include <io.h>
#include <stdio.h>

int main(void)
{
    FILE* fp;
    errno_t err;
    int i = 0;
    int result;

    err = fopen_s(&fp, "file.txt", "a+");
    result = fseek(fp, -4, SEEK_END);
    fscanf_s(fp, "%d", &i);
    printf("%d\n", i);

    result = fseek(fp, 0, SEEK_SET);
    fscanf_s(fp, "%d", &i);
    printf("%d\n", i);
    fscanf_s(fp, "%d", &i);
    printf("%d\n", i);
    system("pause");
    return 0;
}