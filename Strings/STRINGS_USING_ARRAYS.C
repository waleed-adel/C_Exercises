#include<stdio.h>
#include<conio.h>

#define limit 6

int flag=0;

void strcheck (char str[]);

void main(void)
{
 char f_Name[100],l_Name[100];
 int i;
 char c=0;
 clrscr();
 while (c!=27)
 {
  clrscr();
  do
   {
	printf("please enter your first name:");
	flag=0;
	gets(f_Name);
	strcheck(f_Name);
	if(flag==1)
	 {
	  clrscr();
	  printf("please enter 6 characters only");
	  getch();
	  clrscr();
	  }
   }while(flag==1);

  do
   {
	printf("please enter your last name:");
	flag=0;
	gets(l_Name);
	strcheck(l_Name);
	if(flag==1)
	 {
	  clrscr();
	  printf("please enter 6 characters only");
	  getch();
	  clrscr();
	  }
   }while(flag==1);

 if (flag==0)
  {
   clrscr();
   printf("Your Name is:%s %s\n",f_Name,l_Name);
   getch();
   c=27;
  }
 }
}


void strcheck (char str[])
{
  int i;
  for(i=0;i<limit;i++)
   {
	if(str[i]==NULL)    //terminate when detecting a NULL terminator
	break;
   }
   if(i==limit)       //set flag if the string exceeds limit
   flag=1;
}
