/*
	Name: Shubham Sarang
	Roll no: 1345
	Unit 4: Queue
	Program: Ordinary Queue
*/

#include<iostream>
#include<conio.h>
#define MAX 5 

using namespace std;

// Queue template

class OQueue
{
	int front, rear, a[MAX];
	public:
		OQueue()
		{
			front = -1;
			rear = -1;	
		}	
		void Enqueue(int x);
		void Dequeue();
		void PeekFront();
		void PeekRear();
		void Display();
		int Full();
		int Empty();
};

//Functions

void OQueue::Enqueue(int x)
{
	if(Full())
	{
		cout<<"Queue Overflow!!";
		return;
	}
	if(front == -1)
	{
		front++;
	}
	rear++;
	a[rear]=x;
}

void OQueue::Dequeue()
{
	if(Empty())
	{
		cout<<"Queue underflow!!";
		return;
	}
	int tmp = a[front];
	
	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		front++;
	}
	cout<<"Element "<<tmp<<" dequeued";
}

int OQueue::Full()
{
	int result = rear == MAX-1 ? 1:0;
	return result;
}

int OQueue::Empty()
{
	int result = rear == -1 ? 1:0;
	return result;
}

void OQueue::PeekFront()
{
	if(Empty())
	{
		cout<<"Queue underflow!!";
		return;
	}
	cout<<"Element at the front: "<<a[front];
}

void OQueue::PeekRear()
{
	if(Empty())
	{
		cout<<"Queue underflow!!";
		return;
	}
	cout<<"Element at the rear: "<<a[rear];	
}

void OQueue::Display()
{
	if(Empty())
	{
		cout<<"Queue underflow!!";
		return;
	}
	
	cout<<"Queue: \n";
	for(int i=front; i<=rear; i++)
	{
		cout<<a[i]<<"\n";
	}
}

//Menu

int main()
{
	OQueue o;
	int num, ch;
	while(1)
	{
		system("cls");
		cout<<"***Ordinary Queue***\n\n";
		cout<<"1. Perfrom Enqueue on queue\n";
		cout<<"2. Perfrom Dequeue on queue\n";
		cout<<"3. PeekFront of queue\n";
		cout<<"4. PeekRear of queue\n";
		cout<<"5. Display queue\n";
		cout<<"6. Exit\n\n";
		cout<<"Enter the choice you've made: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Add Element: ";
				cin>>num;
				o.Enqueue(num);
				getch();
				break;
			case 2:
				o.Dequeue();
				getch();
				break;
			case 3:
				o.PeekFront();
				getch();
				break;
			case 4:
				o.PeekRear();
				getch();
				break;
			case 5:
				o.Display();
				getch();
				break;
			case 6:
				exit(1);
			default:
				cout<<"Wrong option bruv";
				getch();
				break;
		}
	}
}
