#include<stdio.h>
#include<conio.h>

#define UP    72
#define DOWN  80
#define ESC   27
#define ENTER 13
#define limit  2


void NewEmployee (int count);
void DisplayEmployee(int count);
int  search (int ID);
void printMenu(int Ypos);
void cursor(int Ypos);

int flag1=0;
int flag2=0;
struct employee
 {
   char name[10];
   int ID;
   char address[30];
 };
 struct employee arr[limit];


void main(void)
{
  int i,Xpos=3,Ypos=1,count=0,searchcount=0,ID,index;
  char key;
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
		if(Ypos==5) Ypos=1;
		gotoxy(Xpos,Ypos);
		break;

		case UP:
		Ypos--;
		if(Ypos==0) Ypos=4;
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
		 if(count<limit)
		 {NewEmployee(count); count++;}
		 else
		 {
		  printf("You have exceeded number of enteries!!");
		  getch();
		 }
		 break;

		 case 2:
		 clrscr();
		 flag1=0;
		 printf("please enter an ID:");
		 scanf("%d",&ID);
		 index=search(ID);
		 if(flag1==1)
		 {
		  clrscr();
		  gotoxy(1,1);
		  printf("Employee[%d]",index+1);
		  gotoxy(15,1);
		  printf("Name:%s",arr[index].name);
		  gotoxy(35,1);
		  printf("ID:%d",arr[index].ID);
		  gotoxy(50,1);
		  printf("Address:%s",arr[index].address);
		 }
		 else if(searchcount<2)
		 {
		  clrscr();
		  printf("ID not found");
		  searchcount++;
		 }
		 else
		 {printf("You exceeded number of trials!!"); key=ESC;}
		 getch();
		 break;

		 case 3:
		 DisplayEmployee(count);
		 getch();
		 break;

		 case 4:
		 key=ESC;
		 break;
	   }
	 }

	else if(key==ESC)  break;

   }while(key!=ESC);
}


void NewEmployee (int count)
{
  int id,i;
  flushall();
  printf("Please Enter Name:");
  gets(arr[count].name);
  printf("please Enter ID:");
  do
  {
   flag2=0;
   scanf("%d",&id);
   for(i=0;i<count;i++)
   {
	if(arr[i].ID==id)
	 {
	  printf("this ID is Taken!!\nplease enter another one:");
	  flag2=1;
	  break;
	 }
   }
  }while(flag2==1);
  arr[count].ID=id;
  printf("Please Enter Address:");
  flushall();
  gets(arr[count].address);
}

void DisplayEmployee(int count)
{
 int i;
 for(i=0;i<count&&i<limit;i++)
 {
  gotoxy(1,1+i);
  printf("Employee[%d]",i+1);
  gotoxy(15,i+1);
  printf("Name:%s",arr[i].name);
  gotoxy(35,i+1);
  printf("ID:%d",arr[i].ID);
  gotoxy(50,i+1);
  printf("Address:%s",arr[i].address);
 }
}

int search (int ID)
{
 int i,index;
 for(i=0;i<limit;i++)
 {
  if(arr[i].ID==ID)
  {
  flag1=1;
  index=i;
  }
 }
 return index;
}



void printMenu(int Ypos)
{
 gotoxy(3,1);
 if(Ypos==1)
  {
   textattr(0x70);
   cprintf("New Employee:\r\n");  //use \r\n to go to new line when using cprintf
   printf("  Scan ID:\n  Display\n  Exit");
   textattr(0x07);
  }
 else if(Ypos==2)
  {
   textattr(0x70);
   printf("New Employee:\n  ");
   cprintf("Scan ID:\r\n");
   printf("  Display\n  Exit");
   textattr(0x07);
  }
 else if(Ypos==3)
  {
   textattr(0x70);
   printf("New Employee:\n  Scan ID:\n  ");
   cprintf("Display\r\n");
   printf("  Exit");
   textattr(0x07);
  }
 else if(Ypos==4)
  {
	textattr(0x70);
   printf("New Employee:\n  Scan ID:\n  Display\n  ");
   cprintf("Exit");
   textattr(0x07);
  }
}

void cursor(int Ypos)  //fn to print cursor on screen
{
 gotoxy(1,Ypos);
 printf(">");
}
