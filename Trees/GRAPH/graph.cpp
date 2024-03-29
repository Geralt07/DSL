/*
	Name: Shubham Sarang
	Roll no: 1345
	Unit: Graph
	Program: Adjacency matrix
*/

#include<iostream>
#include<conio.h>
#define MAX 20

using namespace std;
class Graph
{
	int adj[MAX][MAX];
	int n;
	int e;
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


int main()
{
	int ch;
	Graph g;
	while(1)
	{
		system("cls");
		cout<<"***GRAPH*** \n\n";
		
		cout<<"1. Create graph \n";
		cout<<"2. Display \n";
		cout<<"3. Exit \n";
		
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
				exit(1);
				break;
			default:
				cout<<"Wrong opt bruv";
				getch();
				break;		
		}//end switch
	}//end while
}//end main
