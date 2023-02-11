/*
	Name: Shubham Sarang
	Roll no: 1345
	Unit 4: Queues
	Program: Priority Queue
*/

#include<iostream>
#include<conio.h>

using namespace std;

//1. Node template
class PNode
{
	public:
		int data;
		int priority;
		PNode *next;
};

//2. Queue template

class PQueue
{
	PNode *front;
	public:
		PQueue()
		{
			front = NULL;
		}
		void Enqueue(int x, int p);
		void Dqueue();
		void PeekFront();
		void PeekRear();
		void Display();
};

//3. Functions

void PQueue::Enqueue(int x, int p)
{
	PNode *t = new PNode();
	t->data = x;
	t->priority = p;
	t->next = NULL;
	
	//first node
	if(front == NULL)
	{
		front = t;
		return;
	}
	//Traverse in order
	PNode *tmp = front;
	PNode *prev = NULL;
	
	while(tmp != NULL && tmp->priority < t->priority)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	
	//Insert t at the correct position in the queue
	
	if(tmp == front) //Front node Insertion 
	{
		t->next = front;
		front = t;
	}
	else if(tmp == NULL) //Last node insertion
	{
		prev->next = t;
	}
	else
	{
		prev->next = t;
		t->next = tmp;
	}
}

void PQueue::Dqueue()
{
	PNode *tmp = front;
	if(front->next == NULL)
	{
		front == NULL;
	}
	else
	{
		front = front->next;
	}
	cout<<"Element "<<tmp->data<<" dequeued with priority "<<tmp->priority;
	delete tmp;
}

void PQueue::PeekFront()
{
	PNode *tmp = front;
	cout<<"Element at the front is "<<tmp->data<<" with priority "<<tmp->priority;
}

void PQueue::PeekRear()
{
	PNode *tmp = front;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	cout<<"Element at the front is "<<tmp->data<<" with priority "<<tmp->priority;
}

void PQueue::Display()
{
	if(front == NULL)
	{
		cout<<"Empty Queue";
		return;
	}
	PNode *tmp = front;
	cout<<"Data | Priority \n";
	
	while(tmp != NULL)
	{
		cout<<tmp->data<<" | "<<tmp->priority<<"\n";
		tmp = tmp->next;
	}
}

//4. Menu

int main()
{
	int ch, num, pri;
	PQueue p;
	
	while(1)
	{
		system("cls");
		cout<<"***Priority Queue*** \n\n";
		
		cout<<"1. Enqueue \n";
		cout<<"2. Dequeue \n";
		cout<<"3. Peek front \n";
		cout<<"4. Peek rear \n";
		cout<<"5. Display queue \n";
		cout<<"6. Exit \n";
		
		cout<<"Enter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"Enqueue element: ";
				cin>>num;
				cout<<"Enter priority: ";
				cin>>pri;
				p.Enqueue(num,pri);
				getch();
				break;
			case 2:
				cout<<"Dequeue element: ";
				p.Dqueue();
				getch();
				break;
			case 3:
				cout<<"Peek front: ";
				p.PeekFront();
				getch();
				break;
			case 4:
				cout<<"Peek rear: ";
				p.PeekRear();
				getch();
				break;
			case 5:
				cout<<"Display queue: \n";
				p.Display();
				getch();
				break;
			case 6:
				exit(1);
				break;
			default:
				cout<<"Wrong opt bruv";
				getch();
				break;		
		}//end switch
	}//end while
}//end main
