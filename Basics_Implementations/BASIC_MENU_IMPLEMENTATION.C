#include <stdio.h>
#include<conio.h>

#define column 1
#define row    1
#define ENTER 13
#define ESC   27
#define UP    72
#define DOWN  80

void main (void)
{
 int i, counter=0, flag=0;
 char c, n[20];
 clrscr();
 while (flag==0)
  {
   gotoxy(column,row);
   printf("Name:");
   gotoxy(column,row+1);
   printf("Number:");
   gotoxy(column,row+2);
   printf("Address:");
   gotoxy(column,row+3);
   printf("Exit");
   gotoxy(column,row);
   c = getch();
   while(c!=ESC)
	{
	 if(c == NULL)
	  {
	   c = getch();
	   switch (c)
		{
		 case DOWN : counter++;   //((row+counter) = cursor position)
					 if((counter+row)>4) {counter=0;}
					 gotoxy(column,row+counter);
					 break;

		 case UP : counter--;
				   if((row+counter)<1) {counter=3;}
				   gotoxy(column,row+counter);
				   break;
		 }
	  }
	 else if (c == ENTER)
			  {
				if((row+counter)==1)
					{
					 clrscr();
					 printf("please enter your name:");
					 gets(n);
					 clrscr();
					 break;
					}
				if((row+counter)==2)
					{
					 clrscr();
					 printf("please enter your number:");
					 gets(n);
					 clrscr();
					 break;
					}
				if((row+counter)==3)
					{
					 clrscr();
					 printf("please enter your Address:");
					 gets(n);
					 clrscr();
					 break;
					}
				if((row+counter)==4)
					{
					 clrscr();
					 flag=1;
					 break;
					}
			 }
   c = getch();
	  }
   }
}