/*
 *  ---------- Program to demonstrate STACKS ----------
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int top = -1;
int i;
int stk[MAX];

int isEmpty(){
	if(top == -1)
		return 1;
	else
		return 0;
	}


int isFull(){
	if(top == MAX-1)
		return 1;
	else
		return 0;
	}


void Display(){
	if(isEmpty() == 0){
		for(i=0; i<=top; i++)
				printf("%d ",stk[i]);
		printf("\n");
		}
	else
		printf("\nStack is EMPTY\n");
	}


void Push(){
	int val;
	if(isFull() == 0){
		top++;
		printf("\nEnter value to push:");
		scanf("%d", &val);
		stk[top] = val;
		printf("\n%d has been PUSHED.\n\n", val);
		}
	else
		printf("\nStack is FULL\n");

	Display();
	}


void Pop(){
	if(isEmpty() == 1)
		printf("\nStack is EMPTY\n");
	else{
		printf("\n%d has been POPPED.\n\n", stk[top]);
		top--;
		}

	Display();
	}


int main(){
	int c=1;
	do{
		printf("\n1.Push \n2.Pop \n0.Exit\nChoice:");
		scanf("%d", &c);
		switch(c){
			case 1:
				Push();
				break;
			case 2:
				Pop();
				break;
			case 0:
				exit(1);
			default:
				printf("\nWrong Choice\n");
			}
		}while(c != 0);
	return 0;
	}

/* ------ OUTPUT ------

1.Push
2.Pop
0.Exit
Choice:1

Enter value to push:4

4 has been PUSHED.

4

1.Push
2.Pop
0.Exit
Choice:1

Enter value to push:5

5 has been PUSHED.

4 5

1.Push
2.Pop
0.Exit
Choice:1

Enter value to push:6

6 has been PUSHED.

4 5 6

1.Push
2.Pop
0.Exit
Choice:2

6 has been POPPED.

4 5

1.Push
2.Pop
0.Exit
Choice:0
exit status 1
 
*/
