/*
 *  --- Program to demonstrate Sorted Linked Lists ---
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}*NODE;

int len = 0;    // length of list

NODE getnode(){
    NODE p;
    p=(NODE)malloc(sizeof(struct node));
    if(p != NULL){
        len++;  // increment len
        return p;
    }
    else{
        printf("No memory allocation.\n");
        exit(0);
    }
}

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
        if(pos==1)
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

void display(NODE head){
    NODE p;
    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        p = head;
        while(p != NULL){
            printf("%d ", p->data);
            p = p->next;
        }
    }
}

void sortList(NODE head){
    printf("LIST >> ");
    display(head);

    NODE p = head;
    for(int i=0; i<len-1; i++){
        for(int j=0; j<len-1; j++){
            //swappity swap
            if(((p->next)->data)  <  (p->data)){
                int temp = (p->data);
                (p->data) = ((p->next)->data);
                ((p->next)->data) = temp;
            }
            p = p->next;
        }
        p = head;
    }

    printf("\nSORTED> ");
    display(head);
}

void main()
{
    NODE head = NULL;
    int c, ele, pos, value;

    while(1){
        printf("\n\n--MENU--\n");
        printf("1.Insert at front\n2.Insert at rear\n3.Insert at pos\n5.Exit\n");
        scanf("%d", &c);
        switch(c){
            case 1:
                printf("Element to insert:");
                scanf("%d", &ele);
                head = insertFront(head, ele);
                sortList(head);
                break;

            case 2:
                printf("Element to insert:");
                scanf("%d", &ele);
                head = insertRear(head, ele);
                sortList(head);
                break;

            case 3:
                printf("Enter positon and value:");
                scanf("%d %d", &pos, &value);
                head = insertPos(head, value, pos);
                sortList(head);
                break;   

            case 5:
                exit(1);
                
            default:
                printf("\nWrong Choice.\n");
        }
    }
}
