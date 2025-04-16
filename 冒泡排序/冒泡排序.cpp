#include<iostream>
#include<iomanip>

using namespace std;

void bubble_sort(int* arr, int n)
{
	for (int i = n - 1,cnt = 0; i >= 1; i--)
	{
		cnt = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] <= arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				cnt += 1; 
			}
		}
		if (cnt == 0)break;
	}
	return;
}

int main()
{
	int arr[] = { 1,0,9,6,4,3,5,2,8,7 };
	int a = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, a);
	for (auto x : arr)
	{
		cout << setw(2) << x;
	}
	return 1;
}