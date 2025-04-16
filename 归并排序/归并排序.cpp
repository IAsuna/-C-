#include<iostream>
#include<iomanip>

using namespace std;

void merge_sort(int* arr, int l, int r)
{
	if (r - l <= 1)return;
	int mid = (r + l) / 2;
	merge_sort(arr, l, mid);
	merge_sort(arr, mid, r);

	int p1 = l, p2 = mid, k = 0;
	int* temp = new int[r - l];
	while (p1 < mid || p2 < r)
	{
		if(p2 == r || (p1 < mid && arr[p1] <= arr[p2]))
		{
			temp[k++] = arr[p1++];
		}
		else {
			temp[k++] = arr[p2++];
		}
	}
	for (int i = l; i < r; i++)arr[i] = temp[i - l];

	delete[] temp;
	return;
}

int main()
{
	int arr[] = { 1,0,9,6,4,3,5,2,8,7 };
	int a = sizeof(arr) / sizeof(arr[0]);
	merge_sort(arr, 0, a);
	for (auto x : arr)
	{
		cout << setw(2) << x;
	}
	return 1;
}