#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50

struct infix
{
	char target[SIZE];
	char stack[SIZE];
	char *s,*t;
	int top,l; 
};

void create(struct infix *);
void process(struct infix *,char *);
void push(struct infix *,char);
char pop(struct infix *);
void convert(struct infix *);
int preceedence(char c);
void display(struct infix);

int main( )
{
    struct infix q;
	  char expr[SIZE];
    create(&q);

	printf("\nplease enter an infix expression: ");
	gets(expr);

	process(&q,expr);
	convert(&q);

	printf("The Final Prefix expression is: ");
	display(q);

	getch( );
}

//initialses the elements
void create(struct infix *node)
{
	node->top=-1;
	strcpy(node->target,"");
	strcpy(node->stack,"");
	node->l=0;
}

//reverses the given expression
void process(struct infix *node,char *str)
{
	node->s=str;
	strrev(node->s) ;
	node->l=strlen(node->s);
	*(node->target+node->l)='\0';
	node->t=node->target+(node->l-1);
}

//adds an operator to the stack
void push(struct infix *node,char c)
{
	if (node->top==SIZE-1)
		printf("\nStack is full.\n");
	else
	{
		node->top++;
		node->stack[node->top]=c;
	}
}

//pops an operator from the stack
char pop(struct infix *node)
{
	if(node->top==-1)
	{
		printf("Stack is empty\n");
			return -1;
	}
	else
	{
		char item=node->stack[node->top];
		node->top--;
		return item;
	}
}

//converts the given infix string to prefix
void convert(struct infix *node)
{
	char op ;

	while (*(node->s))
	{
		if (*(node->s)==' ' || *(node->s)=='\t')
		{
			node->s++    ;
			continue ;
		}

		if (isdigit(*(node->s)) || isalpha(*(node->s)))
		{
			while(isdigit(*(node->s)) || isalpha(*(node->s)))
			{
				*(node->t)=*(node->s)  ;
				node->s++;
				node->t--;
			}
		}

		if(*(node->s)==')')
		{
			push(node,*( node -> s )) ;
			node->s++;
		}

		if(*(node->s)=='*' || *(node->s)=='+' || *(node->s)=='/' ||
			 *(node->s)=='%' || *(node->s)=='-' || *(node->s)=='$')
		{
		
			if(node->top!=-1)
			{
				op=pop(node) ;

				while(preceedence(op)>preceedence(*(node->s)))
				{
					*(node->t)=op ;
					node->t--;
					op=pop(node) ;
				}
				push(node,op);
				push(node,*(node->s)) ;
			}
		
			else
				push(node,*(node->s)) ;
			node->s++;
		}

		if(*(node->s)=='(')
		{
			op=pop(node);
		
			while(op!=')')
			{
				*(node->t)=op;
				node->t--;
				op=pop(node);
			}
			node->s++;
		}
		
	}

	while(node->top!=-1)
	{
		op=pop(node);
		*(node->t)=op;
		node->t--;
	}
	node->t++;
}

//this fuction determines the preceedence of an operator
int preceedence(char c)
{
	if(c=='$')
		return 3 ;

	if(c=='*' || c=='/' || c=='%')
		return 2;
	else
	{

		if(c=='+' || c=='-')
			return 1;
		else
			return 0;
	}
}

// display function
void display(struct infix node)
{
	while(*(node.t))
	{
		printf(" %c",*(node.t)) ;
		node.t++;
	}
}
