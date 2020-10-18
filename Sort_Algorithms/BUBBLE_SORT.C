#include<stdio.h>
#include<conio.h>

#define size 5

void swap (int* a,int* b);
void bubble_sort(int* arr);
void print_array(int* arr);
void scan_array(int* arr);


void main(void)
{
  int arr[size];
  clrscr();
  printf("Please Fill in the Array Elements\n");
  scan_array(arr);
  bubble_sort(arr);
  printf("\nYour Sorted Array\n");
  print_array(arr);
  getch();
}


void bubble_sort(int* arr)
{
 int i, j;
 for(i=0;i<size-1;i++)
  {
	for(j=0;j<size-1;j++)
	{
	 if(arr[j] > arr[j+1])
	 swap(&arr[j],&arr[j+1]);
	}
  }
}

void swap (int* a,int* b)
{
 *a=*a ^ *b;
 *b=*a ^ *b;
 *a=*a ^ *b;
}

void print_array(int* arr)
{
 int i;
 for(i=0;i<size;i++)
 {
  printf("Array[%d]= %d\n",i,arr[i]);
 }
}

void scan_array(int* arr)
{
 int i;
 for(i=0;i<size;i++)
 {
  printf("Array[%d]:",i);
  scanf("%d",&arr[i]);
 }
}