#include<stdio.h>
#define MAX 5
#include<conio.h>

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
		printf("\n%d has been PUSHED.\n", val);
		}
	else
		printf("\nStack is FULL\n");

	Display();
	}


void Pop(){
	if(isEmpty() == 1)
		printf("\nStack is EMPTY\n");
	else{
		printf("\n%d has been POPPED.\n", stk[top]);
		top--;
		}

	Display();
	}


int main(){
	int c;
	clrscr();
	do{
		printf("1.Push \n2.Pop \n5.Exit\nChoice:");
		scanf("%d", &c);
		switch(c){
			case 1:
				Push();
				break;
			case 2:
				Pop();
				break;
			case 5:
				exit(0);
			default:
				printf("\nWrong Choice\n");
			}
		}while(c !=5);
	getch();
	return 0;
	}
