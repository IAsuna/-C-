#include<iostream>
#include<iomanip>
using namespace std;


void quick_sort(int* arr,int l ,int r)
{
	if (r - l <= 2) {
		if (r - l <= 1) return;
		if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
		return;
	}

	int x = l, y = r - 1, z = arr[l];
	while (x < y)
	{
		while (x < y && z <= arr[y]) --y;
		if (x < y)arr[x++] = arr[y];
		while (x < y && arr[x] <= z) ++x;
		if (x < y) arr[y--] = arr[x];
	}
	arr[x] = z;
	quick_sort(arr, l, x);
	quick_sort(arr, x + 1, r);
	return;
}

void quick_sort_v1(int* arr, int l, int r)
{
	if (r - l <= 2) {
		if (r - l <= 1) return;
		if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
		return;
	}

	int x = l, y = r - 1, z = arr[l];
	
	do
	{
		while (arr[x] < z) ++x;
		while (arr[y] > z) --y;
		if (x <= y)swap(arr[x], arr[y]);
		++x, --y;
	} while (x < y);

	quick_sort_v1(arr, l, x);
	quick_sort_v1(arr, x, r);
	return;
}

int three(int a,int b,int c)
{
	if (a > b)swap(a, b);
	if (a > c)swap(a, c);
	if (b > c)swap(b, c);
	return b;
}

void quick_sort_v2(int* arr, int l, int r)
{
	if (r - l <= 2) {
		if (r - l <= 1) return;
		if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
		return;
	}

	while (l < r)
	{
		int x = l, y = r - 1, z = three(arr[l], arr[r - 1], arr[(l + r) / 2]);

		do
		{
			while (arr[x] < z) ++x;
			while (arr[y] > z) --y;
			if (x <= y)swap(arr[x], arr[y]);
			++x, --y;
		} while (x < y);
		quick_sort_v2(arr, l, x);
		l = x;
	}
	return;
}

#define thresh_hold 16
void quick_sort_v3_3(int* arr, int l, int r)
{
	while (r - l > thresh_hold)
	{
		int x = l, y = r - 1, z = three(arr[l], arr[r - 1], arr[(l + r) / 2]);

		do
		{
			while (arr[x] < z) ++x;
			while (arr[y] > z) --y;
			if (x <= y)swap(arr[x], arr[y]);
			++x, --y;
		} while (x < y);
		quick_sort_v2(arr, l, x);
		l = x;
	}
	return;
}


void unguarded(int* arr, int l, int r)
{
	int ind = l;
	for (int i = l + 1; i < r; i++)
	{
		if (arr[i] < arr[ind]) ind = i;
	}
	while (ind >l)
	{
		swap(arr[ind], arr[ind - 1]);
		ind--;
	}
	for (int i = l + 1; i < r; i++)
	{
		int j = i;
		while (arr[j] < arr[j - 1])
		{
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}
void  quick_sort_v3(int* arr, int l, int r)
{
	quick_sort_v3_3(arr, l, r);
	unguarded(arr, l, r);

}

int main()
{
	int arr[] = { 1,0,9,6,4,3,5,2,8,7 };
	int a = sizeof(arr) / sizeof(arr[0]);
	//shell_sort(arr, 0, a);
	//quick_sort(arr,0, a);
	//quick_sort_v1(arr,0, a);
	//quick_sort_v2(arr,0, a);
	quick_sort_v3(arr, 0, a);
	//quick_sort_v3(arr,0, a);
	for (auto x : arr)
	{
		cout << setw(2) << x;
	}
	return 1;
}