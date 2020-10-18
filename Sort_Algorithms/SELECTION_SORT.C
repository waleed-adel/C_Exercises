#include<stdio.h>
#include<conio.h>

#define size 5

void swap (int* a,int* b);
void selection_sort(int* arr);
void print_array(int* arr);
void scan_array(int* arr);


void main(void)
{
  int arr[size];
  clrscr();
  printf("Please Fill in the Array Elements\n");
  scan_array(arr);
  selection_sort(arr);
  printf("\nYour Sorted Array\n");
  print_array(arr);
  getch();
}


void selection_sort(int* arr)
{
 int i, j, min;
 for(i=0;i<size;i++)
  {
	min=i;
	for(j=i+1;j<size;j++)
	{
	 if(arr[i]>arr[j] && arr[min]>arr[j])  min=j;
	}
   if(min!=i)  swap(&arr[min],&arr[i]);  //swaps value in min with first element
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