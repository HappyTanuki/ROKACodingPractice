#include <stdio.h>

void Unknown(){
    int ch;
    if ((ch = getchar()) != '\n'){
        Unknown();
    }
    putchar(ch);
}

int main(){
    Unknown();
    return 0;
}