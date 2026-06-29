#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
    char firstname[20];
    char lastname[20];
    int rollno;
    char dob[20];
    float percent;
    char cour[20];
};

struct student s1[100];
int c = 0;

// Add Student
void add_student() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = c; i < c + n; i++) {
        printf("Enter first name: ");
        scanf("%s", s1[i].firstname);

        printf("Enter last name: ");
        scanf("%s", s1[i].lastname);

        printf("Enter roll number: ");
        scanf("%d", &s1[i].rollno);

        printf("Enter DOB: ");
        scanf("%s", s1[i].dob);

        printf("Enter course: ");
        scanf("%s", s1[i].cour);

        printf("Enter percentage: ");
        scanf("%f", &s1[i].percent);
    }
    c += n;
}

// Search by Roll Number
void check_roll() {
    int roll, found = 0;
    printf("Enter roll number: ");
    scanf("%d", &roll);

    for (int i = 0; i < c; i++) {
        if (roll == s1[i].rollno) {
            printf("\nStudent Found:\n");
            printf("Name: %s %s\n", s1[i].firstname, s1[i].lastname);
            printf("DOB: %s\n", s1[i].dob);
            printf("Course: %s\n", s1[i].cour);
            printf("Percentage: %.2f\n", s1[i].percent);
            found = 1;
        }
    }
    if (!found) printf("Student not found.\n");
}

// Search by First Name
void check_firstname() {
    char fn[20];
    int found = 0;

    printf("Enter first name: ");
    scanf("%s", fn);

    for (int i = 0; i < c; i++) {
        if (strcmp(fn, s1[i].firstname) == 0) {
            printf("\nName: %s %s\n", s1[i].firstname, s1[i].lastname);
            printf("DOB: %s\n", s1[i].dob);
            printf("Course: %s\n", s1[i].cour);
            printf("Percentage: %.2f\n", s1[i].percent);
            found = 1;
        }
    }
    if (!found) printf("No student found.\n");
}

// Search by Course
void check_course() {
    char course[20];
    int found = 0;

    printf("Enter course: ");
    scanf("%s", course);

    for (int i = 0; i < c; i++) {
        if (strcmp(course, s1[i].cour) == 0) {
            printf("\nName: %s %s\n", s1[i].firstname, s1[i].lastname);
            printf("Percentage: %.2f\n", s1[i].percent);
            printf("Course: %s\n", s1[i].cour);
            found = 1;
        }
    }
    if (!found) printf("No students found.\n");
}

// Count Students
void student_count() {
    printf("Total students: %d\n", c);
}

// Update Student
void student_update() {
    int roll;
    printf("Enter roll number: ");
    scanf("%d", &roll);

    for (int i = 0; i < c; i++) {
        if (s1[i].rollno == roll) {
            int option;
            printf("1.First Name\n2.Last Name\n3.DOB\n4.Percentage\n5.Course\n");
            printf("Enter choice: ");
            scanf("%d", &option);

            switch (option) {
                case 1:
                    printf("New first name: ");
                    scanf("%s", s1[i].firstname);
                    break;
                case 2:
                    printf("New last name: ");
                    scanf("%s", s1[i].lastname);
                    break;
                case 3:
                    printf("New DOB: ");
                    scanf("%s", s1[i].dob);
                    break;
                case 4:
                    printf("New percentage: ");
                    scanf("%f", &s1[i].percent);
                    break;
                case 5:
                    printf("New course: ");
                    scanf("%s", s1[i].cour);
                    break;
                default:
                    printf("Invalid choice\n");
            }
            printf("Updated successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

// Delete Student
void student_delete() {
    int roll;
    printf("Enter roll number: ");
    scanf("%d", &roll);

    for (int i = 0; i < c; i++) {
        if (s1[i].rollno == roll) {
            for (int j = i; j < c - 1; j++) {
                s1[j] = s1[j + 1];
            }
            c--;
            printf("Deleted successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

// Main Function
int main() {
    int choice;

    while (1) {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Search by Roll\n");
        printf("3. Search by Name\n");
        printf("4. Search by Course\n");
        printf("5. Count Students\n");
        printf("6. Delete Student\n");
        printf("7. Update Student\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_student(); break;
            case 2: check_roll(); break;
            case 3: check_firstname(); break;
            case 4: check_course(); break;
            case 5: student_count(); break;
            case 6: student_delete(); break;
            case 7: student_update(); break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
