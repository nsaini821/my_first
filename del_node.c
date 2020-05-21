#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int data;
	struct node *next;

};

void nodeat_end(struct node **ptr, int var)
{
	struct node *last = NULL;
	struct node *tmp= malloc(sizeof(struct node));
	memset(tmp,'\0',sizeof(tmp));
	//struct node *last= malloc(sizeof(struct node));
	//memset(last,'\0',sizeof(last));
	tmp->data=var;
	if(*ptr==NULL)
	{
		tmp->next = NULL;
		*ptr =tmp;
		return ;
	}

	last=*ptr;
	while(last->next!=NULL)
		last=last->next;
	last->next=tmp;
	tmp->next=NULL;



}
void  del_node(struct node **head,int delnode)
{
	struct node *prev=NULL;
	struct node *del =*head;

		if (del->data == delnode)
		{

	 *head=(*head)->next;
	 del->next=NULL;
	 free(del);


	 }

	 else
	 { 	

	while(del->data!=delnode)
	{
		prev=del;
		del=del->next;
	}
	prev->next=del->next;
	del->next=NULL;
	free(del);
	return;

}

}

void print_node(struct node *head)
{
	while(head!=NULL)
	{
		//	head1= head1->next;
		printf("-link list  is------>%d\n",head->data);
		head= head->next;
	}
}


int main()
{
	int var,i;
	int delnode;
	struct node *head=NULL;
	printf("------>%p\n",head);
	printf("enter the data for link list\n");
	for(i=0;i<6;i++)
	{
		scanf("%d",&var);

		nodeat_end(&head ,var);
	}
	//printf("%p\n",head);
	print_node(head);
	printf("enter the node which u want to delete\n");
	scanf("%d",&delnode);
	del_node(&head,delnode);
	print_node(head);
}
