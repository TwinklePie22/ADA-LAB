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

// #include <iostream>
// #include <vector>
// using namespace std;

// void merge(vector<int> &files, int left, int mid, int right)
// {
// 	int i, j, k;
// 	int n1 = mid - left + 1;
// 	int n2 = right - mid;

// 	vector<int> L(n1), R(n2);

// 	for (i = 0; i < n1; i++)
// 		L[i] = files[left + i];
// 	for (j = 0; j < n2; j++)
// 		R[j] = files[mid + 1 + j];

// 	i = 0;
// 	j = 0;
// 	k = left;
// 	while (i < n1 && j < n2)
// 	{
// 		if (L[i] <= R[j])
// 		{
// 			files[k] = L[i];
// 			i++;
// 		}
// 		else
// 		{
// 			files[k] = R[j];
// 			j++;
// 		}
// 		k++;
// 	}

// 	while (i < n1)
// 	{
// 		files[k] = L[i];
// 		i++;
// 		k++;
// 	}

// 	while (j < n2)
// 	{
// 		files[k] = R[j];
// 		j++;
// 		k++;
// 	}
// }
// void mergeSort(vector<int> &files, int left, int right)
// {
// 	if (left < right)
// 	{
// 		int mid = left + (right - left) / 2;

// 		mergeSort(files, left, mid);
// 		mergeSort(files, mid + 1, right);

// 		merge(files, left, mid, right);
// 	}
// }

// int main()
// {
// 	vector<int> files = {3, 2, 5, 1, 6, 4};
// 	int files_count = files.size();
// 	cout << "Given files: \n";
// 	for (int i = 0; i < files_count; i++)
// 		cout << files[i] << " ";
// 	mergeSort(files, 0, files_count - 1);
// 	cout << "\nSorted files are: \n";
// 	for (int i = 0; i < files_count; i++)
// 		cout << files[i] << " ";

// 	return 0;
// }
