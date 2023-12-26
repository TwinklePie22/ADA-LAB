#include<iostream>
#include<algorithm>  
using namespace std;

void MergeSort(int arr[], int left , int right)
{
	if(left<right)
	{
		int mid = left +(right-left)/2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid+1, right);
		inplace_merge(arr+left, arr+mid+1, arr+right+1); // to merge two sorted sub-arrays
	}
}
void printArray(int arr[], int size)
{
	for(int a=0; a<size; a++)
	{
		cout<<arr[a]<<" " ;
	}
	cout<<endl;
}

int main()
{
	int arr[]= {15, 5, 24, 8, 1, 3, 16, 10, 20};
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<< "Original Array: ";
	printArray(arr,n);

	MergeSort(arr, 0, n-1);
	cout<<"Sorted Array: ";
	printArray(arr, n);
	return 0;
}