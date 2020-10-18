#include<stdio.h>
#include<conio.h>

#define size 5

void scanArr(int* ptr);
void seq_search(int* ptr,int x);


void main (void)
{
  int i,arr[size],num;
  int *ptr=arr;
  clrscr();
  printf("Please Fill Array Elements\n");
  scanArr(ptr);
  printf("Please Enter a Number to Search for:");
  scanf("%d",&num);
  seq_search(ptr,num);
  getch();
}



void scanArr(int* ptr)
{
 int i;
 for(i=0;i<size;i++)
  {
   printf("Array[%d]:",i);
   scanf("%d",&ptr[i]);
  }
}

void seq_search(int* ptr,int x)
{
  int i, flag=0;
  for(i=0;i<size;i++)
  {
   if (ptr[i]==x)
   {
	printf("Your Number is in Array[%d]",i);
	flag = 0;
	break;
   }
   else
   flag = 1;
  }
  if(flag == 1)  printf("Your number is not Found!!");
}