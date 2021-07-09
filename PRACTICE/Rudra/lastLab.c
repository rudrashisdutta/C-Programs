#include<stdio.h>
int insert_front(int*dq,int*f,int*r,int n,int x)
{
	if(((*f==0)&&(*r==n-1))||(*f==(*r+1)))
	{
		printf("queue is full\n");
		return (0);
	}
    else if(*f==-1)
	{
		*f=*r=0;
	}
	else if(*f==0)
	{
		*f=n-1;
	}
	else
	{
		*f=*f-1;
	}
	dq[*f]=x;
}
int insert_rear(int*dq,int*f,int*r,int n,int x)
{
	if(((*f==0)&&(*r==n-1))||(*f==(*r+1)))
	{
		printf("queue is full\n");
		return (0);
	}
    else if(*f==-1)
	{
		*f=*r=0;
	}
	else if(*r==n-1)
	{
		*r=0;
	}
	else
	{
		*r=*r+1;
	}
	dq[*r]=x;
}
int delete_front(int*dq,int*f,int*r,int n)
{   int y;
	if(*f==-1)
	{
		printf("queue is empty\n");
		return 0;
	}
	y=dq[*f];
	if(*f==*r)
	{
		*f=*r=-1;
	}
	else if(*f==n-1)
	{
		*f=0;
	}
	else
	{
	    *f=*f+1;	
	}
	return y;
}
int delete_rear(int*dq,int*f,int*r,int n)
{   int y;
	if(*f==-1)
	{
		printf("queue is empty\n");
		return 0;
	}
	y=dq[*f];
	if(*f==*r)
	{
		*f=*r=-1;
	}
	else if(*r==0)
	{
		*r=n-1;
	}
	else
	{
	    *r=*r+1;	
	}
	return y;
}
int main()
{
	int n;
	printf("enter the no. of elements in Dequeue\n");
	scanf("%d",&n);
	int deque[n];
	int f=-1,r=-1,x,y,q,j;
	printf("enter no of operations \n");
	int k;
	scanf("%d",&k);

    for( q=0;q<k;k++)   
    {
	  printf("enter 1 to insert at front\n");
	  printf("enter 2 to insert at rear\n");
	  printf("enter 3 to delete at front\n");
	  printf("enter 4 to delete at rear\n");
	  printf("enter 5 to view\n");
	  int l;
	  scanf("%d",&l);
	  switch (l)
	  {
	   case 1:
	    {
				printf("enter the element to be inserted in front\n");
      	scanf("%d",&x);
        insert_rear(deque,&f,&r,n,x); break;
       }
       case 2:
       	{
		   
       	printf("enter the element to be inserted in rear\n");
      	scanf("%d",&x);
        insert_rear(deque,&f,&r,n,x); break;
       }
       case 3:
       	{
		   
        y=delete_front(deque,&f,&r,n);
         if(y!=0)
          printf("element deleted from front is %d\n",y); break;
      }
       case 4: 
	   {
		 
        y=delete_rear(deque,&f,&r,n);
         if(y!=0)
          printf("element deleted from front is %d\n",y); break;
      }
        case 5:
        	{
			
        for(j=0;j<n;j++)
         printf("%d ",deque[j]);
     }
    }
        
        
     
}
	
}