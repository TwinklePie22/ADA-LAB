/**
 * TODO-  Merge Sort algorithm for an array
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &files_Id, int left, int mid, int right)
{
	inplace_merge(files_Id.begin() + left, files_Id.begin() + mid + 1, files_Id.begin() + right + 1);
}

void mergeSort(vector<int> &files_Id, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		mergeSort(files_Id, left, mid);
		mergeSort(files_Id, mid + 1, right);
		merge(files_Id, left, mid, right);
	}
}

int main()
{
	vector<int> files_Id = {3, 1, 4, 2};
	
	cout << "Original files ID's:";
	for (size_t i = 0; i < files_Id.size(); ++i)
		cout <<  files_Id[i]<<" " ;
	cout<<endl;
	mergeSort(files_Id, 0, files_Id.size() - 1);

	cout << "\nSorted files ID's:";
	for (size_t i = 0; i < files_Id.size(); ++i)
		cout << files_Id[i]<<" " ;
	cout<<endl;
	return 0;
}

// #include<iostream>
// #include<algorithm>  
// using namespace std;

// void MergeSort(int arr[], int left , int right)
// {
// 	if(left<right)
// 	{
// 		int mid = left +(right-left)/2;
// 		MergeSort(arr, left, mid);
// 		MergeSort(arr, mid+1, right);
// 		inplace_merge(arr+left, arr+mid+1, arr+right+1); // to merge two sorted sub-arrays
// 	}
// }
// void printArray(int arr[], int size)
// {
// 	for(int a=0; a<size; a++)
// 	{
// 		cout<<arr[a]<<" " ;
// 	}
// 	cout<<endl;
// }

// int main()
// {
// 	int arr[]= {15, 5, 24, 8, 1, 3, 16, 10, 20};
// 	int n= sizeof(arr)/sizeof(arr[0]);
// 	cout<< "Original Array: ";
// 	printArray(arr,n);

// 	MergeSort(arr, 0, n-1);
// 	cout<<"Sorted Array: ";
// 	printArray(arr, n);
// 	return 0;
// }