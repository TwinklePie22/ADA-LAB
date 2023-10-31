//selection sort an array in assending order

#include<iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		int minValue=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]< arr[minValue])
				minValue=j;
		}
		int temp= arr[i];
		arr[i] = arr[minValue];
		arr[minValue]=temp;
	}
}
int main()
{
	int arr[]={25,669,7755,42,55,254,10,3,64};
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<<"Original Array: ";
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	selectionSort(arr,n);
	std::cout<<"Sorted Array: ";
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
