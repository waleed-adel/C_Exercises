#include<stdio.h>
#include<conio.h>

#define UP    72
#define DOWN  80
#define ESC   27
#define ENTER 13
#define limit  2


void printMenu(int Ypos);
void cursor(int Ypos);

struct employee
 {
   char name[10];
   int ID;
   char address[30];
 };


void main(void)
{
  int i,Xpos=3,Ypos=1,count1=0,count2=0,count3=0;
  char key;
  struct employee arr[limit]={0};
  clrscr();
  do
   {
	clrscr();
	printMenu(Ypos);
	cursor(Ypos);
	gotoxy(Xpos,Ypos);
	key=getch();
	if(key==NULL)
	 {
	  key=getch();
	  switch(key)
	   {
		case DOWN:
		Ypos++;
		if(Ypos==6) Ypos=1;
		gotoxy(Xpos,Ypos);
		break;

		case UP:
		Ypos--;
		if(Ypos==0) Ypos=5;
		gotoxy(Xpos,Ypos);
		break;
	   }
	 }

	else if(key==ENTER)
	 {
	  clrscr();
	  switch(Ypos)
	   {
		 case 1:
		 printf("please enter a name:");
		 if(count1>=2)
		 {printf("\nyou exceeded the limit!!");getch();}
		 else {scanf("%s",arr[count1].name); count1++;}
		 break;

		 case 2:
		 printf("please enter an ID:");
		 if(count2<limit)
		 {scanf("%d",&arr[count2].ID);  count2++;}
		 else
		 {printf("\nyou exceeded the limit!!");getch();}
		 break;

		 case 3:
		 printf("please enter an Address:");
		 if(count3<limit)
		 {scanf("%s",arr[count3].address); count3++;}
		 else
		 {printf("\nyou exceeded the limit!!");getch();}
		 break;

		 case 4:
		 for(i=0;i<limit;i++)
		  {
		   gotoxy(1,i+1);
		   printf("employee[%d] name:%s",i+1,arr[i].name);
		   gotoxy(30,i+1);
		   printf("ID:%d",arr[i].ID);
		   gotoxy(45,i+1);
		   printf("Address:%s",arr[i].address);
		  }
		 getch();
		 key=ESC;
		 break;

		 case 5:
		 key=ESC;
		 break;
	   }
	 }

	else if(key==ESC)  break;

   }while(key!=ESC);
}

void printMenu(int Ypos)
{
 gotoxy(3,1);
 if(Ypos==1)
  {
   textattr(0x70);
   cprintf("Name:\r\n");  //use \r\n to go to new line when using cprintf
   printf("  ID:\n  Address:\n  Display\n  Exit");
   textattr(0x07);
  }
 else if(Ypos==2)
  {
   textattr(0x70);
   printf("Name:\n  ");
   cprintf("ID:\r\n");
   printf("  Address:\n  Display\n  Exit");
   textattr(0x07);
  }
 else if(Ypos==3)
  {
   textattr(0x70);
   printf("Name:\n  ID:\n  ");
   cprintf("Address:\r\n");
   printf("  Display\n  Exit");
   textattr(0x07);
  }
 else if(Ypos==4)
  {
   textattr(0x70);
   printf("Name:\n  ID:\n  Address:\n  ");
   cprintf("Display\r\n");
   printf("  Exit");
   textattr(0x07);
   }
 else if(Ypos==5)
  {
   textattr(0x70);
   printf("Name:\n  ID:\n  Address:\n  Display\n  ");
   cprintf("Exit");
   textattr(0x07);
  }
}

void cursor(int Ypos)  //fn to print cursor on screen
{
 gotoxy(1,Ypos);
 printf(">");
}
