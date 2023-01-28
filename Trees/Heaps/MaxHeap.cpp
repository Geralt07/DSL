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


//4. Menu 
int main()
{
	int ch;
	while(1)
	{
		system("cls");
		cout<<"***HEAPS*** \n\n";
		
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
				getch();
				break;
			case 2:
				cout<<"";
				getch();
				break;
			case 3:
				cout<<"";
				getch();
				break;
			case 4:
				cout<<"Search: ";
				getch();
				break;
			case 5:
				cout<<"Max: \n";
				getch();
				break;
			case 6:
				cout<<"Min: \n";
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
