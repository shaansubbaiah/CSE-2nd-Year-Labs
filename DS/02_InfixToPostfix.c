/*
 *  --- Program to convert expressions from INFIX to POSTFIX ---
 */
#include<stdio.h>
#include<ctype.h>

int getPriority(char var){
  if(var == '/' || var == '*')
    return 2;
  else if(var == '+' || var == '-')
    return 1;
  else
    return 0;
}

void pushPostfix(char *postfix, char *stack, int topStack, int topPostfix){
  (topPostfix)++;
  *(postfix + topPostfix) = *(stack + topStack);
  (topStack)--;
}

void Push(char *stack, char var, int topStack){
  (topStack)++;
  *(stack + topStack) = var;
}

int main(){
  char infix[30], postfix[30], stack[30];
  int topStack = -1, topPostfix = -1; 
  char c;
  printf("Enter Infix Expression:");
  scanf("%s", infix);
  for(int i=0; infix[i]!='\0'; i++){
    c = infix[i];
    
    // if '(' or higer priority operator, push to stack
    if(c=='(' || getPriority(c)<getPriority(topStack) )
      Push(stack, c, topStack);
    
    // if ')' keep pushing to postfix till it reaches '('
    else if(c==')'){
      while(*(stack + topStack) != '(')
        pushPostfix(postfix, stack, topStack, topPostfix);
      --(topStack);
    }
    
    // if alpha numeric, push to postfix
    else if(isdigit(c) || isalpha(c)){
      topPostfix++;
      *(postfix + topPostfix) = c;
    }

    // if operator, keep pushing to postfix while operator >= top of stack
    // push that operator to stack
    else{
      while(getPriority(c)>=getPriority(topStack)){
        pushPostfix(postfix, stack, topStack, topPostfix);      
      }
      Push(stack, c, topStack);
    }
  }

  while(topStack != -1){
    pushPostfix(postfix, stack, topStack, topPostfix);
        --(topStack);
  }

  printf("%s\n", postfix);

  return 0;
}

/* ------ OUTPUT ------
Enter Infix Expression:a+b+(c/d)
ab+cd/+
*/