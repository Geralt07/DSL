/*
	Name: Shubham Sarang
	Roll no: 1345
	Unit: Trees
	Program: MAX-Heap 
*/

#include<iostream>
#include<conio.h>
#define MAX 20
using namespace std;
//1. Node needed cuz array based bruv

//2. Array template
class Heap
{
	int a[MAX];
	int n; 
	public:
		Heap()	
		{
			for(int i=0; i<MAX; i++)
			{
				a[i] = 0;
			}
			n = 0;
		}
		void BuildHeap();
		void Insert(int x);
		void DeleteHeap();
		void Display();
		void reheapUp(int x);
		void reheapDown(int pos);
};

//3. Functions

void Heap::BuildHeap()
{
	cout<<"Enter number of elements: ";
	cin>>n;
	cout<<"\nEnter elements: ";
	int i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	for(i = (n/2)-1;i >= 0; i--)
	{
		reheapDown(i);
	}
	
}

void Heap::Insert(int x)
{
	a[n] = x;	//insert x at position n
	n++;	//increment number of element
	reheapUp(n-1);	//reheapup the element stored at position n-1
}

void Heap::DeleteHeap()
{
	int tmp = a[0]; 
	a[0] = a[n-1];	//copy last element at root position
	a[n-1] = 0;		//set last position to 0
	n--;	//as element is deleted, we decrement n
	cout<<"Element deleted is "<<tmp;
	reheapDown(0); //reheapdown from root
}

void Heap::reheapDown(int pos)
{
	int tmp = a[pos];
	int i;
	while(pos <= (n/2)-1)
	{
		i = 2 * pos + 1;
		if(a[i] < a[i+1] )
		{
			i++;
		}
		if(tmp > a[i])
		{
			break;
		}
		else
		{
			a[pos] = a[i];
			pos = i;
		}
	}
	a[pos] =tmp;
}

void Heap::reheapUp(int x)
{
	int tmp = a[x];
	while(a[(x-1)/2] < tmp && x>0)
	{
		a[x] = a[(x-1)/2];
		x = (x-1)/2;
	}
	a[x] = tmp;
}

void Heap::Display()
{
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
}


//4. Menu 
int main()        
{
	int ch, num;
	Heap h;
	while(1)
	{
		system("cls");
		cout<<"***HEAPS*** \n\n";
		
		cout<<"1. Build Heap \n";
		cout<<"2. Insert Heap \n";
		cout<<"3. Display \n";
		cout<<"4. Delete \n";
		cout<<"5. Exit \n";
		
		cout<<"Enter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"Build heap: ";
				h.BuildHeap();
				getch();
				break;
			case 2:
				cout<<"Insert heap: ";
				cin>>num;
				h.Insert(num);
				getch();
				break;
			case 3:
				cout<<"";
				h.Display();
				getch();
				break;
			case 4:
				cout<<"";
				h.DeleteHeap();
				getch();
				break;
			case 5:
				exit(1);
				break;
			default:
				cout<<"Wrong opt bruv";
				getch();
				break;		
		}//end switch
	}//end while
}//end main
