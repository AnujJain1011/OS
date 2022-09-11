#include<iostream>
using namespace std;

class S
{
		int top;
	public:
		int stack[100];
		S() { top=-1; }
 bool isFull()
{
	if(top >= 99)
	return true;
	else
	return false;
}
void push(int val)
{
	if(isFull())
	cout<<"Stack Overflow"<<endl;
	else
	{
	 top++;
	 stack[top]=val;
    }
}
bool isEmpty()
{
	if(top == -1)
	return true;
	else
	return false;
}
int pop()
{
	if(isEmpty())
	cout<<"Stack Underflow"<<endl;
    else	
    {
    	cout<<"Popped element is:";
    	return stack[top--];
	}
	return 0;
}
void display() 
{
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty"<<endl;
}
};

int main()
{
	S s;
	int ch, val;
   cout<<"1) Push element in Stack"<<endl;
   cout<<"2) Pop element from stack"<<endl;
   cout<<"3) Display all elements of stack"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter your choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            s.push(val);
            break;
         }
         case 2: {
            int v=s.pop();
            cout<<v<<endl;
            break;
         }
         case 3: {
            s.display();
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Wrong Choice"<<endl;
         }
      }
   }while(ch!=4);
	return 0;
}