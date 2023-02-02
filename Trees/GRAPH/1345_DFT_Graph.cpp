/*
	Name: Shubham Sarang
	Roll no: 1345
	Unit: Graph
	Program: DFT
*/

#include<iostream>
#include<conio.h>
#define MAX 20
using namespace std;

// Stack template
class Stack
{
	int a[MAX];
	int tos;
	public:
		Stack()
		{
			tos = -1;	
		}	
		void Push(int x);
		int Pop();
		bool isEmpty();
};

void Stack::Push(int x)
{
	tos++;
	if(tos > MAX-1)
	{
		cout<<"Stack overflow";
		return;
	}
	a[tos] = x;
}

int Stack::Pop()
{
	int x = a[tos];
	tos--;
	return x;
}

bool Stack::isEmpty()
{
	return((tos == -1)?true:false);
}
//Stack end

class Graph
{
	int adj[MAX][MAX];
	int n;
	int e;
	int visited[MAX];
		public:
		Graph()
		{
			int i,j;
			for(i=0;i<MAX;i++)
			{
				for(j=0;j<MAX;j++)
				{
					adj[i][j] = 0;
				}
			}
			n=0;
			e=0;
		}	
		void CreateGraph();
		void Display();
		void DFT(int x);
};

void Graph::CreateGraph()
{
	cout<<"Enter number of nodes: ";
	cin>>n;
	
	cout<<"Enter number of edges: ";
	cin>>e;
	
	int i, source, dest;
	
	for(i=1; i<=e; i++)
	{
		cout<<"Enter edge: "<<i<<endl;
		
		cout<<"Enter source node: ";
		cin>>source;
		
		cout<<"Enter destination node: ";
		cin>>dest;
		
		adj[source][dest] = 1;
		adj[dest][source] = 1;	
		
		cout<<endl;
	} 
}

void Graph::Display()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
}

void Graph::DFT(int x)
{
	int i;
	Stack s;
	//initialize visited flag
	for(i=0;i<n;i++)
	{
		visited[i] = 0;
	}
	s.Push(x);
	visited[x] = 1;
	
	while(!s.isEmpty())
	{
		x = s.Pop();
		cout<<x<<" ";
		for(i=0; i<n; i++)
		{
			if(adj[x][i] == 1 && visited[i] == 0) //check if there is an edge
			{
				s.Push(i);
				visited[i] = 1;
			}
		}//end for
	}//end while
}

int main()
{
	int ch, num;
	Graph g;
	while(1)
	{
		system("cls");
		cout<<"***GRAPH*** \n\n";
		
		cout<<"1. Create graph \n";
		cout<<"2. Display \n";
		cout<<"3. Depth First Traversal \n";
		cout<<"4. Exit \n";
		
		cout<<"Enter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"Create graph: ";
				g.CreateGraph();
				getch();
				break;
			case 2:
				cout<<"Display: \n ";
				g.Display();
				getch();
				break;
			case 3:
				cout<<"Enter node: ";
				cin>>num;
				g.DFT(num);
				getch();
				break;
			case 4:
				exit(1);
				break;
			default:
				cout<<"Wrong opt bruv";
				getch();
				break;		
		}//end switch
	}//end while
}//end main
