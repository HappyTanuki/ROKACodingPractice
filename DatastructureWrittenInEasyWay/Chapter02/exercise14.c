#include <stdio.h>

double DivideSum(double n){
    if (n < 1){
        return 0;
    }
    return (1 / n + DivideSum(n - 1));
}

int main(){
    printf("%lf, ", DivideSum(2));
    return 0;
}