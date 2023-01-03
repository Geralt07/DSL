/*
Name: Shubham sarang
Roll no: 1345
Unit 2: Binary search
*/
#include<iostream>
using namespace std;
int main()
{
	int n, i, flag=0, arr[20];
	int first, last, mid, target;
	cout<<"***Binary Search***"<<endl;
	cout<<"Enter size of array: ";
	cin>>n;
	
	cout<<endl;
	
	cout<<"Enter elements of an array: ";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	cout<<endl;
	
	cout<<"Enter target: ";
	cin>>target;
	
	//logic
	first= 0;
	last= n-1;
	
	while(first <= last)
	{
		mid = (first + last)/2;
		if(target<arr[mid])
		{	
			last = mid - 1;
		}
		else if(target > arr[mid])
		{
			first = mid + 1;	
		}
		else
		{
			flag = 1;
			break;
		}	
	}
	
	cout<<endl;
	
	if(flag==0)
	{
		cout<<"Target not found";
	}
	else
	{
		cout<<"Target found at index "<<mid;
	}
	
}//end main
