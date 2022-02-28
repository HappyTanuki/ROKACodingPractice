#include <stdio.h>
#include <time.h>
#include "exercise21.c"

int main(){
    
    for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (j >= 3 && j <= 7 && i >= 2 && i <= 8){
                    if ((i == 3 && j <= 6) || j == 4 || ((j == 5 || j == 6) && i <= 5) || (i == 6 && j == 5)){ // 아직 미완
                        write_pixel(i, j, WHITE);
                    }
                }
                else {
                    write_pixel(i, j, YELLOW);
                }
            }
        
    }

    clock_t start = clock(), stop;

    stop = clock();
    printf("\n수행시간:%lf\n", (double)((stop - start) / (double)CLOCKS_PER_SEC));
    return 0;
}