#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Student structure
struct Student {
    int id;
    char name[50];
    int age;
    float grade;
};

// Function to add a student
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

// Function to view all students
void viewStudents(struct Student *students, int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Age: %d, Grade: %.2f\n", students[i].id, students[i].name, students[i].age, students[i].grade);
    }
}

// Function to delete a student by ID
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

// Function to save students to a file
void saveToFile(struct Student *students, int count) {
    FILE *file = fopen("students.dat", "wb");
    if (file) {
        fwrite(students, sizeof(struct Student), count, file);
        fclose(file);
        printf("Student records saved to file.\n");
    } else {
        printf("Error saving to file!\n");
    }
}

// Function to load students from a file
void loadFromFile(struct Student *students, int *count) {
    FILE *file = fopen("students.dat", "rb");
    if (file) {
        *count = fread(students, sizeof(struct Student), 10, file);
        fclose(file);
        printf("Student records loaded from file.\n");
    } else {
        printf("Error loading from file!\n");
    }
}

// Main function
int main() {
    struct Student students[10];  // Array to hold up to 10 students
    int count = 0;  // Number of students
    int choice, id;

    // Load existing student records from file
    loadFromFile(students, &count);

    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Delete Student\n");
        printf("4. Save and Exit\n");
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
                saveToFile(students, count);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;  
}
