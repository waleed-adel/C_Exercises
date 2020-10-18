#include<stdio.h>
#include<conio.h>


#define size   30
#define ENTER  13
#define HOME   71
#define END    79
#define ESC    27
#define LEFT   75
#define RIGHT  77


void scanChar(char* , int*);
void printChar(char* , int*);


void main(void)
{
 char arr[size], key;
 int count=0, Xpos=1, endcount=0, i;
 clrscr();
 gotoxy(Xpos,1);
 do
  {
	key=getch();
	if(key==NULL)
	{
	  key=getch();
	  switch(key)
	  {
		case LEFT:
		Xpos--;
		if(Xpos<1)
		{ Xpos=1;}
		gotoxy(Xpos,1);
		break;

		case RIGHT:
		Xpos++;
		if(Xpos>count+1)   Xpos=count+1;
		gotoxy(Xpos,1);
		break;

		case HOME:
		Xpos=1;
		gotoxy(Xpos,1);
		break;

		case END:
		gotoxy(endcount+1,1);
		count=endcount+1;
		break;
	  }
	}
	else if(key == ESC) break;
	else if(key == ENTER)
	{
	  printf("\n");
	  for(i=0;i<endcount;i++)
	   {
		printf("%c",arr[i]);
	   }
	}
	else
	{
	printf("%c",key);
	arr[Xpos-1]=key;
	Xpos++; count++; endcount++;
	}
  }while(key!=ESC);

 getch();

}