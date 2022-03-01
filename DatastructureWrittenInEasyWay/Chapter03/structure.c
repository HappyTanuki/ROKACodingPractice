#include <stdio.h>

typedef struct student_tag {
    char name[10];
    int age;
    double gpa;
} Student;

int main(){
    Student a = {"kim", 20, 4.3};
    Student b = {"park", 21, 4.2};
    return 0;
}