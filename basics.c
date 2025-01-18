#include <stdio.h>

int main() {
    int choice;
    char name[20];
    int age;
    do {
        printf("1. Add Student\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Student Name: ");
                scanf("%s",&name);
                printf("Student Age: ");
                scanf("%d",&age);
                printf("Adding student...\n");
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 2);
    
    return 0;
}
