#include<stdio.h>
#include<conio.h>
#include<string.h>


#define UP    72
#define DOWN  80
#define ESC   27
#define ENTER 13
#define limit  4



typedef struct employee
{
 int ID;
 char name[50];
}emp;



typedef struct queue
{
 int in,size;   //size represents limit of total elements in queue
 emp* e;        //in represents next element that's ready to be out
}queue;


int init_queue(queue* q,int size);
int queue_empty (queue* q);
int queue_full (queue* q);
void out_queue (queue* q);
void in_queue (queue* q,emp* data);
void printMenu(int Ypos);
void cursor(int Ypos);



void main(void)
{
  int i,x,size=0,Xpos=3,Ypos=1;
  char key;
  emp emp_data;
  queue q;
  q.in=0;
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
		  printf("Please Enter Size of Queue: ");
		  scanf("%d",&size);
		  flushall();
		  x = init_queue(&q,size);
		 (x == 0) ? printf("\nNOT ENOUGH MEMORY!!\n") : printf("\nQueue Initialized Successfully\n\n");
		 getch();
		 }

		 x = queue_full(&q);
		 if(x == 0)
		 {
		  printf("Please Enter Employee Data\nID: ");
		  scanf("%d",&emp_data.ID);
		  flushall();
		  printf("Name: ");
		  gets(emp_data.name);
		  in_queue (&q,&emp_data);
		 }
		 else
		 printf("\nQueue IS FULL!!");
		 getch();
		 break;


		 case 2:
		 x = queue_empty (&q);
		 if(x == 0)
		 {
		  out_queue(&q);
		  printf("\nData Is Outed Successfully\n");
		 }
		 else
		 printf("QUEUE IS EMPTY!!");
		 getch();
		 break;


		 case 3:
		 if(!q.in)
		 printf("NOTHING TO DISPLAY!!");
		 else
		 {
		  for(i=q.in-1;i>=0;i--)
		  {
		   printf("%d\tID: %d\t\tName: %s\n",i, q.e[i].ID, q.e[i].name);
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




int init_queue(queue* q,int size)
{
  q -> e = (emp*)malloc(size*sizeof(emp));  //dynamically allocate a chunck of memory ==> (queue)
  if (q -> e != NULL)
  {
   q -> size = size;
   q -> in = 0;
   return 1;
  }
  else
  return 0; //not enough space in memory to allocate in
}



int queue_empty (queue* q)
{
 if(q -> in == 0)
 return 1;        //queue is empty
 else
 return 0;        //queue is not empty
}




int queue_full (queue* q)
{
  if (q -> in == q -> size)
  return 1;
  else
  return 0;
}



void in_queue (queue* q,emp* data)
{
 q -> e[q->in].ID = data -> ID;
 strcpy(q -> e[q->in].name,data -> name);
 q -> in ++;
 printf("Data Entered Successfully");
}



void out_queue (queue* q)
{
   int i;
   printf("ID: %d\t\tName: %s\n",q->e[0].ID,q->e[0].name);
   for (i=0;i < (q->in);i++)
   {
	q -> e[i].ID = q -> e[i+1].ID;
	strcpy(q -> e[i].name , q -> e[i+1].name);
   }
 q -> in --;
}



void printMenu(int Ypos)
{
 gotoxy(3,1);
 if(Ypos==1)
  {
   textattr(0x70);
   cprintf("In_Queue\r\n");  //use \r\n to go to new line when using cprintf
   printf("  Out_Queue\n  Display\n  Exit");
   textattr(0x07);
  }
 else if(Ypos==2)
  {
   textattr(0x70);
   printf("In_Queue\n  ");
   cprintf("Out_Queue\r\n");
   printf("  Display\n  Exit");
   textattr(0x07);
  }
 else if(Ypos==3)
  {
   textattr(0x70);
   printf("In_Queue\n  Out_Queue\n  ");
   cprintf("Display\r\n");
   printf("  Exit");
   textattr(0x07);
  }
 else if(Ypos==4)
  {
   textattr(0x70);
   printf("In_Queue\n  Out_Queue\n  Display\n  ");
   cprintf("Exit");
   textattr(0x07);
   }
}




void cursor(int Ypos)  //fn to print cursor on screen
{
 gotoxy(1,Ypos);
 printf(">");
}