/*
 *  --- Stack using LinkedList ---
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}*NODE;


NODE getnode(){
	return (NODE)malloc(sizeof(struct node));
}


NODE insertFront(NODE head, int item){
    NODE p;
    p = getnode();
    p->data = item;
    p->next = head;
    head = p;
    return head;
}


NODE deleteFront(NODE head){
	NODE p;
	if(head == NULL)
		printf("Stack is empty");
	else{
		printf("Deleted %d\n", head->data);
		p = head->next;
		free(head);
		return p;
	}
}


void display(NODE head){
    NODE p;
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }
    p = head;
    printf("STACK >> ");
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}


void main()
{
    NODE head = NULL;
    int c, ele;

    while(1){
        printf("\n\n1.Push\n2.Pop\n5.Exit\n");
        scanf("%d", &c);
        switch(c){
            case 1:
                printf("Element:");
                scanf("%d", &ele);
                head = insertFront(head, ele);
                display(head);
                break;
            
            case 2:
                head = deleteFront(head);
                display(head);
                break;

            case 5:
                exit(1);		
        }
    }
}
