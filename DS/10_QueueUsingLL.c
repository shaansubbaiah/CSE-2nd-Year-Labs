/*
 *  --- Queue using LinkedList ---
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


NODE deleteRear(NODE head){
	NODE p,prev;
	p = head;
	if(head == NULL)
		printf("Queue is empty\n");
	else{
        if(p->next == NULL){
            printf("Deleted %d\n", p->data);
            free(p);
            head = NULL;
        }
		while(p->next != NULL){
			prev = p;
			p = p->next;
		}
		printf("Deleted %d\n", p->data);
		free(p);
		prev->next = NULL;
	}
	return head;
}


void display(NODE head){
    NODE p;
    if(head == NULL){
        printf("Queue is empty\n");
        return;
    }
    p = head;
    printf("QUEUE >> ");
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
        printf("\n\n1.Enqueue\n2.Dequeue\n5.Exit\n");
        scanf("%d", &c);
        switch(c){
            case 1:
                printf("Element:");
                scanf("%d", &ele);
                head = insertFront(head, ele);
                display(head);
                break;
            
            case 2:
                head = deleteRear(head);
                display(head);
                break;

            case 5:
                exit(1);		
        }
    }
}
