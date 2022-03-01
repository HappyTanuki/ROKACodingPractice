#include <stdio.h>

int Recursive(int n){
    printf("%d\n", n);
    if(n < 1) return 2;
    else return (2 * Recursive(n - 1) + 1);
}

int main(){
    printf("%d\n", Recursive(5));
    return 0;
}