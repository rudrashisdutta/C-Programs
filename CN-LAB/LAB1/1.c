#include<stdio.h>
struct student
{
    char name[30];
    int roll;
    double mark1,mark2;
};

void swapMarks(double *mark1,double *mark2){
    double temp;
    temp = *mark1;
    *mark1 = *mark2;
    *mark2 = temp;

}

void main(){
    struct student s;
    printf("Enter the name of the student:  ");
    scanf("%s",s.name);
    printf("Enter the roll number of the student:  ");
    scanf("%d",&s.roll);
    printf("Enter the mark1:  ");
    scanf("%lf",&s.mark1);
    printf("Enter the mark2:  ");
    scanf("%lf",&s.mark2);
    swapMarks(&s.mark1,&s.mark2);
    printf("Name:  %s\nRoll Number:  %d\nMark1:  %lf\nMark2:  %lf\n",s.name,s.roll,s.mark1,s.mark2);
}