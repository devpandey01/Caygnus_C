#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    int age;
    float grade;
};

int main() {
    int capacity = 10, count = 0;
    struct Student *students = (struct Student *)malloc(capacity * sizeof(struct Student));

    if (!students) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    students[count].id = 1; 
    count++;

 
    if (count == capacity) {
        capacity *= 2;
        students = (struct Student *)realloc(students, capacity * sizeof(struct Student));
    }

    

    free(students); 
    return 0;
}
