/*  Doubly Linked List 😈  */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}*NODE;

NODE makeNode(int x){
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

/*   

    Insert Functions

*/

NODE insertFront(NODE head){
    int ele;
    printf("\nElement:");
    scanf("%d", &ele);

    NODE temp = makeNode(ele);
    temp->next = head;

    return temp;
}

NODE insertRear(NODE head){
    int ele;
    printf("\nElement:");
    scanf("%d", &ele);
    
    NODE temp = makeNode(ele);
    
    if(head == NULL){
        return temp;
    }
    else{
        NODE p = head;
     
        // p will point to last element
        while((p->next) != NULL){
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;

        return head;
    }    
}

NODE insertPos(NODE head){
    int ele, pos;
    printf("\nElement & Position: ");
    scanf("%d %d", &ele, &pos);

    NODE temp = makeNode(ele);

    if(head == NULL){
        if(pos != 1)
            printf("\nPosition doesnt exist!");
        else
            return temp;
    }
    else{
        NODE p = head;

        // p will point to pos-1'th element
        for(int c=0; c<pos-1; c++){
            p = p->next;
        }
        // backup p->next
        (p->next)->prev = temp;
        temp->next = p->next;
        p->next = temp;
        temp->prev = p;

        return head;
    }
}

/*   

    Delete Functions

*/

NODE deleteFront(NODE head){
    if(head == NULL)
        printf("\nList Empty!");
    else{
        NODE temp = head->next;
        if(temp == NULL){
            return NULL;
        }
        else{
            temp->prev = NULL;
            free(head);
            return temp;
        }        
    }    
}

NODE deleteRear(NODE head){
    if(head == NULL)
        printf("\nList Empty!");
    else{
        NODE temp = head;
        // temp goto last but 1 ele
        while((temp->next)->next != NULL){
            temp = temp->next;
        }  
        free(temp->next);
        temp->next == NULL;
        return head;
    }
}

NODE deletePos(NODE head){
    if(head == NULL)
        printf("\nList Empty!");
    else{
        int pos;
        NODE temp = head;  
        printf("Enter Position:");
        scanf("%d", &pos);
        
        if(pos == 1)
            head = deleteFront(head);
        else{
            int i=1;
            while(i < pos){
                if(temp->next != NULL)
                    temp = temp->next;
                else{
                    printf("Position doesnt exist!"); 
                    return head;  
                }
                i++;
            }
            NODE posnd = temp->next;
            (posnd->next)->prev = temp;
            temp->next = posnd->next;
            free(posnd);
            return head;
        }
    }
}

void display(NODE head){
    if(head == NULL)
        printf("\nEmpty List!");
    else{
        NODE p = head;

        printf("\nLIST >> ");
        while(p != NULL){
            /* data view */
            printf("%d ", p->data);

            /* full view */
            // printf("\n%d\t%d\t%d", &(p->prev), p->data, &(p->next));

            p = p->next;
        }
    }
}

void main(){
    NODE head = NULL;
    int ch;

    printf("\n\n---MENU---\n1.Ins Fr\n2.Ins Rr\n3.Ins Ps");
    printf("\n4.Del Fr\n5.Del Rr\n6.Del Ps\n8.Exit\n");
    while(1){
        // printf("\n\n---MENU---\n1.Ins Fr\n2.Ins Rr\n3.Ins Ps");
        // printf("\n4.Del Fr\n5.Del Rr\n6.Del Ps\n420.Exit\n");
        printf("\nChoice:");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                head = insertFront(head);
                display(head);
                break;
            case 2:
                head = insertRear(head);
                display(head);
                break;
            case 3:
                head = insertPos(head);
                display(head);
                break;
            case 4:
                head = deleteFront(head);
                display(head);
                break;
            case 5:
                head = deleteRear(head);
                display(head);
                break;
            case 6:
                head = deletePos(head);
                display(head);
                break;
            case 8:
                printf("\nExiting!");
                exit(1);
            default:
                printf("\nWrong Input!");
        }
    }
}