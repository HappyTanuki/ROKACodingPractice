#include <stdio.h>
#include "75p_quiz04.c"

int main()
{
    int a = 5;
    int *p = &a;
    int **pp = &p;
    int ***ppp = &pp;

    printf("%d, %d, %d, %d\n", a, *p, **pp, ***ppp);
    return 0;
}