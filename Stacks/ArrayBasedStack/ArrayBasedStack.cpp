/*
Name: Shubham Sarang
Roll no: 1345
Unit 3:Stacks
Program: Array based Stack
*/
#include<iostream>
#include<conio.h>
#define MAX 5

using namespace std;

//1. Node template NOT REQUIRED

//2. Stack template
class AStack
{
	int a[MAX];
	int tos;
	public:
		AStack()
		{
			tos = -1;
		}
		void Push(int x);
		void Pop();
		void Peek();
		void Display();
		int Full();
		int Empty();
};

//3. Functions
void AStack::Push(int x)
{
	if(Full())
	{
		cout<<"Stack overflow!!!";
	}
	else
	{
		tos++;
		a[tos] = x; 
	}
}

void AStack::Pop()
{
	if(Empty())
	{
		cout<<"Stack underflow!!!";
	}
	else
	{
		cout<<a[tos]<<" popped";
		tos--;		
	}
	Display();
}

void AStack::Peek()
{
	cout<<" Element at the top of the stack: "<<a[tos];
} 

void AStack::Display()
{
	int cnt = tos;
	while(cnt!= -1)
	{
		cout<<"\n"<<a[cnt]<<"\n";
		cnt--;
	}
}

int AStack::Full()
{
	if(tos == MAX-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int AStack::Empty()
{
	if(tos == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//4.MENU

int main()
{
	int ch, num;
	AStack s;
	while(1)
	{
		system("cls");
		
		cout<<"****Array Based Stack***"<<endl;
		
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
				s.Push(num);
				getch();
				break;
			case 2: 
				cout<<"Pop element: ";
				s.Pop();
				getch();
				break;
			case 3: 
				cout<<"Peek element: ";
				s.Peek();
				getch();
				break;
			case 4: 
				cout<<"Display stack: ";
				s.Display();
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

