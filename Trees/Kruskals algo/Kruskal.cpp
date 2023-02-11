/*
	Name: Shubham Sarang
	Roll no: 1345
	Unit: Graph
	Program: Kruskals
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
					adj[i][j] = 0;
				}
			}
			for(i = 0; i<MAX; i++)
			{
				parent[i] = -1;
			}
			n=0;
			e=0;
		}	
		void CreateGraph();
		void Display();
		void Kruskals();
		int Find(int i);
		int Union(int i, int j);
};

void Graph::CreateGraph()
{
	cout<<"Enter number of nodes: ";
	cin>>n;
	
	cout<<"Enter number of edges: ";
	cin>>e;
	
	int i, source, dest, weight;
	
	for(i=1; i<=e; i++)
	{
		cout<<"Enter edge: "<<i<<endl;
		
		cout<<"Enter source node: ";
		cin>>source;
		
		cout<<"Enter destination node: ";
		cin>>dest;
		
		cout<<"Enter weight of edge: ";
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
			if(adj[i][j] == INF)
			{
				cout<< "0";
			}
			else
			{
				cout<<adj[i][j]<<" ";	
			}
		}
		cout<<endl;
	}
}

void Graph::Kruskals()
{
	int minimum, i,j,ne =1;
	int a,b,u,v;
	int mincost = 0;
	while(ne<n)
	{
		for(i=0,minimum=999; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(adj[i][j] < minimum)
				{
					minimum = adj[i][j];
					a = u = i;
					b = v = j;
				}//end if
			}//end for j
		}//end for i
		u = Find(u);
		v = Find(v);
		
		if(Union(u,v))
		{
			cout<<"Edge: ("<< a << ", "<< b <<")" <<" = "<<adj[a][b]<<endl;
			mincost += minimum;
			ne++;
		}
		adj[a][b] = adj[b][a] = INF;
	}//end while
	cout<<"MST total cost: "<<mincost;
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

int main()
{
	int ch;
	Graph g;
	while(1)
	{
		system("cls");
		cout<<"***MST using Kruskal algorithm*** \n\n";
		
		cout<<"1. Create graph \n";
		cout<<"2. Display \n";
		cout<<"3. Find the MST using Kruskals algorithm \n";
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
				cout<<"";
				g.Display();
				getch();
				break;
			case 3:
				cout<<"Kruskals: \n ";
//				g.Kruskals();
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
