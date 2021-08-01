#include <stdio.h>
struct student
{
    char name[30];
    int roll;
    double mark1, mark2, mark3;
};

void getResult(struct student s)
{
    double totalMarks;
    totalMarks = (s.mark1 + s.mark2 + s.mark3);
    double cgpa = totalMarks / 30;
    printf("______________________________________\nTotal Marks:  %lf\nCGPA:  %lf", totalMarks, cgpa);
}

void main()
{
    struct student s;
    printf("Enter the name of the student:  ");
    scanf("%s", s.name);
    printf("Enter the roll number of the student:  ");
    scanf("%d", &s.roll);
    printf("Enter the mark1:  ");
    scanf("%lf", &s.mark1);
    printf("Enter the mark2:  ");
    scanf("%lf", &s.mark2);
    printf("Enter the mark3:  ");
    scanf("%lf", &s.mark3);
    printf("\n______________________________________\n\nName:  %s\nRoll Number:  %d\n______________________________________\nMark1:  %lf\nMark2:  %lf\nMark3:  %lf\n", s.name, s.roll, s.mark1, s.mark2, s.mark3);
    getResult(s);
}