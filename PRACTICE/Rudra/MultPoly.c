#include<stdio.h>
#include<stdlib.h>
struct Poly{
    int *coeff;
    int expo;
};
struct Poly enterPoly(){
    struct Poly x;
    printf("Enter the maximum power of x in the polynomial:\t");
    scanf("%d",&x.expo);
    x.coeff=(int*)calloc(x.expo+1,sizeof(int));
    for(int i=0;i<=x.expo;i++){
        printf("Enter the coefficient of x to power %d:\t",i);
        scanf("%d",(x.coeff+i));
    }
    return x;
}
void showPoly(struct Poly x){
    for(int i=x.expo;i>=0;i--){
        if(i==0){
            printf("%d",*(x.coeff));
        }
        else{
            printf("%d*(x to power %d) + ",*(x.coeff+i),i);
        }
    }
}
struct Poly multiply(struct Poly x,struct Poly y){
    struct Poly z;
    z.expo=x.expo+y.expo;
    z.coeff=(int*)calloc(z.expo+1,sizeof(int));
    for(int i=0;i<=x.expo;i++){
        for(int j=0;j<=y.expo;j++){
            *(z.coeff+(i+j))+=(*(x.coeff+i)**(y.coeff+j));
        }
    }
    return z;
}
void main(){
    struct Poly p1,p2,m;
    printf("Polynomial 1:\n");
    p1=enterPoly();
    printf("\n\nPolynomial 2:\n");
    p2=enterPoly();
    printf("\n\nPolynomial 1:\n");
    showPoly(p1);
    printf("\n\nPolynomial 2:\n");
    showPoly(p2);
    m=multiply(p1,p2);
    printf("\n\nPolynomial 1  *  Polynomial 2:\n\n");
    showPoly(m);
}