/*
Name: Shubham Sarang
Roll no: 1345
Unit 3:Stacks
Program: List based Stack
*/

#include<iostream>
#include<conio.h>
using namespace std;

class SNode
{
	public:
		int data;
		SNode *next;	
};

class LStack
{	
	SNode *tos;
	public:
		LStack()
		{
			tos = NULL; 
		}
		void Push(int x);
		void Pop();
		void Peek();
		void Display();
};

void LStack::Push(int x)
{
	SNode *t = new SNode();
	t->data = x;
	t->next = NULL;
	if(tos == NULL)
	{
		tos = t;
	}
	else
	{
		t->next = tos;
		tos = t;	
	}
}
void LStack::Pop()
{
	if(tos == NULL)
	{
		cout<<"Empty stack";
		return;
	}
	SNode *tmp = tos;
	cout<<tmp->data<<" popped";
	tos = tos->next;
	delete tmp;
}

void LStack::Peek()
{
	if(tos == NULL)
	{
		cout<<"Empty Stack";
		return;
	}
	cout<<"Element at the top of stack: "<<tos->data;
}

void LStack::Display()
{
	SNode *cnt = tos;
	if(tos == NULL)
	{
		cout<<"Empty Stack";
		return;
	}
	while(cnt != NULL)
	{
		cout<<cnt->data<<"\n";
		cnt = cnt->next;	
	} 
}

int main()
{
	int ch, num;
	LStack l;
	while(1)
	{
		system("cls");
		
		cout<<"****List Based Stack***"<<endl;
		
		cout<<"1. Push an element in stack \n";
		cout<<"2. Pop an element in stack \n";
		cout<<"3. Peek stack \n";
		cout<<"4. Display stack \n";
		cout<<"5. Exit \n";
		
		cout<<"Enter choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1: 
				cout<<"Push element: ";
				cin>>num;
				l.Push(num);
				getch();
				break;
			case 2: 
				cout<<"Pop element: ";
				l.Pop();
				getch();
				break;
			case 3: 
				cout<<"Peek element: ";
				l.Peek();
				getch();
				break;
			case 4: 
				cout<<"Display stack: \n";
				l.Display();
				getch();
				break;
			case 5: 
				exit(1);
			default:
				cout<<"Wrong choice bruv";
				getch();
		}
	} 
}

