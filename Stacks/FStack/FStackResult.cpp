/*
Name: Shubham Sarang
Roll no: 1345
Unit 3: Stacks
Program: Evaluation of a Postfix Expression
*/

#include"FStack.cpp"

int main()
{
	char tmp, postfix[MAX]; //MAX defined in FStack.cpp
	Stack s;
	int i=0 ;
	float a, b, result;
	
	cout<<"Evaluation of postfix expression \n";
	cout<<"Enter a postfix expression: ";
	gets(postfix);
	
	while(postfix != '\0')
	{
		tmp = postfix[i];
		
		if(tmp== ' ') //checking space
		{
			i++;
			continue;
		}
		if(isdigit(tmp)) //checking for digit 
		{
			float x = tmp - 48.0;
			s.Push(x);
		}
		else //check if operator + - * / 
		{
			b = s.Pop();
			a = s.Pop();
			
			switch(tmp)
			{
				case '+':
					result = a+b;
					break;
				case '-':
					result = a-b;
					break;
				case '*':
					result = a*b;
					break;
				case '/':
					result = a/b;
					break;	
			} 
			s.Push(result);
		}//end of else
		
		i++;

	}//end of while
	cout<<"Result = "<<result;
}
