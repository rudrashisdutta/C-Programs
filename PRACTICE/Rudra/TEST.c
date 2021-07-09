#include<stdio.h>
int func(int n){
    if(n>0){
        printf("%d",n);
        func(n-1);
    }
}
void main(){
    int r=3;
    func(r);
}