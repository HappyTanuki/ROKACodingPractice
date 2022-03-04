#include <stdio.h>
#define SIZE 6

void GetIntegers(int list[])
{
    printf("6개의 정수를 입력하시오: ");
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &list[i]);
    }
}

int CalSum(int list[])
{
    int sum = 0;
    for (int i = 0; i < SIZE; ++i)
    {
        sum += *(list + i);
    }
    return sum;
}

int main()
{
    int list[SIZE];
    GetIntegers(list);
    printf("합 = %d \n", CalSum(list));
    return 0;
}