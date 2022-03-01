#include <stdio.h>

void Asterisk(int i){
    if(i > 1){
        Asterisk(i/2);
        Asterisk(i/2);
    }
    printf("*");
}

int main(){
    Asterisk(5);
    return 0;
}