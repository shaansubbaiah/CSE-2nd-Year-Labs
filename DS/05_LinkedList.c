#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}*NODE;

NODE getnode()
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else
	{
		printf("No memory allocatipon\n");
		exit(0);
	}
}

NODE insertFront(NODE head,int item)
{
	NODE p;
	p = getnode();
	p->data = item;
	p->next = head;
	head = p;
	return head;
}

void display(NODE head)
{
	NODE p;
	if(head == NULL){
		printf("List is empty\n");
		exit(0);
	}
	p = head;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
}

NODE insertRear(NODE head, int item)
{
	NODE p,q;
	q = getnode();
	q->data = item;
	q->next = NULL;
	
	if(head == NULL)
		return q;
	p = head;
	while(p->next != NULL)
		p = p->next;
	p->next = q;
	return head;	
}

void main()
{
	NODE head = NULL;
	int c, ele, pos, value;
	while(1)
	{
        printf("\n\n--MENU--\n");
		printf("1.Insert front\n2.Insert end\n4.Display\n5.Exit\n");
		scanf("%d", &c);
		switch(c)
		{
			case 1:
                printf("Element to insert:");
				scanf("%d", &ele);
				head=insertFront(head,ele);
				break;
			case 2:
                printf("Element to insert:");
				scanf("%d", &ele);
				head=insertRear(head,ele);
				break;
			case 4:
                printf("LIST >> ");
				display(head);
				break;
			case 5:
				exit(0);		
		}
	}
}