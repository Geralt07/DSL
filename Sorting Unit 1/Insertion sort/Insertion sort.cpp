/*Selection sort 
Name: Shubham Sarang 
ROll NO: 1345
Unit 1 Sorting
Program: Insertion sort
*/
#include<iostream>
using namespace std; 
int main()
{
	int n, arr[20], i, tmp, loc; 
	
	cout<<"**Insertion Sorting**"<<endl<<endl;
	
	cout<<"Enter size of array: ";
	cin>>n;
	
	cout<<endl;
	
	cout<<"Enter number of elements: ";
	
	for(i=0; i<n; i++)
	{
	cin>>arr[i];
	}
	
	cout<<endl;
	
	//Insertion sort logic
	for(i=1; i<n; i++)
	{
		tmp = arr[i];
		loc = i-1;
		while(tmp < arr[loc] && loc>=0)
		{
			arr[loc+1] = arr[loc];
			loc--;
		}
		arr[loc+1] = tmp;
	}
		//Display sorted array 
	cout<<"The sorted elements are : ";
	
	for(i=0; i<n; i++)
	{
	cout<<arr[i]<<" ";
	}

}//End main
