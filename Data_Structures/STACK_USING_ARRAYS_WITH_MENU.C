#include<stdio.h>
#include<conio.h>
#include<string.h>


#define UP    72
#define DOWN  80
#define ESC   27
#define ENTER 13




typedef struct employee
{
 int ID;
 char name[50];
}emp;



typedef struct stack
{
 int tos,size;   //size represents limit of total elements in stack
 emp* e;        //tos represents stack pointer or number of elements entered in stack
}stack;


int init_stack(stack* s,int size);
int stack_empty (stack* s);
int stack_full (stack* s,int size);
void pop (stack* s);
void push (stack* s,emp* data);
void printMenu(int Ypos);
void cursor(int Ypos);



void main(void)
{
  int i,x,size=0,Xpos=3,Ypos=1;
  char key;
  emp emp_data;
  stack s;
  s.tos=0;
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
		 if(size == 0)
		 {
		  printf("Please Enter Size of Stack: ");
		  scanf("%d",&size);
		  flushall();
		  x = init_stack(&s,size);
		 (x == 0) ? printf("\nNOT ENOUGH MEMORY!!\n") : printf("\nStack Initialized Successfully\n\n");
		 getch();
		 }

		 x = stack_full(&s,size);
		 if(x == 0)
		 {
		  printf("Please Enter Employee Data\nID: ");
		  scanf("%d",&emp_data.ID);
		  flushall();
		  printf("Name: ");
		  gets(emp_data.name);
		  push (&s,&emp_data);
		 }
		 else
		 printf("\nSTACK OVERFLOW!!");
		 getch();
		 break;


		 case 2:
		 x = stack_empty (&s);
		 if(x == 0)
		 {
		  pop(&s);
		  printf("\nData Is Pulled Successfully\n");
		 }
		 else
		 printf("STACK IS EMPTY!!");
		 getch();
		 break;


		 case 3:
		 if(!s.tos)
		 printf("NOTHING TO DISPLAY!!");
		 else
		 {
		  for(i=s.tos-1;i>=0;i--)
		  {
		   printf("%d\tID: %d\t\tName: %s\n",i, s.e[i].ID, s.e[i].name);
		  }
		 }
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




int init_stack(stack* s,int size)
{
  s -> e = (emp*)malloc(size*sizeof(emp));  //dynamically allocate a chunck of memory ==> (stack)
  if (s -> e != NULL)
  {
   s -> size = size;
   s -> tos = 0;
   return 1;
  }
  else
  return 0; //not enough space in memory to allocate in
}



int stack_empty (stack* s)
{
 if(s -> tos == 0)
 return 1;
 else
 return 0;
}




int stack_full (stack* s,int size)
{
  if (s -> tos == size)
  return 1;
  else
  return 0;
}



void push (stack* s,emp* data)
{
 s -> e[s->tos].ID = data -> ID;
 strcpy(s -> e[s->tos].name,data -> name);
 s -> tos ++;
 printf("Data Pushed Successfully");
}



void pop (stack* s)
{
   printf("ID: %d\t\tName: %s\n",s->e[s->tos-1].ID,s->e[s->tos-1].name);
   s -> tos --;
}


void printMenu(int Ypos)
{
 gotoxy(3,1);
 if(Ypos==1)
  {
   textattr(0x70);
   cprintf("Push\r\n");  //use \r\n to go to new line when using cprintf
   printf("  Pop\n  Display\n  Exit");
   textattr(0x07);
  }
 else if(Ypos==2)
  {
   textattr(0x70);
   printf("Push\n  ");
   cprintf("Pop\r\n");
   printf("  Display\n  Exit");
   textattr(0x07);
  }
 else if(Ypos==3)
  {
   textattr(0x70);
   printf("Push\n  Pop\n  ");
   cprintf("Display\r\n");
   printf("  Exit");
   textattr(0x07);
  }
 else if(Ypos==4)
  {
   textattr(0x70);
   printf("Push\n  Pop\n  Display\n  ");
   cprintf("Exit");
   textattr(0x07);
   }
}




void cursor(int Ypos)  //fn to print cursor on screen
{
 gotoxy(1,Ypos);
 printf(">");
}