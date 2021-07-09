#include<stdio.h>
struct Empl{
    int id,age;
    float basicSalary,grossSalary;
    char eName[50];
};

void main(){
    int n;
    printf("Enter the number of employees:\t");
    scanf("%d",&n);
    struct Empl emp[n];
    for(int i=0;i<n;i++){
        printf("\nEmployee %d:\n\nID:\t",i+1);
        scanf("%d",&emp[i].id);
        printf("Name:\t");
        scanf("%*c");
        scanf("%[^\n]s",emp[i].eName);
        printf("Age:\t");
        scanf("%d",&emp[i].age);
        printf("Basic Salary:\t");
        scanf("%f",&emp[i].basicSalary);
        float DA=0,HRA=0;
        DA=0.8*emp[i].basicSalary;
        HRA=0.1*emp[i].basicSalary;
        emp[i].grossSalary=DA+HRA+emp[i].basicSalary;
    }
    char a[]="NAME",b[]="ID",c[]="AGE",d[]="BASIC SALARY",e[]="GROSS SALARY";
    printf("|%15s|%50s|%6s|%20s|%20s|\n",b,a,c,d,e);
    for(int i=0;i<n;i++){
        printf("|%15d|%50s|%6d|%20d|%20d|\n",emp[i].id,emp[i].eName,emp[i].age,emp[i].basicSalary,emp[i].grossSalary);
    }
}