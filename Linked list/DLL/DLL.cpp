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
	if(head == NULL)
	{
		cout<<"Empty list";
		return;
	}
	
	DNode *tmp = head; 
	cout<<"Forward Direction: ";
	while( tmp!= NULL)
	{
		cout<<tmp->data<<"<->";
		tmp = tmp->right;
	}
	cout<<"End of list"<<endl;
	tmp = tail;
	cout<<"Reverse Direction: ";
	while( tmp!= NULL)
	{
		cout<<tmp->data<<"<->";
		tmp = tmp->left;
	}
	cout<<"Start of list"<<endl;
}

void DList::Length()
{
	int count=0;
	if(head == NULL)
	{
		cout<<"Empty list";
		return;
	}
	
	DNode *tmp = head;
	while( tmp!= NULL)
	{
		count++;
		tmp = tmp->right;
	}
	cout<<"Length of list: "<<count;
}

void DList::Search(int x)
{
	if(head == NULL)
	{
		cout<<"Empty list";
		return;
	}
	int flag = 0;
	DNode *tmp = head;
	while(tmp!=NULL)
	{
		if(tmp->data==x)
		{
			flag=1;
			break;
		}
		tmp=tmp->right;
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

void DList::Remove(int x)
{
	if(head == NULL)
	{
		cout<<"Empty list";
		return;
	}
	DNode *tmp = head;
	DNode *prev = NULL;
	int flag = 0;
	while(tmp!=NULL)
	{
		if(tmp->data == x)
		{
			flag = 1;
			break;	
		}
		prev = tmp;
		tmp = tmp->right;
	}
	//step 3: unsuccessfull search return control
	if(flag==0)
	{
		cout<<"Element "<<x<<" not found ";
		return;
	}
	
	//Step 4: Successful search, a single node deletion
	if(head == tail)
	{
		head = NULL;
		tail = NULL;
	}
	else if(tmp==head) //step 4 b: head node deletion
	{
		head = tmp->right;
		head->left = NULL;	
	}
	else if(tmp == tail) //step4 c: tail node deletion
	{
		tail = prev;
		tail->right = NULL; 
	}
	else //Step 4 d: any node in the middle
	{
		prev->right = tmp->right;
		(tmp->right)->left = prev;
	}
    //Step 5: delete the node containing x
    delete tmp;
    cout<<"Element deleted ";
}
//Functions

//Menu

int main()
{
	int ch, x, y,z, num;
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
					d.Display();
					getch();
					break;
			case 3:
					cout<<"Length of the list is: ";
					d.Length();
					getch();
					break;
			case 4:
					cout<<"Enter the element to be searched: ";
					cin>>y;
					d.Search(y);
					getch();
					break;
			case 5:
					cout<<"Enter the element to be removed: ";
					cin>>z;
					d.Remove(z);
					d.Display();
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
