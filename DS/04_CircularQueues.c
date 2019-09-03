/*
 *  --- Program to demonstrate circular queues ---
 */
#include<stdio.h>
#include<stdlib.h>
#define size 3

void enqueue(int q[], int *r, int *f){
  	if((*r-*f == size-1)  ||  *r == *f-1)
    	printf("Queue is full!\n");
  	else{
        if(*r == -1 && *f == -1)
            *r = *f = 0;
        else
    	    *r = (*r+1) % size;
        printf("Value to enqueue:");
    	scanf("%d", &q[*r]);
  	}
}


void dequeue(int q[], int *r, int *f){
  	if(*f == -1)
    	printf("Queue is empty!\n");
  	else{
    	printf("Item deleted: %d\n", q[*f]);
    	if(*f == *r)
            *f = *r = -1;
        else
            *f = (*f+1) % size;
  	}
}


void display(int q[], int *r, int *f){
  	int i;
 	if(*f == -1)
    	printf("Queue is empty!\n");
	else{
		printf("----------------------\n");	
 		for(i = *f;; i++){
            i %= size;
   			printf("%d ", q[i]);
            if(*r == i)
                break;
  		}
  		printf("\n----------------------\n");
	}	
}


void main(){
	int q[20], r = -1, f = -1;
  	int a;
  	while(1){
		printf("\n\n----MENU----\n");
    	printf("\n1.Enqueue \n2.Dequeue\n3.Display\n4.Exit\n");
    	scanf("%d", & a);
    	switch (a) {
    	case 1:
      		enqueue(q, &r, &f);
      		break;
   		case 2:
      		dequeue(q, &r, &f);
      		break;
    	case 3:
      		display(q, &r, &f);
      		break;
    	case 4:
      		exit(0);
      		break;
    	default:
      		printf("INVALID CHOICE\n");
    	}
  	}
}

/* ---- OUTPUT ----

----MENU----

1.Enqueue 
2.Dequeue
3.Display
4.Exit
1
Value to enqueue:10


----MENU----

1.Enqueue 
2.Dequeue
3.Display
4.Exit
1
Value to enqueue:20


----MENU----

1.Enqueue 
2.Dequeue
3.Display
4.Exit
1
Value to enqueue:30


----MENU----

1.Enqueue 
2.Dequeue
3.Display
4.Exit
3
----------------------
10 20 30 
----------------------


----MENU----

1.Enqueue 
2.Dequeue
3.Display
4.Exit
2
Item deleted: 10


----MENU----

1.Enqueue 
2.Dequeue
3.Display
4.Exit
1
Value to enqueue:40


----MENU----

1.Enqueue 
2.Dequeue
3.Display
4.Exit
3
----------------------
20 30 40 
----------------------


----MENU----

1.Enqueue 
2.Dequeue
3.Display
4.Exit
4

*/