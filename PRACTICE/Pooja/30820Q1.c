#include<stdio.h>
struct student
{
    char name[50];
    int roll,age;
    double cgpa;
}stud[5];
void main(){
    for(int i=0;i<2;i++){
        printf("\n\nStudent %d:\nName:\t",i+1);
        scanf("%[^\n]s",stud[i].name);
        printf("Roll:\t");
        scanf("%d",&stud[i].roll);
        printf("Age:\t");
        scanf("%d",&stud[i].age);
        printf("CGPA:\t");
        scanf("%lf",&stud[i].cgpa);
        scanf("%*c");
    }
    for(int i=0;i<5;i++){
        printf("\n\nName:\t%s\nRoll:\t%d\nAge:\t%d\nCGPA:\t%lf",stud[i].name,stud[i].roll,stud[i].age,stud[i].cgpa);
    }
}