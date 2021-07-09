#include<stdio.h>
struct date
{
    int d,m,y;
};
void readdata()
{
    printf("Enter the date(1-31):  ");
    scanf("%d",&d.d);
    printf("Enter the month (1-12):  ");
    scanf("%d",&d.m);
    printf("Enter the year:  ");
    scanf("%d",&d.y);
}
void valid()
{
    switch(d.m)
    {
        case 1:
            if(d.d>=1&&d.d<=31)
            printf("JANUARY %d, %d",d.d,d.y);
            else
            printf("ERROR:Invalid Date For The Month!");
            break;
        case 2:
            if(d.d==29)
            {
                if((d.y%400==0)||(d.y%4==0)&&(d.y%100==0))
                printf("FEBRUARY 29, %d",d.y);
                else
                printf("ERROR:Not a Leap Year!");
            }
            else if(d.d>=1&&d.d<=28)
            printf("FEBRUARY %d, %d",d.d,d.y);
            else
            printf("ERROR:Invalid Date For The Month!");
        case 3:
            if(d.d>=1&&d.d<=31)
            printf("MARCH %d, %d",d.d,d.y);
            else
            printf("ERROR:Invalid Date For The Month!");
        case 4:
            if(d.d>=1&&d.d<=30)
            printf("APRIL %d, %d",d.d,d.y);
            else
            printf("ERROR:Invalid Date For The Month!");
        case 5:
            if(d.d>=1&&d.d<=31)
            printf("MAY %d, %d",d.d,d.y);
            else
            printf("ERROR:Invalid Date For The Month!");
        case 6:
            if(d.d>=1&&d.d<=30)
            printf("JUNE %d, %d",d.d,d.y);
            else
            printf("ERROR:Invalid Date For The Month!");
        case 7:
            if(d.d>=1&&d.d<=31)
            printf("JULY %d, %d",d.d,d.y);
            else
            printf("ERROR:Invalid Date For The Month!");
        case 8:
            if(d.d>=1&&d.d<=31)
            printf("AUGUST %d, %d",d.d,d.y);
            else
            printf("ERROR:Invalid Date For The Month!");
        case 9:
            if(d.d>=1&&d.d<=30)
            printf("SEPTEMBER %d, %d",d.d,d.y);
            else
            printf("ERROR:Invalid Date For The Month!");
        case 10:
            if(d.d>=1&&d.d<=31)
            printf("APRIL %d, %d",d.d,d.y);
            else
            printf("ERROR:Invalid Date For The Month!");
    }
}