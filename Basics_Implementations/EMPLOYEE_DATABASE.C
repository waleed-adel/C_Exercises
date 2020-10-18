#include<stdio.h>
#include<conio.h>
#include<string.h>

#define  n  3

struct employee
{
 int ID;
 char name[50];
};

void search_name(struct employee* sptr,char* name_emp);
void search_id (struct employee* sptr,int id);
void scan_emp(struct employee* sptr);


void main(void)
{
 struct employee arr[n];
 struct employee* sptr = arr;
 int x;
 char name_emp[50];
 clrscr();
 scan_emp(sptr);
 printf("\nPlease Enter 1 for ID search or 2 for Name search:");
 scanf("%d",&x);
 flushall();
 if(x == 1)
  {
   clrscr();
   printf("Please Enter an ID:");
   scanf("%d",&x);
   flushall();
   search_id(sptr,x);
   getch();
  }
 else if(x == 2)
  {
	clrscr();
	printf("Please Enter a Name:");
	gets(name_emp);
	search_name(sptr,name_emp);
	getch();
  }
}



void scan_emp(struct employee* sptr)
{
 int i;
 for(i=0;i<n;i++)
 {
  printf("Employee[%d]\n",i);
  printf("Please Enter Employee ID: ");
  scanf("%d",&sptr[i].ID);
  flushall();
  printf("Please Enter Employee Name:");
  gets(sptr[i].name);
  printf("\n");
 }
 flushall();
}


void search_id (struct employee* sptr,int id)
{
 int i, flag=0;
 clrscr();
 for(i=0;i<n;i++)
 {
   if(sptr[i].ID == id)
	{
	 printf("Employee[%d]\nID:%d\nName:%s\n",i,sptr[i].ID,sptr[i].name);
	 flag=1;
	 break;
	}
 }
 if(flag == 0)
 printf("Your ID is Not Found!!");
}


void search_name(struct employee* sptr,char* name_emp)
{
  int i, j, x, flag=0;
  clrscr();
  for(i=0;i<n;i++)
  {
	 x = strcmp(sptr[i].name,name_emp);
	 if(x == 0)
	 {
	  flag = 0;
	  break;
	 }
	 else if (x < 0 || x > 0)  flag=1;
  }
  if(flag == 0)
  printf("Employee[%d]\nID:%d\nName:%s\n",i,sptr[i].ID,sptr[i].name);
  else if (flag == 1)
  printf("Name Entered is not Found!!\n");
}