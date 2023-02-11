/*
	Name: Shubham Sarang
	Roll no: 1345
	Unit 7: Graph
	Program: KRUSKAL'S Algorithm
*/

#include<iostream>
#include<conio.h>
#define MAX 20
#define INF 999

using namespace std;
class Graph
{
	int adj[MAX][MAX];
	int n;
	int e;
	int parent[MAX];
	
	public:
		Graph()
		{
			int i,j;
			for(i=0;i<MAX;i++)
			{
				for(j=0;j<MAX;j++)
				{
					adj[i][j] = INF;
				}
			}
			
			for(i=0;i<MAX;i++)
			{
				parent[i]=-1;
			}
			n=0;
			e=0;
		}	
		void CreateGraph();
		void Display();
		void Kruskal();
		int Find(int i);
		int Union(int i,int j);
};

void Graph::CreateGraph()
{
	cout<<"Enter number of nodes: ";
	cin>>n;
	
	cout<<"Enter number of edges: ";
	cin>>e;
	
	int i, source, dest,weight;
	
	for(i=1; i<=e; i++)
	{
		cout<<"Enter edge: "<<i<<endl;
		
		cout<<"Enter source node: ";
		cin>>source;
		
		cout<<"Enter destination node: ";
		cin>>dest;
		
		cout<<"Enter the weight: ";
		cin>>weight;
		
		adj[source][dest] = weight;
		adj[dest][source] = weight;	
		
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
			if(adj[i][j]==INF)
			{
				cout<<"0 ";
			}
			else
			{
				cout<<adj[i][j]<<" ";
			}
			
		}
		cout<<endl;
	}
}


void Graph :: Kruskal()
{
	int minimum,i,j,ne=1;
	int a,b,u,v;
	int mincost=0;
	
	while(ne<n)
	{
		for(i=0,minimum=999;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(adj[i][j]<minimum)
				{
					minimum=adj[i][j];
					a=u=i;
					b=v=j;
				}
			}//end of for j inner loop
		}//end of for i outer loop
		
		u=Find(u);
		v=Find(v);
		
		if(Union(u,v))
		{
			cout<<"Edge: "<< ne++ <<" (" << a << " ,"<<b<<") = "<<adj[a][b] <<endl;
			mincost+=minimum;
		}
		
		adj[a][b]=adj[b][a]=INF;
	}//end of while
	
	cout<<"MST Total Cost: " << mincost;
}
 int Graph :: Find(int i)
 {
 	while(parent[i]!=-1)
 	{
 		i=parent[i];	
	}
	return i;
 }
 
 int Graph :: Union(int i,int j)
 {
 	if(i!=j)
 	{
 		parent[j]=i;
		return 1;	
	}
 }






////////
int main()
{
	int ch;
	Graph g;
	while(1)
	{
		system("cls");
		cout<<"***MST using Kruskal's Algorithm'*** \n\n";
		
		cout<<"1. Create graph \n";
		cout<<"2. Display \n";
		cout<<"3. Find the MST using Kruskal's Algo\n";
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
				
				g.Kruskal();
				getch();
				break;	
			case 4:
				exit(1);
				break;
			default:
				cout<<"Wrong opt";
				getch();
				break;		
		}//end switch
	}//end while
}//end main

