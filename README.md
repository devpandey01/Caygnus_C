# Student Management System in C

This project implements a **Student Management System** in the C programming language. The system allows for basic CRUD (Create, Read, Update, Delete) operations to manage student records. It also demonstrates file handling techniques to store and retrieve data persistently.

## Features

- **Add Student**: Allows users to add new student records with details such as ID, name, age, and grade.
- **View Students**: Displays all student records currently stored in the system.
- **Delete Student**: Deletes a student record by specifying their student ID.
- **File Handling**: Student records are stored in a binary file (`students.dat`) for persistence between program runs.
- **Menu-driven Interface**: The user interacts with the system through a simple, text-based menu.

## Requirements

- **C Compiler**: The program can be compiled using any standard C compiler, such as GCC.
- **Operating System**: Works on Linux, macOS, and Windows (using a compatible C compiler, such as MinGW for Windows).
- **Basic knowledge of C**: Familiarity with basic C concepts such as arrays, structures, and file handling will help in understanding and extending the code.

## Project Structure

The project consists of a single C file (`student_management.c`) that implements the entire functionality. The project is designed to be simple and easy to understand.

- **student_management.c**: The main C source code file that contains the logic for adding, viewing, deleting, and saving student records.
- **students.dat**: A binary file where student records are saved. This file is auto-generated when students are added, and it is used to persist the data across different program executions.

## How to Compile and Run

### Step 1: Clone or Download the Project

You can download or clone the repository to your local machine.

```bash
git clone https://github.com/your-username/student-management-system.git
cd student-management-system
```

### Step 2: Compile the Code

To compile the program, open a terminal/command prompt and navigate to the project directory. Use a C compiler such as GCC to compile the program.

```bash
gcc -o student_management student_management.c
```

This will generate an executable file named `student_management`.

### Step 3: Run the Program

To run the program, use the following command:

```bash
./student_management
```

### Step 4: Interact with the Program

After running the program, you will be presented with a simple menu to choose actions:

```
1. Add Student
2. View Students
3. Delete Student
4. Save and Exit
```

- **Add Student**: Allows the user to add a new student by entering their details (ID, name, age, grade).
- **View Students**: Displays all students' details currently stored in the system.
- **Delete Student**: Prompts the user to enter a student ID and deletes the corresponding record.
- **Save and Exit**: Saves all student records to the `students.dat` file and exits the program.

## How the Program Works

### 1. Data Structure: `Student`

The student records are stored using a structure (`struct`) that contains the following fields:

- `id`: The student’s unique ID.
- `name`: The student’s name.
- `age`: The student’s age.
- `grade`: The student’s grade (float).

```c
struct Student {
    int id;
    char name[50];
    int age;
    float grade;
};
```

### 2. Functions

- **`addStudent()`**: Prompts the user to enter a student’s details and adds them to the system.
- **`viewStudents()`**: Displays all the student records currently stored in the system.
- **`deleteStudent()`**: Deletes a student record by matching the ID entered by the user.
- **`saveToFile()`**: Saves the student records to a binary file (`students.dat`) using `fwrite()`.
- **`loadFromFile()`**: Loads student records from the binary file (`students.dat`) using `fread()` when the program starts.

### 3. File Handling

The program uses **binary file handling** to store student records. The file `students.dat` is created if it does not exist. When students are added, the records are saved to this file. When the program is run again, the records are loaded from the file, ensuring persistence.

- **Saving data**: `fwrite()` is used to write the student records to the binary file.
- **Loading data**: `fread()` is used to read the student records back into the program when it starts.

### 4. Menu-driven Interface

The user interacts with the program through a simple menu that allows them to:
1. Add new students.
2. View all stored students.
3. Delete a student by their ID.
4. Save the records to a file and exit the program.

### 5. Error Handling

The program includes basic error handling for situations such as invalid input or when trying to delete a non-existent student. However, there is room for improvement, especially in input validation.

## Example Usage

Here’s an example of how the program runs:

```
Student Management System
1. Add Student
2. View Students
3. Delete Student
4. Save and Exit
Enter your choice: 1
Enter student ID: 1
Enter name: John
Enter age: 20
Enter grade: 85.5

Student Management System
1. Add Student
2. View Students
3. Delete Student
4. Save and Exit
Enter your choice: 2
ID: 1, Name: John, Age: 20, Grade: 85.50

Student Management System
1. Add Student
2. View Students
3. Delete Student
4. Save and Exit
Enter your choice: 4
Student records saved to file.
Exiting...
```

In this example, a student with ID `1`, name `John`, age `20`, and grade `85.5` is added to the system. After viewing the students, the user saves the data to a file and exits the program.

## Future Improvements

This project can be enhanced further with the following features:

- **Dynamic Memory Allocation**: Currently, a fixed-size array is used to store the students. It can be improved by using dynamic memory allocation (`malloc`, `realloc`) to allow for an unlimited number of student records.
- **Search Functionality**: Implement the ability to search for students by ID, name, or grade.
- **Sorting**: Add sorting options to view students by their ID or grade in ascending/descending order.
- **Update Student**: Implement a feature to update an existing student's details.
- **Advanced Input Validation**: Improve input validation to ensure the user cannot enter invalid data such as non-numeric values for age or grades.
