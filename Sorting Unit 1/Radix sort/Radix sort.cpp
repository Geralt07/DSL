/*Radix sort 
Name: Shubham Sarang 
ROll NO: 1345
Unit 1 Sorting
Program: Radix sort
*/
#include<iostream>
using namespace std; 
int main()
{
	int n, arr[20], i, j, p, max, k, r, passes=0;
	int bucket[10][20], b_count[10], divisor=1;  
	
	cout<<"**Radix Sorting**"<<endl<<endl;
	
	cout<<"Enter size of array: ";
	cin>>n;
	
	cout<<endl;
	
	cout<<"Enter number of elements: ";
	
	for(i=0; i<n; i++)
	{
	cin>>arr[i];
	}
	
	//find largest number
	max = arr[0];
	for(i=1; i<n; i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];	
		}
	}
	//Length of number
	while(max>0)
	{
		max=max/10;
		passes++;
	}
	//Logic
	for(p=0; p<passes; p++)
	{
		//initialize the b_count array to 0
		for(k=0; k<10; k++)
		{
			b_count[k] = 0;
		}//end of k
		
		//extract digit, place in bin, update b_count
		for(i=0; i<n; i++)
		{
			r = (arr[i]/divisor) % 10; 
			bucket[r][b_count[r]] = arr[i]; 
			b_count[r]++;
		}//end of i
		i=0;
		//Collect the bins
		for(j=0; j<10; j++)
		{
			for(k=0; k<b_count[j]; k++)
			{
				arr[i] = bucket[j][k];
				i++;
			}
		}
		
	divisor = divisor * 10;
	}
	//Display array
	cout<<"The sorted elements are : ";
	
	for(i=0; i<n; i++)
	{
	cout<<arr[i]<<" ";
	}
	
}//end main
