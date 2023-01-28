/*
	Name: Shubham Sarang
	Roll no: 1345
	Unit: Trees
	Program: Binary search tree
*/

#include<iostream>
#include<conio.h>
using namespace std;

//1. Node template
class BSTNode
{
	public:
		int data;
		BSTNode *right;
		BSTNode *left;
};

//2. Tree template
class BST
{
	BSTNode *root;
	int cnt;
	public:
		BST()
		{
			root = NULL;
			cnt = 0;
		}	
		void Insert(int x);
		void Display();
		void Count();
		void Inorder(BSTNode *t);
		void Preorder(BSTNode *t);
		void Postorder(BSTNode *t);
		void Search(int x);
		void FindMax();
		void FindMin();
};

//3. Functions
void BST::Insert(int x)
{
	//make a new node t
	BSTNode *t = new BSTNode();
	t->data = x;
	t->left = NULL; 
	t->right = NULL;
	
	//first node
	if(root == NULL)
	{
		root = t;
		cnt++;
		return;	
	}	
	
	BSTNode *tmp = root;
	BSTNode *prev = NULL;
	
	while(tmp!=NULL)
	{
		prev = tmp;
		
		if(t->data<tmp->data)
		{
			tmp = tmp->left;
		}
		
		else if(t->data>tmp->data)
		{
			tmp = tmp->right;
		}
		else
		{
			cout<<"Don't put same values bruv \n";
			cout<<"come onnn";
			return;
		}
	}//end of while
	
	//attach t
	if(t->data < prev->data)
	{
		prev->left = t;
	}
	else
	{
		prev->right = t;
	}
	cnt++;
}

void BST::Display()
{
	if(root == NULL)
	{
		cout<<"Empty Tree bruv";
		return;
	}
	cout<<"Inorder traversal: "; 
	Inorder(root);
	
	cout<<endl;
	cout<<"Preorder traversal: "; 
	Preorder(root);
	
	cout<<endl;
	cout<<"Postorder traversal: "; 
	Postorder(root);
}

void BST::Inorder(BSTNode *t)
{
	if(t!=NULL)
	{
		Inorder(t->left);
		cout<<t->data<<" ";
		Inorder(t->right);	
	}
}

void BST::Preorder(BSTNode *t)
{
	if(t!=NULL)
	{
		cout<<t->data<<" ";
		Preorder(t->left);
		Preorder(t->right);
	}
}
	
void BST::Postorder(BSTNode *t)
{
	if(t)
	{
		Postorder(t->left);
		Postorder(t->right);
		cout<<t->data<<" ";
	}
}

void BST::Count()
{
	cout<<"Number of nodes in da tree "<<cnt;
}

void BST::FindMin()
{
	if(root == NULL)
	{
		cout<<"Empty Tree bruv";
		return;
	}
	BSTNode *tmp = root;
	
	while(tmp->left != NULL)
	{
		tmp = tmp->left;
	}
	cout<<"Minimum value is "<<tmp->data;
}

void BST::FindMax()
{
	if(root == NULL)
	{
		cout<<"Empty Tree bruv";
		return;
	}
	BSTNode *tmp = root;
	
	while(tmp->right != NULL)
	{
		tmp = tmp->right;
	}
	cout<<"Maximum value is "<<tmp->data;
}

void BST::Search(int x)
{
	if(root == NULL)
	{
		cout<<"Empty Tree bruv";
		return;
	}
	BSTNode *tmp = root;
	int flag = 0;
	while(tmp != NULL)
	{
		if(x < tmp->data)
		{
			tmp = tmp->left;
		}	
		else if(x > tmp->data)
		{
			tmp = tmp->right;
		}	
		else
		{
			flag = 1;
			break;
		}
	}
	if(flag == 1)
	{
		cout<<"Element found "<<tmp->data;	
	}
	else
	{
		cout<<"Element not found ";	
	}
}
//4. Menu

int main()
{
	int ch, num, y;
	BST b;
	while(1)
	{
		system("cls");
		cout<<"***Binary Search Tree*** \n\n";
		
		cout<<"1. Insert \n";
		cout<<"2. Display \n";
		cout<<"3. Count \n";
		cout<<"4. Search \n";
		cout<<"5. Find max \n";
		cout<<"6. Find min \n";
		cout<<"7. Exit \n";
		
		cout<<"Enter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"Insert: ";
				cin>>num;
				b.Insert(num);
				getch();
				break;
			case 2:
				cout<<"";
				b.Display();
				getch();
				break;
			case 3:
				cout<<"";
				b.Count();
				getch();
				break;
			case 4:
				cout<<"Search: ";
				cin>>y;
				b.Search(y);
				getch();
				break;
			case 5:
				cout<<"Max: \n";
				b.FindMax();
				getch();
				break;
			case 6:
				cout<<"Min: \n";
				b.FindMin();
				getch();
				break;				
			case 7:
				exit(1);
				break;
			default:
				cout<<"Wrong opt bruv";
				getch();
				break;		
		}//end switch
	}//end while
}//end main
