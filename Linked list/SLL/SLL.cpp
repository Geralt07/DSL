/*
Name: Shubham Sarang
Roll no: 1345 
Unit 5: Linked list 
Program: Singly Linked List
*/

#include<iostream>
#include<conio.h>
using namespace std;

//Node template
class Node
{
	public:
		int data;
		Node *next;
};

//List tempate
class SList
{
	Node *head;
	
	public:
		SList()
		{
			head=NULL;
		}
		void Insert(int x);
		void Display();
		void Length();
		void Search(int x);
		void Remove(int x); 
		void Reverse();
};
// Functions
void SList :: Insert(int x)
{
	//create node t
	Node *t= new Node();
	t->data=x;
	t->next = NULL;

	//first node in the list
	if(head == NULL)
	{
		head = t;
		return;
	}
	
	//traverse till last node
	Node *tmp = head;
	
	while(tmp->next != NULL)
	{
		tmp= tmp->next;
	}
	//attach t to the last node tmp
	tmp->next = t;
}
void SList :: Display()
{
	Node *tmp = head;
	while(tmp!=NULL)
	{
		cout<<tmp->data<<"->";
		tmp = tmp->next;
	}
	cout<<"End of list";
}

void SList :: Length()
{
	Node *tmp = head;
	int count=0;
	while(tmp!=NULL)
	{
		count++;
		tmp = tmp->next;
	}
	cout<<"Number of elements in list is "<<count;
}

void SList :: Search(int x)
{
	Node *tmp=head;
	int flag=0;
	
	while(tmp!=NULL)
	{
		if(tmp->data==x)
		{
			flag=1;
			break;
		}
		tmp=tmp->next;
	}
	
	if(flag==1)
	{
		cout<<"Element "<<x<<" found";
	}
	else
	{
		cout<<"Element "<<x<<" not found";
	}
}

void SList :: Remove(int x)
{
	//Step 1:List in empty return control
	if(head==NULL)
	{
		cout<<"LIST IS EMPTY";
		return;
	}
	//Step 2: Search element
	Node *tmp = head;
	Node *prev = NULL;
	int flag = 0;
	
	while(tmp!=NULL)
	{
		if(tmp->data == x)
		{
			flag = 1;
			break;	
		}
		prev = tmp;
		tmp = tmp->next;
	}
	
	//step 3: unsuccessfull search return control
	if(flag==0)
	{
		cout<<"Element "<<x<<" not found ";
		return;
	}
	
	//Step 4: Successful search, a single node deletion
	if(tmp == head && tmp->next == NULL)
	{
		head = NULL;
	}
	else if(tmp==head) //step 4 b: head node deletion
	{
		head = tmp->next;	
	}
	else if(tmp->next == NULL) //step4 c: tail node deletion
	{
		prev->next = NULL; 
	}
	else //Step 4 d: any node in the middle
	{
		prev->next = tmp->next;
	}
    //Step 5: delete the node containing x
    delete tmp;
    cout<<"Element deleted ";
}

void SList::Reverse()
{
	Node *tmp = head;
	Node *revHead = NULL;
	
	while(tmp!=NULL)
	{
		//Make new node
		Node *r = new Node();
		r->data = tmp->data;
		r->next = revHead; //for the first node revhead is already null
		
		//set Revhead
		revHead = r;
		
		//advance tmp
		tmp = tmp->next;
		
	}//end while
	head = revHead;
}
//Menu 

int main()
{
	int ch, num, y;
	SList s;
	while(1)
	{
		system("cls");
		cout<<"**Singly linked list**"<<endl;
		cout<<"1. Insert in SLL\n";
		cout<<"2. Display List\n";
		cout<<"3. Length of SLL\n";
		cout<<"4. Search for the node in SLL\n";
		cout<<"5. Remove a node\n";
		cout<<"6. Reverse the list \n";
		cout<<"7. Exit\n\n";	
		
		cout<<"Enter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
					cout<<"Enter the data: ";
					cin>>num;
					s.Insert(num);
					getch();
					break;
			case 2:
					s.Display();
					getch();
					break;
			case 3:
					s.Length();
					getch();
					break;
			case 4:
					cout<<"Enter the element to be searched: ";
					cin>>y;
					s.Search(y);
					getch();
					break;
			case 5:
					cout<<"Enter the element to be removed: ";
					cin>>y;
					s.Remove(y);
					s.Display();
					getch();
					break;
			case 6:
					cout<<"Reverse: ";
					s.Reverse();
					s.Display();
					getch();
					break;
			case 7:
					exit(1);
			default:
					cout<<"Incorrect option";
					getch();	
		}//end of switch
			
		
	}//end while
	
}//end main
