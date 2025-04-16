#include<iostream>
#include<ctime>
#include<cstdio>
using namespace std;

#define cmp >
#define ROOT 1
#define FATHER(i) ((i) / 2)
#define LEFT(i) ((i) * 2)
#define RIGHT(i) ((i) * 2 + 1)


int* get_rand_data(int n)
{
	int* arr = new int[n];
	for (int i = 0; i < n; i++) 
		arr[i] = rand() % 100000;
	return arr;
}
void up_updata(int* data, int i)
{
	while (i > 1 && data[i] cmp data[FATHER(i)])
	{
		swap(data[i], data[FATHER(i)]); 
		i = FATHER(i);
	}
	return;
}

inline void down_updata(int* data,int i, int n)
{
	while (LEFT(i) <= n)
	{
		int ind = i, l = LEFT(i), r = RIGHT(i);
		if (data[l] cmp data[ind])ind = l;
		if (r <= n && data[r] cmp data[ind]) ind = r;
		if (ind == i)break;
		swap(data[ind], data[i]);
		i = ind;
	}
	return;
}

void heap_sort(int* data, int n)
{
	for (int i = n; i >= 2; i--)
	{
		swap(data[i], data[i]);
		down_updata(data, 1, i - 1);
	}
}

//普通堆排序，向上调整
void normal_heap(int* data, int n)
{
	for (int i = 2; i <= n; i++)
	{
		up_updata(data, i);
	}
	heap_sort(data, n);
	return;
}

//线性对的向下调整
inline void linear_heap(int* data, int n)
{
	for (int i = (n / 2); i >= 1; i--)
	{
		down_updata(data, i,1000);
	}
	return;
}
int main()
{
#define MAX_N 1000
	srand(time(0));
	int* arr = get_rand_data(MAX_N);
	int* data = arr - 1;
	
}