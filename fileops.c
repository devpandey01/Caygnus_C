#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    int age;
    float grade;
};

void saveToFile(struct Student *students, int count) {
    FILE *file = fopen("students.dat", "wb");
    if (file) {
        fwrite(students, sizeof(struct Student), count, file);
        fclose(file);
    } else {
        printf("Error saving to file!\n");
    }
}

void loadFromFile(struct Student *students, int *count) {
    FILE *file = fopen("students.dat", "rb");
    if (file) {
        *count = fread(students, sizeof(struct Student), 10, file);
        fclose(file);
    } else {
        printf("Error loading from file!\n");
    }
}

int main() {
    struct Student students[10];
    int count = 0;
    
    loadFromFile(students, &count); 
    return 0;
}
