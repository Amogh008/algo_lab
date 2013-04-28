#include <stdio.h>
#include <stdlib.h>

typedef struct key
{
  int data;
  struct key *lchild;
  struct key *rchild;
}node;

void print_tree(node *root)
{
  if(root!=NULL)
    {
      print_tree(root->lchild);
      printf("%d -> ",root->data);
      print_tree(root->rchild);
    }
  
}
void insert(node *root)
{
  int parent;
  node *temp1, *temp2=NULL;
  temp1=root;
  int entry;
  
  printf("please enter the value to be inserted: ");
  scanf("%d",&entry);
  printf("\n");
  
  while(temp1!=NULL)
    {
      temp2=temp1;
      if(temp1->data<entry)
	temp1=temp1->rchild;
      else
	temp1=temp1->lchild;
    }
  
  if(entry>temp2->data)
    {
      parent=temp2->data;
      temp2->rchild=(node *)malloc(sizeof(node));
      temp2=temp2->rchild;
      temp2->data=entry;
      temp2->rchild=NULL;
      temp2->lchild=NULL;
      printf("\nthe value has been inserted at the right child of %d\n",parent);
    }
  
  else 
    {
      parent=temp2->data;
      temp2->lchild=(node *)malloc(sizeof(node));
      temp2=temp2->lchild;
      temp2->data=entry;
      temp2->rchild=NULL;
      temp2->lchild=NULL;
      printf("\nthe value has been inserted at the left child of %d\n",parent);
    }
}

node *tree_min(node *root)
{
  node *temp1, *temp2;
  temp1=root;
  while(temp1->lchild!=NULL)
    {
      temp2=temp1;              
      temp1=temp1->lchild;
    }
  return temp2;
}

node *tree_max(node *root)
{
  node *temp1, *temp2;
  temp1=root;
  while(temp1->rchild!=NULL) 
    {
      temp2=temp1;
      temp1=temp1->rchild;
    }
  return temp2;
}

int delete_item(node *root)
{
  int exchange;
  node *min_par, *min;
  node *temp1, *temp2;	
  temp1=root;
  int val;
  printf("please enter the value to be deleted: ");
  scanf("%d",&val);
  printf("\n");
  
  if(temp1==NULL)
    {
      printf("tree not created.\n");
      return 0;
    }
  temp2=temp1;
  while(val!=temp1->data)
    {
      temp2=temp1;
      if(val > temp1->data)
	temp1=temp1->rchild;
      else
	temp1=temp1->lchild;
    }
  
  if(temp1->lchild==NULL && temp1->rchild==NULL)
    {
      if(temp1->data > temp2->data)
        {
	  temp2->rchild=NULL;
	  free(temp1);
	  return val;
        }
      else
        {
	  temp2->lchild=NULL;
	  free(temp1);                                     
	  return val;
        }
    }
  
  else if(temp1->lchild==NULL && temp1->rchild!=NULL)
    {
      if(temp1->data > temp2->data)
        {
	  temp2->rchild=temp1->rchild;
	  free(temp1);
	  return val;
        }
      else
        {
	  temp2->lchild=temp1->rchild;
	  free(temp1);                                     
	  return val;
        }                   
    }
  
  else if(temp1->lchild!=NULL && temp1->rchild==NULL)
    {
      if(temp1->data > temp2->data)
        {
	  temp2->rchild=temp1->lchild;
	  free(temp1);
	  return val;
        }
      else
        {
	  temp2->lchild=temp1->lchild;
	  free(temp1);                                     
	  return val;
        }                   
    }
  
  else if(temp1->lchild!=NULL && temp1->rchild!=NULL)
    {
      min_par=tree_min(temp1->rchild);
      min=min_par->lchild;
      exchange=min->data;
      min->data=temp1->data;
      temp1->data=exchange;
      
      if(min->lchild==NULL && min->rchild==NULL)
        {
	  min_par->lchild=NULL;
	  free(min);                 
	  return val;
        }
      
      else if(min->rchild!=NULL)
        {
	  min_par->lchild=min->rchild;
	  free(min);
	  return val;
        }
    }
}


int main()
{
    int suc,num_suc;
    int del_val;
    int num;
    node *root;
    int choice=1,menu_choice;
    
    root=(node *)malloc(sizeof(node));
    printf("enter the value at the node: ");
    scanf("%d",&num);
    printf("\n");
	
    root->data=num;
    root->lchild=NULL;
    root->rchild=NULL;
    
    while(choice==1)
      {
	printf("what do you want to do:\n\n1.>insert a node\n2.>delete a node\n3.>print the tree in inorder\n4.>exit\n\n");
	printf("please enter your choice: ");
	scanf("%d",&menu_choice);
	printf("\n");
	
	if(menu_choice==1)
	  {
	    insert(root);
	  }
	
	else if(menu_choice==2)
	  {
	    del_val=delete_item(root);
	    if(del_val!=0)
	      printf("\n%d has been successfully deleted\n",del_val);
	  }
	
	else if(menu_choice==3)
	  {
            printf("\n"); 
            print_tree(root);
            printf("NULL\n\n"); 
	  }
        
	else if(menu_choice==4) 
	  exit(-1);
	
	printf("enter 1 to go to the main menu or '0' to exit: ");
	scanf("%d",&choice);
	printf("\n");
	
	if(choice==0)
	  exit(-1);
	printf("\n");
      }
    
    return 0;
}

