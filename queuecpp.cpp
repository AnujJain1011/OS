#include <iostream>
using namespace std;

class Q
{
	private:
	int front,rear;
	public:
	int Queue[2];
	Q() 
	{
	   front=-1,rear=-1;
    }
    bool isFull()
   { 
 	 if(rear == 1)
 	 return true;
 	 else
 	 return false;
   }
   void Enqueue() 
   {
   if (isFull())
   cout<<"Queue Overflow"<<endl;
   else {
   	     int val;
         cout<<"Enter the element to insert: "<<endl;
         cin>>val;
      if (front == - 1)
      front = 0;
      rear++;
      Queue[rear]=val;
    }
   }
   bool isEmpty()
   {
   	if(front == -1 ||front > rear)
   	return true;
   	else
   	return false;
   }
   int Dequeue() 
   {
    if (isEmpty()) 
    cout<<"Queue Underflow ";
    else 
	{
      cout<<"Element deleted from queue is : ";
      return Queue[front++];
    }
    return 0;
   }
   void Display() 
   {
    if (front == - 1)
    cout<<"Queue is empty"<<endl;
    else 
	{
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
      cout<<Queue[i]<<" ";
         cout<<endl;
    }
  }
};
int main() 
{
	Q q;
   int ch;
   cout<<"1) Insert element in the Queue"<<endl;
   cout<<"2) Delete element from the Queue"<<endl;
   cout<<"3) Display all the elements of Queue"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) 
	  {
         case 1: 
         {
                 q.Enqueue();
                 break;
		 }
         case 2: 
		 {
		 	int val=q.Dequeue();
		 	cout<<val<<endl;
		 	break;
		 }
         case 3: 
         {
         	q.Display();
            break;
		 }
         case 4: 
         {
         	cout<<"Exit 32"<<endl;
            break;
		 }
         default: 
		 cout<<"Wrong choice"<<endl;
      }
   } while(ch!=4);
   return 0;
}