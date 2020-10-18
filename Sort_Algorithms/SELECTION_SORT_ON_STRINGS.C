#include<stdio.h>
#include<conio.h>
#include<string.h>


#define size  4



void main(void)
{
  int i ,j ,k, x, index;
  char arr[size][50],temp[50];
  clrscr();
  printf("Please Enter (N) Strings:\n ");
  for (k=0;k<size;k++)
  {
   gets(arr[k]);
  }
  for(i=0;i<size-1;i++)
  {
   index=i;
   for(j=i+1;j<size;j++)
   {
	x = strcmp(arr[j],arr[index]);
	if (x < 0)
	{
	 strcpy(temp,arr[j]);
	 strcpy(arr[j],arr[index]);
	 strcpy(arr[index],temp);
	}
   }
  }
  printf("\nYour Sorted String:\n");
  for(i=0;i<size;i++)
  {
   printf("%s\n",arr[i]);
  }
  getch();
}


