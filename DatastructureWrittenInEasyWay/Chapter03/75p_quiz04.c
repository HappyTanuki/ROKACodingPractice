#include "75p_quiz03.c"
#include <math.h>

double GetDistance(Point p1, Point p2){
    return sqrt(pow((double)(p1.x - p2.x), (double)2) + pow((double)(p1.y - p2.y), (double)2));
}