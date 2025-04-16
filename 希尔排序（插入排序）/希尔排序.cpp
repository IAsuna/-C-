#include<iostream>
#include<iomanip>
using namespace std;

void insert_sort(int* arr, int l, int r, int step)
{
	int ind = l;
	
	for (int i = l + step; i < r; i += step)
	{
	
		if (arr[i] < arr[ind]) ind = i;
	}

	while (ind > l)
	{
		swap(arr[ind], arr[ind - 1]);
		ind -= step;
	}

	for (int i = l + 2 * step; i < r; i += step)
	{
		int j = i;
		while (arr[j] < arr[j - step])
		{
			swap(arr[j], arr[j - step]);
			j -= step;
		}
	}
	return;
}

void shell_sort(int *arr,int l,int r)
{
	int k = 2, n = r - l, step;
	do
	{
		step = n / k == 0 ? 1 : n / k;
		for (int i = l, I = l + step; i < I; i++)
		{
			insert_sort(arr, i, r, step);
		}
		k *= 2;
	} while (step != 1); 
	return;
}

void shell_sort_hibbard(int* arr, int l, int r)
{
	int step = 1, n = (r - l);
	while (step <= n / 2) step = step * 2 + 1;
	do 
	{
		step /= 2;
		for (int i = l, I = l + step; i < I; i++)
		{
			insert_sort(arr, i, r, step);
		}
		
	} while (step > 1); 
	return;
}

int main()
{
	int arr[] = { 1,0,9,6,4,3,5,2,8,7 };
	int a = sizeof(arr) / sizeof(arr[0]);
	//shell_sort(arr, 0, a);
	shell_sort_hibbard(arr, 0, a);
	for (auto x : arr)
	{
		cout << setw(2) << x;
	}
	return 1;
}