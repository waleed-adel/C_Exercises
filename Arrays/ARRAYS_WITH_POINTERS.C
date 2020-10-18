#include<conio.h>
#include<stdio.h>

#define size   5


void printArray(int* ptrArr);
void scanArray(int* ptrArr);


void main(void)
{
 int arr[size];
 int *ptr = arr;
 clrscr();
 scanArray(ptr);
 printArray(ptr);
 getch();
}


void scanArray(int* ptrArr)
{
 int i;
 printf("Please Enter Array Elements\n");
 for(i=0;i<size;i++)
  {
   printf("Array Element[%d]: ",i);
   scanf("%d",&ptrArr[i]);
  }
}



void printArray(int* ptrArr)
{
  int i;
  printf("\n\n");
  for(i=0;i<size;i++)
   {
	 printf("Array[%d] = %d\n",i,*(ptrArr+i));
   }


}




