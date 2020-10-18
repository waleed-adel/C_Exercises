#include <stdio.h>
#include <conio.h>

#define ENTER  13

char* getstr (char str[]);

void main (void)
{
char name[100],c,*string;
clrscr();
printf("please enter your name:");
string=getstr(name);
printf("\nYour name is:%s",string);
getch();
}

char* getstr (char str[])
{
 int i=-1;
 char c;
 do
   {
	  i++;
	  c=getch();
	  str[i]=c;
	  printf("%c",c);
	}while(str[i]!=ENTER);
	str[i]=NULL;
	return str;
}



