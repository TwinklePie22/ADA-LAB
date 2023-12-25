// quick sort algorithm on a given array

#include<iostream>
using namespace std;

int divideArray (int arr[], int lb, int ub)   // lb= lower bound and ub= upper bound
{
	int pivot= arr[lb];
	int i = lb;
	for(int j=lb+1; j<=ub; j++)
	{
		if(arr[j] < pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[lb],arr[i]);	
	return i;
}
void quickSort (int arr[], int lb, int ub)
{
	if(lb < ub)
	{
		int p= divideArray(arr, lb, ub );
		quickSort(arr, lb, p-1);
		quickSort(arr, p+1, ub);
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
	int arr[]= {5, 3, 1, 9, 8, 2, 4, 7};
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<< "Original Array: ";
	printArray(arr,n);
	
	// Sorted array
	quickSort(arr, 0, n-1);
	cout<<"Sorted Array: ";
	printArray(arr, n);
	return 0;
}
