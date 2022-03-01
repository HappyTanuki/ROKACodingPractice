#include <stdio.h>

int Fib(int n){
    printf("Fib(%d) is called\n", n);
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    return Fib(n - 1) + Fib(n - 2);
}

int main(){
    Fib(6);
    return 0;
}