#include <stdio.h>

double divideSum(double n){
    if (n < 1){
        return 0;
    }
    return (1 / n + divideSum(n - 1));
}

int main(){
    printf("%lf, ", divideSum(2));
    return 0;
}