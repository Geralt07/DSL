/*
Name: Shubham Sarang 
ROll NO: 1345
Unit 1 Sorting
Program: Shell sort
*/
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n, extractData, arr[20], i, gap, loc;
	
	cout<<"*** Shell sort ***"<<endl;
	cout<<"Enter size of array: ";
	cin>>n;
	cout<<endl;
	cout<<"Enter elements: ";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<endl;
	//Logic
	gap=floor(n/2);
	
	while(gap>0)
	{
		for(i=0 ; i<n-gap ; i++)
		{
			extractData= arr[i+gap];
			loc = i+gap;
			
			while((loc-gap)>=0 && extractData < arr[loc-gap])
			{
				arr[loc] = arr[loc-gap];
				loc = loc - gap;  
			}//end of inner while	
			arr[loc] = extractData;
		}//end of for	
		gap = floor(gap/2); 
	}//end of while
	
	cout<<"Sorted array :";
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}//end main


