#include<stdio.h>
#include<stdio.h>

void main (void)
{
 int x,sum=0;
 clrscr();
 do
 {
   printf("please enter a number:\t");
   scanf("%d",&x);
   sum=sum+x;
 }while(sum<=100);
  printf("Sum:%d",sum);
  getch();
}