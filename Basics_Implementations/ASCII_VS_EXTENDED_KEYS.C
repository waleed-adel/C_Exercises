#include <stdio.h>
#include<conio.h>

#define ESC  27


void main (void)
{
char key;
clrscr();
printf("please enter a key:\n");
key=getch();
while(key!=ESC)
 {
  if(key==NULL)
   {
	 key=getch();
	 printf("ASCII of KEY:%d\n",key);
   }
   else {printf("\nplease enter an extended key!!");}
   key=getch();
 }
}