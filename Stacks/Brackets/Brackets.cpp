/*
Name: Shubham Sarang
Roll no: 1345
Unit 3:Stacks
Program: Balancing of parenthesis
*/

#include<iostream>
#define MAX 20

using namespace std;

class Stack
{
	char a[MAX];
	int tos;
	public:
		Stack()
		{
			tos = -1;
		}
		void Push(char x);
		char Pop();
		int Full();
		int Empty();
};

void Stack::Push(char x)
{
	if(Full())
	{
		cout<<"Stack overflow";
	}
	else
	{
		tos++;
		a[tos] = x;
	}
}

char Stack::Pop()
{
	if(Empty())
	{
		cout<<"StackUnderflow bro";	
	}
	else
	{
		char tmp = a[tos];
		tos--;
		return tmp;	
	}	
}


int Stack::Full()
{
	return (tos == MAX-1 ? 1:0);
}

int Stack::Empty()
{
	return (tos == -1 ? 1:0);
}

int main()
{
	char expr[20], tmp;
	int i=0, flag=0;
	Stack s;
	
		cout<<"***Balancing of parenthesis*** \n";
		cout<<"Enter an expression";
		cin>>expr;
	
		while(expr[i] != '\0')
		{
			if(expr[i]=='(' ||expr[i]=='{' ||expr[i]=='['  )
			{	
				s.Push(expr[i]);
			}
			if(expr[i]==')' ||expr[i]=='}' ||expr[i]==']')
			{
				if(s.Empty()) //Extra bracket at the end
				{
					flag=1;
					break;
				}
			
				tmp = s.Pop();
			
				if(	tmp == '{' && expr[i]=='}' || 
			   	tmp == '[' && expr[i]==']' ||
			   	tmp == '(' && expr[i]==')' )
			 	 {
				 	i++;
					 continue;
			 	 }
			  	 else //bracket not matching 
			 	 {
			  		flag = 1;
			  		break;
				 }
			}
			i++;
		}//end while
	
		if(s.Empty() && flag == 0)
		{
			cout<<"Parenthesis are balanced";
		}
		else
		{
			cout<<"Parenthesis are not balanced";
		}
	
}//end main

