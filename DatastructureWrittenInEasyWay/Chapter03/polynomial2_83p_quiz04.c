#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

#pragma pack(push, 1)
typedef struct {
    float coef;
    int expon;
} Polynomial;
#pragma pack(pop)

Polynomial terms[MAX_TERMS] = {{8, 3}, {7, 1}, {1, 0}, {10, 3}, {3, 2}, {1, 0}};

int avail = 6;

char Compare(int a, int b){
    if (a > b){
        return '>';
    }
    else if (a == b){
        return '=';
    }
    else {
        return '<';
    }
}

void Attach(float coef, int expon){
    if (avail > MAX_TERMS) {
        fprintf(stderr, "항의 개수가 너무 많음\n");
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail].expon = expon;
    avail++;
}

void PolyAdd2(int a_s, int a_e, int b_s, int b_e, int *c_s, int *c_e){
    float tempcoef;

    *c_s = avail;
    while (a_s <= a_e && b_s <= b_e){
        switch(Compare(terms[a_s].expon, terms[b_s].expon)){
        case '>':
            Attach(terms[a_s].coef, terms[a_s].expon);
            a_s++;
            break;
        case '=':
            tempcoef = terms[a_s].coef + terms[b_s].coef;
            if (tempcoef){
                Attach(tempcoef, terms[a_s].expon);
                a_s++, b_s++;
                break;
            }
        case '<':
            Attach(terms[b_s].coef, terms[b_s].expon);
            b_s++;
            break;
        }
    }

    for (; a_s <= a_e; a_s++){
        Attach(terms[a_s].coef, terms[a_s].expon);
    }
    for (; b_s <= b_e; b_s++){
        Attach(terms[b_s].coef, terms[b_s].expon);
    }
    *c_e = avail - 1;
}

void PrintPoly(int s, int e){
    for (int i = s; i < e; i++){
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

void PolyRead(FILE *file_pointer, int *a_s, int *a_e, int *b_s, int *b_e, int *c_s, int *c_e){
    file_pointer = fopen("file.dat", "rb");
    fread(   a_s,        sizeof(int),         1, file_pointer);
    fread(   a_e,        sizeof(int),         1, file_pointer);
    fread(   b_s,        sizeof(int),         1, file_pointer);
    fread(   b_e,        sizeof(int),         1, file_pointer);
    fread(   c_s,        sizeof(int),         1, file_pointer);
    fread(   c_e,        sizeof(int),         1, file_pointer);
    fread( terms, sizeof(Polynomial), MAX_TERMS, file_pointer);
    fread(&avail,        sizeof(int),         1, file_pointer);
    fclose(file_pointer);
    return;
}

void PolyWrite(FILE *file_pointer, int a_s, int a_e, int b_s, int b_e, int c_s, int c_e){
    file_pointer = fopen("file.dat", "ab");
    fwrite(  &a_s,        sizeof(int),         1, file_pointer);
    fwrite(  &a_e,        sizeof(int),         1, file_pointer);
    fwrite(  &b_s,        sizeof(int),         1, file_pointer);
    fwrite(  &b_e,        sizeof(int),         1, file_pointer);
    fwrite(  &c_s,        sizeof(int),         1, file_pointer);
    fwrite(  &c_e,        sizeof(int),         1, file_pointer);
    fwrite( terms, sizeof(Polynomial), MAX_TERMS, file_pointer);
    fwrite(&avail,        sizeof(int),         1, file_pointer);
    fclose(file_pointer);
    return;
}

int main(){
    FILE *file_pointer;
    int a_s = 0, a_e = 2, b_s = 3, b_e = 5, c_s, c_e;
    PolyAdd2(a_s, a_e, b_s, b_e, &c_s, &c_e);

    PrintPoly(a_s, a_e);
    PrintPoly(b_s, b_e);
    PolyWrite(file_pointer, a_s, a_e, b_s, b_e, c_s, c_e);
    PolyRead(file_pointer, &a_s, &a_e, &b_s, &b_e, &c_s, &c_e);
    printf("---------------------------------------------------------------------\n");
    PrintPoly(a_s, a_e);
    PrintPoly(b_s, b_e);
    printf("---------------------------------------------------------------------\n");
    PrintPoly(c_s, c_e);
    
    return 0;
}