#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define UP    72
#define DOWN  80
#define ESC   27
#define ENTER 13




typedef struct node
{
 int ID;
 char name[50];
 struct node* next;
 struct node* previous;
}node;

typedef struct linkedlist
{
 struct node* start;
 struct node* end;
}linkedlist;




node* create_node (void);
node* search_node(linkedlist* l,node* data,int);
int delete_node(linkedlist* l,node* ptr);
void free_list(linkedlist* l);
void add_node (linkedlist* l,node* new_element);
void insert_node(linkedlist* l,node* new_element);
void display_list (linkedlist* l);
void scan_data (node* emp);
void printMenu(int Ypos);
void cursor(int Ypos);




void main(void)
{
  int i ,x ,Xpos=3 ,Ypos=1;
  char key;
  node* ptr_node;
  linkedlist* l;
  l -> start = NULL;    //initialize an empty linked list
  l -> end = NULL;
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
		if(Ypos==7) Ypos=1;
		gotoxy(Xpos,Ypos);
		break;

		case UP:
		Ypos--;
		if(Ypos==0) Ypos=6;
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
		 ptr_node = create_node();
		 scan_data(ptr_node);
		 add_node(l,ptr_node);
		 break;

		 case 2:
		 clrscr();
		 ptr_node=create_node();
		 scan_data(ptr_node);
		 insert_node(l,ptr_node);
		 printf("Insert Successful");
		 getch();
		 break;

		 case 3:
		 clrscr();
		 printf("Enter 1 for ID Search\nEnter 2 for Name Search\n");
		 scanf("%d",&x);
		 flushall();
		 ptr_node=search_node(l,ptr_node,x);
		 x=delete_node(l,ptr_node);
		 if(x == 0)
		 printf("NOT FOUND!!");
		 else
		 printf("Delete Successful");
		 getch();
		 break;

		 case 4:
		 clrscr();
		 ptr_node=create_node();
		 printf("Enter 1 for ID Search\nEnter 2 for Name Search\n");
		 scanf("%d",&x);
		 flushall();
		 ptr_node=search_node(l,ptr_node,x);
		 if(ptr_node == NULL)
		 printf("NOT FOUND!!");
		 else
		 printf("Employee ID:%d\t\tEmployee Name:%s\n",ptr_node -> ID,ptr_node -> name);
		 getch();
		 break;

		 case 5:
		 clrscr();
		 display_list(l);
		 getch();
		 break;

		 case 6:
		 free_list(l);
		 key=ESC;
		 break;
	   }
	 }

	else if(key==ESC)  break;

   }while(key!=ESC);
} //end of main




node* create_node (void)
{
 return (node*)malloc(sizeof(node));
}




void scan_data (node* emp)
{
 clrscr();
 printf("Please Enter Employee Data\n");
 printf("Employee ID:");
 scanf("%d",&emp -> ID);
 flushall();
 printf("Please Enter Employee Name:");
 gets(emp -> name);
}




void add_node (linkedlist* l,node* new_element)
{
  if (l -> start == NULL)
  {
	l -> start = new_element;
	l -> end = new_element;
	new_element -> next = NULL;
	new_element -> previous = NULL;
  }
  else
  {
	l -> end -> next = new_element;
	new_element -> previous = l -> end;
	l -> end = new_element;
	new_element -> next = NULL;
  }
}




void insert_node(linkedlist* l,node* new_element)
{
 node* temp_ptr;
 temp_ptr = l -> start;
 while(temp_ptr && ((temp_ptr -> ID) < (new_element -> ID)))
 {
  temp_ptr = temp_ptr -> next;
 }

 if (!temp_ptr)                  //case: empty linked list
 add_node(l,new_element);    //insert a new node at the beginning

 else if(temp_ptr == l -> start)  //case: ID smaller than first element in list
 {
  new_element -> next = l -> start;
  l -> start -> previous = new_element;
  l ->start = new_element;
  new_element -> previous = NULL;
 }

 else       //case: insert a node in between two nodes
 {
  temp_ptr -> previous -> next = new_element;
  new_element -> previous = temp_ptr -> previous;
  new_element -> next = temp_ptr;
  temp_ptr -> previous = new_element;
 }
}

int delete_node(linkedlist* l,node* ptr)
{
 int x;
 node* temp = ptr;
 if(temp == NULL)
 return 0;   //node not found (data entered not found)

 else if (l -> start == temp && l -> end == temp) //case: empty list
 {
  l -> start = l -> end = NULL;
  free(temp);
 }
 else if(l -> start == temp)    //case: deleting first node
 {
  l -> start = l -> start -> next;
  l -> start -> previous = NULL;
  free(temp);
 }
 else if (l -> end == temp)  //case: deleting last node
 {
   l -> end = l -> end -> previous;
   l -> end -> next = NULL;
   free(temp);
 }
 else    //case: deleting a node between 2 nodes
 {
   temp -> next -> previous = temp -> previous;
   temp -> previous -> next = temp -> next;
   free(temp);
 }
 return 1;
}



void free_list(linkedlist* l)
{
 node* temp = l -> start;
 while(l -> start)
 {
   l -> start = temp -> next;
   free(temp);
   temp = l -> start;
 }
}



node* search_node(linkedlist* l,node* data,int x)
{
 node* temp = l -> start;
 if(l -> start == NULL)
 return NULL;
 if(x == 1)
 {
  printf("\nPlease Enter an ID: ");
  scanf("%d",&data -> ID);
 }
 else if(x == 2)
 {
  printf("\nPlease Enter a Name: ");
  gets(data -> name);
 }
 while(x==1 && temp && ((temp -> ID) != (data -> ID)) )
 {
  temp = temp -> next;
 }
 while(x==2 && temp && (strcmp((temp -> name),(data -> name))) )
 {
  temp = temp -> next;
 }
 return temp;
}



void display_list (linkedlist* l)
{
  node* temp = l -> start;
  while(temp!=NULL)
  {
   printf("Employee ID: %d\t\tEmployee Name:%s\n",temp -> ID,temp -> name);
   temp = temp -> next;
  }
}



void printMenu(int Ypos)
{
 gotoxy(3,1);
 if(Ypos==1)
  {
   textattr(0x70);
   cprintf("Add\r\n");  //use \r\n to go to new line when using cprintf
   printf("  Insert\n  Delete\n  Search\n  Display\n  Exit");
   textattr(0x07);
  }
 else if(Ypos==2)
  {
   textattr(0x70);
   printf("Add\n  ");
   cprintf("Insert\r\n");
   printf("  Delete\n  Search\n  Display\n  Exit");
   textattr(0x07);
  }
 else if(Ypos==3)
  {
   textattr(0x70);
   printf("Add\n  Insert\n  ");
   cprintf("Delete\r\n");
   printf("  Search\n  Display\n  Exit");
   textattr(0x07);
  }
 else if(Ypos==4)
  {
   textattr(0x70);
   printf("Add\n  Insert\n  Delete\n  ");
   cprintf("Search\r\n");
   printf("  Display\n  Exit");
   textattr(0x07);
   }
 else if(Ypos==5)
  {
   textattr(0x70);
   printf("Add\n  Insert\n  Delete\n  Search\n  ");
   cprintf("Display\r\n");
   printf("  Exit");
   textattr(0x07);
  }
 else if(Ypos==6)
  {
   textattr(0x70);
   printf("Add\n  Insert\n  Delete\n  Search\n  Display\n  ");
   cprintf("Exit");
   textattr(0x07);
  }
}



void cursor(int Ypos)  //fn to print cursor on screen
{
 gotoxy(1,Ypos);
 printf(">");
}
