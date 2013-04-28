#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 15
#define true 1
#define false 0

/*Structure Decvlaration*/
typedef struct
{
char data[MAX];
char top;
}STK;

/*Function Declarations*/
void input(char str[]);
void intopre(char str1[],char pre[]);
void intopost(char str1[],char post[]);
int isoperand(char sym);
int prcd(char sym);
void push(STK *s1,char elem);
int pop(STK *s1);
int empty(STK *s2);
int full(STK *s2);
void dis(char str[]);

int main()
{
STK s;
int cs,ans;
char str[MAX],pre[MAX],post[MAX];

do                                                   /*Using Do-while Loop*/
{
//clrscr();
printf("-----Program for Expressions-----");
printf("Input The String:");
printf("MENU:");
printf("1.Infix to Prefix");
printf("2.Infix to Postfix");
printf("3.Exit");
cs=getche();

switch(cs)  /*Using Switch Case*/
{
case '1':
intopre(str,pre);
break;
case '2':
intopost(str,post);
break;
case '3':
break;
default:
printf("Enter a Valid Choise!"); /*Default Case*/
break;
}
printf("Do you wish to Continue?(y/n)");
ans=getche();
}while(ans=='y'||ans=='Y');   /*Condition for Do-while loop*/

getch();
return 0;
}

/*To Input String*/
void input(char str[])
{
printf("Enter the Infix String:");
scanf("%s",str);
}

/*To Covert Infix To Prefix*/
void intopre(char str1[],char pre[])
{
 	 STK s1;
int len,flag;
len=strlen(str1);
int check=0,cnt=len-1,pos=0;
char elem;

while(cnt>=0)  /*while condition*/
{
flag=0;
if(isoperand(str1[cnt]))   /*Checking for Operand*/
{
printf("%c",str1[cnt]);
cnt--;
pos++;
}
else
{
check=prcd(str1[cnt]);
while(check==false)
{
pre[pos]=str1[cnt];
flag=1;
pos++;
cnt--;
}
if(flag==0)
{
elem=pop(&s1);
printf("%c",elem);
}
}

}
}

/*To Convert Infix To Postfix*/
void intopost(char str1[],char post[])
{
int len;
len=strlen(str1);
int check=0,cnt=len-1,pos=0;

}

/*To Check For Operand*/
int isoperand(char sym)
{
if('A'<sym<'Z'||'a'<sym<'z')
return(true);
return(false);
}

/*To Check The Precedence*/
int prcd(char sym)
{

}

/*To Display String*/
void dis(char str[])
{


}

/*Push Function Definition*/
void push(STK *s1,char elem)
{
if(!full(s1))
{
s1->top++;                  /*Incrementing top*/
s1->data[s1->top]=elem;     /*Storing element*/
}
else
printf("Stack is Full!");
}

/*Full Function Definition*/
int full(STK *s2)
{
if(s2->top==MAX)    /*Condition for Full*/
return(true);
return(false);
}

/*Pop Function Definition*/
int pop(STK *s1)
{
char elem;
if(!empty(s1))
{
elem=s1->data[s1->top]; /*Storing top stack element in elem*/
s1->top--;              /*Decrementing top*/
return(elem);
}
return(false);
}

/*Empty Function Definition*/
int empty(STK *s2)
{
if(s2->top==-1)         /*Condition For Empty*/
return(true);
return(false);
}
