#include <stdio.h>

struct Student {
    int id;
    char name[50];
    int age;
    float grade;
};

int main() {
    struct Student students[10];
    int count = 0;

    students[count].id = 1;
    printf("Enter name: ");
    scanf("%s", students[count].name);
    printf("Enter age: ");
    scanf("%d", &students[count].age);
    printf("Enter grade: ");
    scanf("%f", &students[count].grade);
    
    count++;
    
    printf("Student Details:\n");
    printf("ID: %d, Name: %s, Age: %d, Grade: %.2f\n", students[0].id, students[0].name, students[0].age, students[0].grade);
    
    return 0;
}
