#include <stdio.h>

#define MAX_STUDENTS 100

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent(struct Student s[], int *count);
void displayStudents(struct Student s[], int count);
void findTopper(struct Student s[], int count);

int main() {
    struct Student s[MAX_STUDENTS];
    int count = 0, choice;

    while (1) {
        printf("\n===== Student Marks Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Find Topper\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(s, &count); break;
            case 2: displayStudents(s, count); break;
            case 3: findTopper(s, count); break;
            case 4: printf("Exiting program...\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}

void addStudent(struct Student s[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student list is full!\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &s[*count].roll);
    printf("Enter Name: ");
    scanf("%s", s[*count].name);
    printf("Enter Marks: ");
    scanf("%f", &s[*count].marks);

    (*count)++;
    printf("Student added successfully!\n");
}

void displayStudents(struct Student s[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    for (int i = 0; i < count; i++)
        printf("%-10d %-20s %-10.2f\n", s[i].roll, s[i].name, s[i].marks);
}

void findTopper(struct Student s[], int count) {
    if (count == 0) {
        printf("No students to find topper.\n");
        return;
    }

    int topIndex = 0;
    for (int i = 1; i < count; i++)
        if (s[i].marks > s[topIndex].marks)
            topIndex = i;

    printf("\nTopper: %s (Roll No: %d) with %.2f marks\n",
           s[topIndex].name, s[topIndex].roll, s[topIndex].marks);
}