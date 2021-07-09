#include<stdio.h>
int sumS(){
    int sum=0;
    for(int i=1;i<26;i++){
        if(i%2!=0){
            sum+=(i*i);
        }
    }
    return sum;
}
void main(){
    printf("Sum of squares of all the odd numbers form 1 to 25:\t%d",sumS());
}