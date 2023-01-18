//Stack with float data

#include<iostream>
#include<conio.h>
#include<ctype.h>

#define MAX 20 

using namespace std;

//Node template not required

//Stack template 
class Stack
{
	float a[MAX];
	int tos;
	public:
		Stack()
		{
			tos = -1;
		}
		void Push(float x); 
		float Pop();
		int Full();
		int Empty();
};
//Functions

void Stack::Push(float x)
{
	if(Full())
	{
		cout<<"Stack overflow!!";
	}
	else
	{
		tos++;
		a[tos] = x;
	}
}

float Stack::Pop()
{
	if(Empty())
	{
		cout<<"Stack underflow!!";	
		return -1;
	}
	else
	{
		float tmp = a[tos];
		tos--;
		return tmp;
	}
}

int Stack::Full()
{
	return(tos == MAX ? 1:0);
}

int Stack::Empty()
{
	return(tos == -1 ? 1:0);
}
