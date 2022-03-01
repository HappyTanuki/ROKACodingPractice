#include <stdio.h>

int Sum(int n){
    if (n < 1){
        return 0;
    }
    return n + Sum(n - 1);
}

int main(){
    printf("%d", Sum(10));
    return 0;
}