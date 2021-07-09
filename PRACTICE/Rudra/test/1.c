#include<stdio.h>
void main()
{
    int n,x,y=1,a[4][100],z=1,w=0,t=0;
    printf("Enter the number of elements in a row:  ");
    scanf("%d",&n);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0)
            {
                printf("\n\n1st row:\n\n");
                i1:
                printf("\nRULE:\nYou can only enter 0 and 1.\nYou cannot enter 1 anymore once 0 is already entered.It has to be 0.\n");
                printf("Enter the number: ");
                scanf("%d",&x);
                if(x==0||x==1)
                {
                    if((y==1&&x==1)||(y==0&&x==0)||(y==1&&x==0))
                    a[i][j]=x;
                    else if(y==0&&x==1)
                    {
                        printf("ERROR:wrong input!");
                        goto i1;
                    }
                    y=x;
                }
                else
                {
                    printf("ERROR:wrong input!");
                    goto i1;
                }
            }
            if(i==1)
            {
                printf("\n\n2nd row:\n\n");
            
            
                i2:
                printf("\nRULE:\nYou can only enter 0 and 1.\nYou cannot enter 0 anymore once 1 is already entered.It has to be 1.\n");
                printf("Enter the number: ");
                scanf("%d",&x);
                if(x==0||x==1)
                {
                    if((t==1&&x==1)||(t==0&&x==0)||(t==0&&x==1))
                    a[i][j]=x;
                    else if(t==1&&x==0)
                    {
                        printf("ERROR:wrong input!");
                        goto i2;
                    }
                    t=x;
                }
                else
                {
                    printf("ERROR:wrong input!");
                    goto i2;
                }
        
            }
            if(i==2)
            {
                printf("\n\n3rd row::\n\n");
            
            
                i3:
                printf("\nRULE:\nYou can only enter 0 and 1.\nFirst element should be 0.\n0 should be followed by 1 which will be followed by a 0 throughout the row.\n");
                printf("Enter the number:  ");
                scanf("%d",&x);
                if(x==0||x==1)
                {
                    if((z==1&&x==0)||(z==0&&x==1))
                    a[i][j]=x;
                    else
                    {
                        printf("ERROR:wrong input!");
                        goto i3;
                    }
                }
                else
                {
                    printf("ERROR:wrong input!");
                    goto i3;
                }
                z=x;
            }
        
            if(i==3)
            {
                printf("\n\n4th row::\n\n");
            
            
                i4:
                printf("\nRULE:\nYou can only enter 0 and 1.\nFirst element should be 1.\n1 should be followed by 0 which will be followed by a 1 throughout the row.\n");
                printf("Enter the number:  ");
                scanf("%d",&x);
                if(x==1||x==0)
                {
                    if((w==1&&x==0)||(w==0&&x==1))
                    a[i][j]=x;
                    else
                    {
                        printf("ERROR:wrong input!");
                        goto i4;
                    }
                }
                else
                {
                    printf("ERROR:wrong input!");
                    goto i4;
                }
                w=x;
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<n;j++)
        printf("%d\t",a[i][j]);
        printf("\n");
    }
}