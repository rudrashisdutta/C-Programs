#include<stdio.h>
struct student{
    char *c;
};
int main(){
    struct student *s;
    s->c="hello";
    printf("%s",s->c);
}