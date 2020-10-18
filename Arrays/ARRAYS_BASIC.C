#include <stdio.h>
#include<conio.h>

#define n 5

void main (void)
{
 int i, arr[n];
 clrscr();
 printf("please enter 5 elements:");
 for (i=0;i<5;i++)         //scan array elements
 {
  scanf("%d",&arr[i]);
 }
  for(i=0;i<5;i++)                //print array
  {
   printf("Array[%d]:%d\n",i,arr[i]);
  }
 getch();
}
