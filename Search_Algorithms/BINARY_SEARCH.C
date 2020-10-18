#include<stdio.h>
#include<conio.h>

#define size  5


void scanArray(int* ptr);
int bin_search(int* ptr,int);


void main (void)
{
  int arr[size],num, hi, lo, mid, x;
  int* ptr=arr;
  clrscr();
  printf("Please Fill Array Elements\n");
  scanArray(ptr);
  printf("Please Enter a Number to search for:");
  scanf("%d",&num);
  x = bin_search(ptr,num);
  if(x == -1)
  printf("Your Number is not Found!!");
  else
  printf("Your Number is in Array[%d]",x);
  getch();
}


void scanArray(int* ptr)
{
 int i;
 for(i=0;i<size;i++)
 {
  printf("Array[%d]:",i);
  scanf("%d",&ptr[i]);
  if(i >= 1)
  {
   while(ptr[i] < ptr[i-1])
   {
	printf("\nPlease a number greater than the previous one!!");
	printf("\nArray[%d]:",i);
	scanf("%d",&ptr[i]);
   }
  }
 }
}



int bin_search(int* ptr,int x)
{
 int i, mid, hi=size-1, lo=0;
 while(hi>=lo)
   {
	 mid = (hi+lo)/2;
	 if(ptr[mid] == x)
	 return mid;
	 else if(ptr[mid] > x)
	 hi = mid-1;
	 else
	 lo = mid+1;
   }
  return -1;
}