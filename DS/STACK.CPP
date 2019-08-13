#include<iostream.h>
#include<conio.h>
#include<process.h>
class stack
{
private:  int a[10],size,top;
public:
	 stack(int n)
	 {
	   size=n;
	   top=-1;
	}
      void operator+(int );
      void operator-();
      friend ostream &operator<<(ostream &,stack);
};

void stack::operator+(int x)
{
 if (top==size-1)
 {
 cout<<"stack is full"<<endl;
 }
 else
 top++;
 a[top]=x;
}

void stack::operator-()
{
if(top==-1)
{
 cout<<"stack is empty" <<endl;
}
else
cout<<"the deleted element is" <<a[top];
top--;
}


ostream &operator<<(ostream &out, stack s1)
{ int i;
  if (s1.top==-1)
  {
  cout <<"stack is empty" <<endl;
  }
  else
  {
  for(i=s1.top;i>=0;i--)
  cout<<s1.a[i]<<endl;
  }
  return out;
}


void main()
{
int ch,x;
stack s1(30);
clrscr();
while(1)
{
   cout<<"enter the choice" <<endl;
   cout<<"\n 1.push \n 2.pop \n 3. display \n 4.exit"<<endl;
   cin>>ch;
   switch(ch)
   {
   case 1:
       cout<<"enter the element to be inserted"<<endl;
       cin>>x;
       s1 +x;
       break;
   case 2 :
       -s1;
       break;
   case 3 :
	cout<<"stack contains " <<s1;
	break;
  case 4 : exit(0);
	  break;
   default: cout<<"invalid choice"<<endl;
    }
   }
   getch();
 }
