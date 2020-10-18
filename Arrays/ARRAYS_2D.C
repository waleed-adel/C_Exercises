#include <stdio.h>
#include<conio.h>

#define row    3
#define column 3

void row_sum (int arr[row][column]);
void printArr(int arr1[row][column]);

void main (void)
{
 int i, j, arr[row][column];
 clrscr();
 printf("please enter array elements\n");
 for(i=0;i<row;i++)
  {
	for(j=0;j<column;j++)
	 {
	   printf("arr[%d][%d]=",i,j);
	   scanf("%d",&arr[i][j]);
	 }
  }
 clrscr();
 printArr(arr);
 row_sum(arr);
 getch();
}


void printArr(int arr1[row][column])
{
 int i, j, Xpos=3, Ypos=3;  //initial starting position for cursor
 gotoxy(Xpos,Ypos);
 for(i=0;i<row;i++)
  {
	for(j=0;j<column;j++)
	{
	  printf("%d",arr1[i][j]);
	  gotoxy(Xpos+=5,Ypos);
	}
	Xpos=3; Ypos+=2;
	gotoxy(Xpos,Ypos);     //return to first column and down to next row
  }
}

void row_sum (int arr[row][column])
{
  int i, j, sum=0, Xpos=3, Ypos=3;
  gotoxy(Xpos+20,Ypos-2);
  printf("sum");
  for(i=0;i<row;i++)
   {
	 for(j=0;j<column;j++)
	  {
		sum+=arr[i][j];
	  }
	gotoxy(Xpos+20,Ypos+=(2*i));
	printf("%d",sum);
	sum=0;
	Ypos=3;  //return initial value of row
   }
 }