/*Selection sort 
Name: Shubham Sarang 
ROll NO: 1345
Unit 1 Sorting
Program: Selection sort
*/
#include<iostream>
using namespace std; 
int main()
{
	int n, arr[20]; 
	int i, min, loc, tmp, j;
	
	cout<<"**Selection Sorting**"<<endl<<endl;
	
	cout<<"Enter size of array: ";
	cin>>n;
	
	cout<<endl;
	
	cout<<"Enter number of elements: ";
	
	for(i=0; i<n; i++)
	{
	cin>>arr[i];
	}
	
	cout<<endl;
	//selection sort processing 
	for(i=0; i<n; i++)
	{
		//Assume min value and its loc
		min= arr[i]; 
		loc= i; 
		for(j=i+1; j<n; j++)
		{
			if(arr[j] < min)
			{
				min = arr[j];
				loc = j;
			}
		} 
		//found the min value and loc 
		//swap the value at i and loc
		tmp = arr[i];
		arr[i] = min; 
		arr[loc] = tmp;
	}
	//Display sorted array 
	cout<<"The sorted elements are : ";
	
	for(i=0; i<n; i++)
	{
	cout<<arr[i]<<" ";
	}

}//end main

