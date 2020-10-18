#include<stdio.h>
#include<conio.h>


void swap (int* , int*);


void main(void)
{
  int x=5, y=10;
  clrscr();
  printf("X = %d \t Y = %d\n\n",x,y);
  swap (&x,&y);
  printf("After swapping\nX = %d \t Y = %d",x,y);
  getch();
}


void swap (int* x, int*y)
{
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;
}





