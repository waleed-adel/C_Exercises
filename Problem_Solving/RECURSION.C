#include<stdio.h>
#include<conio.h>


int power (int,int);


void main (void)
{
 int x,y,z;
 clrscr();
 printf("please enter a number:");
 scanf("%d",&x);
 printf("please enter a power:");
 scanf("%d",&y);
 z=power(x,y);
 printf("%d ^ %d = %d",x,y,z);
 getch();
}


int power(int n,int p)
{
 if(p==0) return 1;
 else return n*power(n,p-1);
}


