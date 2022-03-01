#include <stdio.h>

int Recursive(int n){
    printf("%d\n", n);
    if(n < 1) return -1;
    else return ( Recursive(n - 3) + 1);
}

int main(){
    printf("%d\n", Recursive(10));
    return 0;
}