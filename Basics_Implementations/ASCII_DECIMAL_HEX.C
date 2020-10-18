#include <stdio.h>
#include<conio.h>

void main (void)

{
int y,z;
char x;
clrscr();
printf("hello world\n");
printf("please enter a character: \n");
scanf("%c",&x);
printf("ASCII: %d\n",x);
printf("please enter a number: \n");
scanf("%d",&y);
printf("Equivelant Char.: %c\n",y);
printf("please enter a decimal: \n");
scanf("%d",&z);
printf("HEX: %x",z);
getch();
}
