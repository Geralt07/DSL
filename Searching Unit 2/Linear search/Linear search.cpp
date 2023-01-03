/*Linear search 
Name: Shubham Sarang 
ROll NO: 1345
Unit 2 Searching
Program: Linear search
*/
#include<iostream>
using namespace std; 
int main()
{
	int i, n, arr[20];
	int target, flag=0;
	
	cout<<"**Linear Search**"<<endl<<endl;
	
	cout<<"Enter size of array: ";
	cin>>n;
	
	cout<<endl;
	
	cout<<"Enter number of elements: ";
	
	for(i=0; i<n; i++)
	{
	cin>>arr[i];
	}
	
	cout<<endl;
	
	cout<<"Enter element to be searched: ";
	cin>>target;
	
	//Logic
	for(i=0; i<n; i++)
	{
		if(arr[i] == target)
		{
			flag = 1;
			break;
		}
	}
	if(flag == 1) 
	{
		cout<<"Element found at index "<< i;
	}
	else
	{
		cout<<"Element not found";
	}
	
	
}//end main

