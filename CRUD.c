#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    float grade;
};

void addStudent(struct Student *students, int *count) {
    printf("Enter student ID: ");
    scanf("%d", &students[*count].id);
    printf("Enter name: ");
    scanf("%s", students[*count].name);
    printf("Enter age: ");
    scanf("%d", &students[*count].age);
    printf("Enter grade: ");
    scanf("%f", &students[*count].grade);
    (*count)++;
}

void viewStudents(struct Student *students, int count) {
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Age: %d, Grade: %.2f\n", students[i].id, students[i].name, students[i].age, students[i].grade);
    }
}

void deleteStudent(struct Student *students, int *count, int id) {
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

int main() {
    struct Student students[10];
    int count = 0;
    int choice, id;

    do {
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                viewStudents(students, count);
                break;
            case 3:
                printf("Enter student ID to delete: ");
                scanf("%d", &id);
                deleteStudent(students, &count, id);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
