#include<stdio.h>
#include<conio.h>

#define n 5


void main(void)
 {
  int max, min, i, arr[5];
  clrscr();
  printf("please enter n numbers:");
  for(i=0;i<n;i++)
   {
	scanf("%d",&arr[i]);
   }
   min=arr[0];
   max=arr[0];
  for(i=1;i<n;i++)
   {
	if(arr[i]<min) {min=arr[i];}
	if(arr[i]>max) {max=arr[i];}
   }
   printf("MAX:%d\nMIN:%d",max,min);
   getch();
 }