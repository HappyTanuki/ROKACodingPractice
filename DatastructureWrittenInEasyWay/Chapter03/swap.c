#include <stdio.h>

void Swap(int *px, int *py)
{
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}

int main() {
    int a = 1, b = 2;

    printf("Swap을 호출하기 전: a = %d, b = %d\n", a, b);
    Swap(&a, &b);
    printf("Swap을 호출한 다음: a = %d, b = %d\n", a, b);
    return 0;
}