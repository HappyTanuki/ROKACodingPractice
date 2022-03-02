#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_DEGREE 101

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} Polynomial;

Polynomial PolyAdd1(Polynomial a, Polynomial b){
    Polynomial c;

    int a_pos = 0, b_pos = 0, c_pos = 0;
    int degree_a = a.degree;
    int degree_b = b.degree;
    c.degree = MAX(a.degree, b.degree);

    while (a_pos <= a.degree && b_pos <= b.degree){
        if (degree_a > degree_b){
            c.coef[c_pos++] = a.coef[a_pos++];
            degree_a--;
        }
        else if (degree_a == degree_b){
            c.coef[c_pos++] = a.coef[a_pos++] + b.coef[b_pos++];
            degree_a--, degree_b--;
        }
        else {
            c.coef[c_pos++] = b.coef[b_pos++];
            degree_b--;
        }
    }

    return c;
}

void print_poly(Polynomial p){
    for (int i = p.degree; i > 0; i--){
        printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
    }
    printf("%3.1f \n", p.coef[p.degree]);
}

int main(){
    Polynomial a = {3, {1, 0, 2, 3}};
    Polynomial b = {3, {-1, 0, 4, -1}};
    Polynomial c;

    print_poly(a);
    print_poly(b);
    c = PolyAdd1(a, b);
    printf("---------------------------------------------------------------------\n");
    print_poly(c);
    
    return 0;
}