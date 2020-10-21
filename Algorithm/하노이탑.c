
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define PLATE_MAX 50

struct {
    int fris[PLATE_MAX];
} pole[3];

int n, d1n = 5, d2n = 0, d3n = 0;

void printTower() {///프린트하는 함수
    int i, j;
    for (i = 0; i <= 2; i++)
    {
        printf("%d: ", i);
        if (pole[i].fris[1] <= 0) printf("x");
        else
        {
            for (j = n; j >= 1; j--)
            {
                if (pole[i].fris[j] > 0)
                {
                    printf("%d ", j);
                }
            }
        }
        printf("\n");
    }
    return;
}

void move(int disc1, int disc2)///웥반 이동 함수
{
    int blank = 0, fir, sec;
    if (disc1 == 0)
    {
        fir = d1n;
        d1n--;
    }
    if (disc1 == 1)
    {
        fir = d1n;
        d1n--;
    }
    else if (disc1 == 2)
    {
        fir = d2n;
        d2n--;
    }
    else if (disc1 == 3)
    {
        fir = d3n;
        d3n--;
    }
    if (disc2 == 1)
    {
        sec = d1n;
        d1n--;
    }
    else if (disc2 == 2)
    {
        sec = d2n;
        d2n--;
    }
    else if (disc2 == 3)
    {
        sec = d3n;
        d3n--;
    }
    blank = pole[disc1].fris[fir - 1];
    pole[disc1].fris[fir - 1] = 0;
    pole[disc2].fris[sec - 1] = blank;
}

int main() {
    int i, j, d1, d2;
    scanf("%d", &n);
    for (i = n; i >= 1; i--)
    {
        pole[0].fris[n - i + 1] = i;
    }
    printTower();
    while (1)
    {
        scanf("%d%d", &d1, &d2);
        if (d1 > n || d2 > n) return 0;
        move(d1, d2);
        printTower();
    }
    return 0;
}
