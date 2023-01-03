/*
Name: Shubham Sarang
Roll no: 1345
Program: Doubly Linked List 
*/
#include<iostream>
#include<conio.h>
using namespace std;
//Node template
class DNode
{
	public:
		int data;
		DNode *left;
		DNode *right;	
};
class DList
{
	DNode *head;	
	DNode *tail;
	public:
		DList()
		{
			head = NULL;
			tail = NULL;
		}
		void Insert(int x);
		void Display();
		void Length();
		void Search(int x);
		void Remove(int x);
};
//List template
void DList :: Insert(int x)
{
	DNode *t = new DNode();
	t->data = x;
	t->left = NULL;
	t->right = NULL;
	if(head == NULL)
	{
		head = t;
		tail = t;
	}
	else
	{
		tail->right = t;
		t->left = tail; 
		tail = t;
	}
}

void DList :: Display()
{
	
}
//Functions

//Menu

int main()
{
	int ch, x, num;
	DList d;
	while(1)
	{	
		system("cls");
		cout<<"**Doubly linked list**"<<endl;
		cout<<"1. Insert in DLL\n";
		cout<<"2. Display List\n";
		cout<<"3. Length of DLL\n";
		cout<<"4. Search for the node in DLL\n";
		cout<<"5. Remove a node\n";
		cout<<"6. Exit\n\n";	
		
		cout<<"Enter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
					cout<<"Enter the data: ";
					cin>>num;
					d.Insert(num);
					getch();
					break;
			case 2:
					cout<<"The list is: ";
					getch();
					break;
			case 3:
					cout<<"Length of the list is: ";
					getch();
					break;
			case 4:
					cout<<"Enter the element to be searched: ";
					getch();
					break;
			case 5:
					cout<<"Enter the element to be removed: ";
					getch();
					break;
			case 6:
					exit(1);
			default:
					cout<<"Incorrect option";
					getch();	
					break;
		}//end of switch
	}//end while	
}//end main
