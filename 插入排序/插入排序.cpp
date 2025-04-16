#include<iostream>
#include<iomanip>
using namespace std;




void insert_sort(int* arr, int l, int r)
{
	for (int i = l + 1; i < r; i++)
	{
		int j = i;
		while (j > l && arr[j] < arr[j - 1])
		{
			swap(arr[j], arr[j - 1]);
			j -= 1;
		}
	}
	return;
}

void insert_sort2(int* arr, int l, int r)
{
	int ind = l;
	for (int i = l + 1; i < r; i++)
	{
		if (arr[i] < arr[ind]) ind = i;
	}
	while (ind > l) {
		swap(arr[ind], arr[ind - 1]);
		ind -= 1;
	}
	for (int i = l + 1; i < r; i++)
	{
		int j = i;
		while (arr[j] < arr[j - 1])
		{
			swap(arr[j], arr[j - 1]);
			j -= 1;
		}
	}
	return;
}

int main()
{
	int arr[] = { 1,0,9,6,4,3,5,2,8,7 };
	int a = sizeof(arr) / sizeof(arr[0]);
	/*insert_sort(arr, 0, a);
	for (auto x : arr)
	{
		cout << setw(2) << x;
	}
	*/
	insert_sort2(arr, 0, a);
	for (auto x : arr)
	{
		cout << setw(2) << x;
	}
	return 1;
}