/*
	Name: Shubham Sarang
	Roll no: 1345
	Unit 2: Searching
	Program: HASHING Algorithm
*/
#include<iostream>
#include<conio.h>
#define SIZE 10
#define EMPTY -1

using namespace std;

int h[SIZE];

//Initialize array
void Init()
{
	int i;
	for(i=0; i<SIZE; i++)
	{
		h[i] = EMPTY;
	}
}

//insert key

void Insert(int key)
{
	int addr = key % SIZE; //modulo division
	if(h[addr]==EMPTY) 	//space available at addr
	{
		h[addr] = key;
		cout<<key<<" is inserted at "<<addr<<endl;
	}
	else 	//addr is occupied, linear probe
	{
		do
		{
			addr = (addr+1)%SIZE;
		}
		while(h[addr] != EMPTY);
		h[addr] = key;
		cout<<key<<" is inserted at "<<addr<<endl;
	}
}

void Display()
{
	int i; 
	cout<<"Hash Table \n\n";
	for(i=0; i<SIZE; i++)
	{
		cout<<"h["<<i<<"]"<<h[i]<<endl;
	}
}

void Search(int skey)
{
	int saddr = skey %SIZE;
	int ogaddr = saddr; //original address
	if(h[saddr] == skey)
	{
		cout<<"Value is found at "<<saddr<<endl;
	}
	else
	{
		do
		{
			saddr = (saddr + 1)%SIZE;
			if(saddr == ogaddr)
			{
				break;
			}
		}
		while(h[saddr] != EMPTY);
		if(h[saddr] == skey)
		{
			cout<<"Value is found at "<<saddr<<endl;
		}
		else
		{
			cout<<"Value not found"<<endl;
		}
	}
}
int main()
{
	Init();
	int ch, num,y;
	while(1)
	{
		system("cls");
		cout<<"***Hashing Algorithm*** \n";
		cout<<"1. Insert \n";
		cout<<"2. Display \n";
		cout<<"3. Search \n";
		cout<<"4. Exit \n";
		
		cout<<"Enter yo choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Insert number: ";
				cin>>num;
				Insert(num);
				getch();
				break;
			case 2:
				cout<<"Display: ";
				Display();
				getch();
				break;
			case 3:
				cout<<"Search: ";
				cin>>y;
				Search(y);
				getch();
				break;
			case 4:
				exit(1);
				break;
			default:
				cout<<"Wrong opt";
				getch();
				break;	
		}
	}
}
