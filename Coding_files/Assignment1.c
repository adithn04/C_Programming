#include <stdio.h>
#include <string.h>
struct Student {
    int id;
    char name[50];
    int marks[5];
    float average;
};
void inputStudents(struct Student s[], int n) {
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &s[i].id);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Enter 5 marks: ");
        for(int j = 0; j < 5; j++) {
            scanf("%d", &s[i].marks[j]);
        }
    }
}
void calculateAverage(struct Student *s) {
    int total = 0;
    for(int i = 0; i < 5; i++) {
        total += s->marks[i];
    }
    s->average = total / 5.0;
}
void displayTopper(struct Student s[], int n) {
    int topperIndex = 0;
    for(int i = 1; i < n; i++) {
        if(s[i].average > s[topperIndex].average) {
            topperIndex = i;
        }
    }

    printf("\nTopper Details:\n");
    printf("ID: %d\n", s[topperIndex].id);
    printf("Name: %s\n", s[topperIndex].name);
    printf("Marks: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", s[topperIndex].marks[i]);
    }
    printf("\nAverage: %.2f\n", s[topperIndex].average);
}

int main() {
    int n = 5;
    struct Student students[n];

    inputStudents(students, n);

    for(int i = 0; i < n; i++) {
        calculateAverage(&students[i]);
    }

    displayTopper(students, n);

    return 0;
}
