#include <stdio.h>

int sum(int n){
    if (n < 1){
        return 0;
    }
    return n + sum(n - 1);
}

int main(){
    printf("%d", sum(10));
    return 0;
}