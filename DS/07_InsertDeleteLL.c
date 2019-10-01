/*
 *  --- Program to demonstrate Linked Lists ---
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}*NODE;

NODE getnode(){
    NODE p;
    p=(NODE)malloc(sizeof(struct node));
    if(p != NULL)
        return p;
    else{
        printf("No memory allocation.\n");
        exit(0);
    }
}

/*
 *  --- Insert Functions ---
 */

NODE insertFront(NODE head, int item){
    NODE p;
    p = getnode();
    p->data = item;
    p->next = head;
    head = p;
    return head;
}

NODE insertRear(NODE head, int item){
    NODE p, q;
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

NODE insertPos(NODE head, int item, int pos){
    NODE curr, prev = NULL, newn;
    int count=1;

    newn = getnode();
    newn->data = item;
    newn->next = NULL;
    
    if(head == NULL){
        if(pos == 1)
            return newn;
        else{
            printf("Invalid position\n");
            return 0;
        }
    }
    
    if(pos == 1){
        newn->next = head;
        head = newn;
        return head;
    }
    else{
        curr = head;
        while(curr != NULL  &&  count != pos){
            prev = curr;
            curr = curr->next;
            count++;
        }

        if(count == pos){
            prev->next = newn;
            newn->next = curr;
            return head;
        }
        else{
            printf("Invalid position\n");
            return head;
        }
    }
}

/*
 *  --- Delete Functions ---
 */

NODE deleteFront(NODE head){
	NODE p;
	if(head == NULL)
		printf("List is empty");
	else{
		printf("Deleted %d\n", head->data);
		p = head->next;
		free(head);
		return p;
	}
}

NODE deleteRear(NODE head){
	NODE p,prev;
	p = head;
	if(head == NULL)
		printf("List is empty\n");
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

NODE deletePos(NODE head, int pos){
    NODE p = head;
    if(head == NULL)
        printf("List is empty\n");
    else if(pos == 0){
        printf("Deleted %d\n", head->data);
        NODE temp = head->next;
        free(head);
        head = temp;
    }
    else{
        for(int i=0; i<pos-1; i++){
            p = p->next;
        }
        // now p at element 1 less than given pos
        if(p->next == NULL){
            printf("Invalid Postion\n");
        }
        else{
            NODE temp = p->next;
            printf("Deleted %d\n", temp->data);
            p->next = (p->next)->next;
            free(temp);
        }        
    }
    return head;
}

void display(NODE head){
    NODE p;
    if(head == NULL){
        printf("List is empty\n");
        exit(0);
    }
    p = head;
    printf("LIST >> ");
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

void main()
{
    NODE head = NULL;
    int c, c1, ele, pos, value;
    while(1){
        printf("\n\n--MENU--\n");
        printf("1.Insert\n2.Delete\n5.Exit\n");
        scanf("%d", &c);
        switch(c){
            case 1:
                printf("\t1.At front\n\t2.At rear\n\t3.At postion\n");
                scanf("%d", &c1);
                switch(c1){
                    case 1:
                        printf("Element to insert:");
                        scanf("%d", &ele);
                        head = insertFront(head, ele);
                        display(head);
                        break;
                    case 2:
                        printf("Element to insert:");
                        scanf("%d", &ele);
                        head = insertRear(head, ele);
                        display(head);
                        break;
                    case 3:
                        printf("Enter positon and value:");
                        scanf("%d %d", &pos, &value);
                        head = insertPos(head, value, pos);
                        display(head);
                        break;
                    default:
                        printf("Wrong choice!");
                }
                break;
            
            case 2:
                printf("\t1.At front\n\t2.At rear\n\t3.At postion\n");
                scanf("%d", &c1);
                switch(c1){
                    case 1:
                        head = deleteFront(head);
                        display(head);
                        break;
                    case 2:
                        head = deleteRear(head);
                        display(head);
                        break;
                    case 3:
                        printf("Enter positon:");
                        scanf("%d", &pos);
                        head = deletePos(head, pos-1);
                        display(head);
                        break;
                    default:
                        printf("Wrong choice!");
                }
                break;

            case 5:
                exit(1);		
        }
    }
}