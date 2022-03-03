#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_DEGREE 101

#pragma pack(push, 1)
typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} Polynomial;
#pragma pack(pop)

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

Polynomial PolyRead(FILE *file_pointer){
    Polynomial p;
    file_pointer = fopen("file.dat", "rb");
    fread(&p, sizeof(Polynomial), 1, file_pointer);
    fclose(file_pointer);

    return p;
}

void PolyWrite(FILE *file_pointer, Polynomial p){
    file_pointer = fopen("file.dat", "ab");
    fwrite(&p, sizeof(Polynomial), 1, file_pointer);
    fclose(file_pointer);

    return;
}

int main(){
    FILE *file_pointer;

    Polynomial a = {5, {3, 6, 0, 0, 0, 10}};
    Polynomial b = {4, {7, 0, 5, 0, 1}};
    Polynomial c;

    PrintPoly(a);
    PolyWrite(file_pointer, a);
    a = PolyRead(file_pointer);
    PrintPoly(a);
    PrintPoly(b);
    c = PolyAdd1(a, b);
    printf("---------------------------------------------------------------------\n");
    PrintPoly(c);
    
    return 0;
}