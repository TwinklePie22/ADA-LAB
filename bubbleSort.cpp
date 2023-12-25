//bubble sort an array

#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=0;j<n-i-1; j++)
		{
			if(arr[j]> arr[j+1])
			{
			int temp= arr[j];
			arr[j]= arr[j+1];
			arr[j+1]=temp;
			}
		}
	}
}
int main()
{	
	int n;
	cout<<"Enter the number of elements of array: ";
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
	{	
		cout<<"Enter the element "<<i+1<<" of array: ";
		cin>>arr[i];
	}
	// int arr[]={24,12,58,668,88,20,4};
	// int n= sizeof(arr)/sizeof(arr[0]);
	cout<<"Original Array: ";
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	bubbleSort(arr,n);
	cout<<"Sorted Array: ";
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}

