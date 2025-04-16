#include<iostream>
#include<list>
#include<iomanip>
using namespace std;

void selection_sort(int* arr, int l, int r) 
{
	for (int i = l, R = r - 1; i < R; i++) 
	{
		int ind = i;
		for (int j = i + 1; j < r; j++)
		{
			if (arr[j] < arr[ind]) ind = j;
		}
		swap(arr[i], arr[ind]);
	}
	return;
}

int main()
{
	int arr[] = { 1,0,9,6,4,3,5,2,8,7 };
	int a = sizeof(arr)/sizeof(arr[0]);
	selection_sort(arr, 0, a);
	for (auto x : arr)
	{
		cout <<setw(2)<< x;
	}
	return 1;
}