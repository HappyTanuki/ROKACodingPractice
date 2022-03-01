#define WHITE 0
#define BLACK 1
#define YELLOW 2
#define WIDTH 10
#define HEIGHT 10

int screen[WIDTH][HEIGHT];

char ReadPixel(int x, int y){
    return screen[x][y];
}

void WritePixel(int x, int y, int color){
    screen[x][y] = color;
}

void FloodFill(int x, int y){
    if (ReadPixel(x, y) == WHITE){
        WritePixel(x, y, BLACK);
        FloodFill(x, y - 1);
        FloodFill(x, y + 1);
        FloodFill(x - 1, y);
        FloodFill(x + 1, y);
    }
}

//#include <stdio.h>
//#include <time.h>
//#include "exercise21.c"
//
//int main(){
//    
//    for (int j = 0; j < 10; j++){
//        for (int i = 0; i < 10; i++){
//            if ((i == 2 && j >= 3 && j <= 6) ||
//                ((i == 3 || i == 4) && j >= 4 && j <= 6) ||
//                (i == 5 && j >= 4 && j <= 7) ||
//                (i >= 6 && i <= 8 && j == 4)){
//                WritePixel(i, j, WHITE);
//            }
//            else {
//                WritePixel(i, j, YELLOW);
//            }
//        }
//        
//    }
//    clock_t start = clock(), stop;
//    printf("영역 채우기 전:\n");
//    for (int i = 0; i < 10; i++){
//        for (int j = 0; j < 10; j++){
//            printf("%d\t", ReadPixel(i, j));
//        }
//        printf("\n");
//    }
//    FloodFill(5, 4);
//    printf("영역 채우기 후:\n");
//    for (int i = 0; i < 10; i++){
//        for (int j = 0; j < 10; j++){
//            printf("%d\t", ReadPixel(i, j));
//        }
//        printf("\n");
//    }
//    stop = clock();
//    printf("\n수행시간:%lf\n", (double)((stop - start) / (double)CLOCKS_PER_SEC));
//    return 0;
//}