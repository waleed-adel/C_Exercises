#include<stdio.h>
#include<conio.h>
#define n 3

void main(void)
{
int i, column=n/2 , row=0;
clrscr();
gotoxy(column+1,row+1);
printf("1");
for (i=1;i<=n*n-1;i++)
{
 if (i%3)
  {
	row--;    if (row<0)    {row=n-1;};
	column--; if (column<0) {column=n-1;};
  }
  else
  {
  row++;    if(row>n-1)  {row=0;}
  }
  gotoxy(column+1,row+1);
  printf("%d",i+1);
}
  getch();
}