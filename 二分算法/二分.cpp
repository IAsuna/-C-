#include<iostream>
#include<iomanip>
using namespace std;


void output(int* arr, int n,int ind = -1) {
	
	for (int i = 0; i < n; i++)
		cout <<setw(4)<< i ;
	cout << endl;

	for (int i = 0; i < n; i++)
		cout << "-----";
	cout << endl;
	
	for (int i = 0; i < n; i++)
	{
		if (i == ind)printf("\033[1;32m");
		cout << setw(4) << arr[i];
		if (i == ind)printf("\033[0m");
	}
	cout << endl;
	return;
}

int binary_search(int* arr, int n, int x) {
	int head = 0, tail = n - 1, mid;
	while (head <= tail)
	{
		mid = (head + tail) / 2;
		if (arr[mid] == x)return mid;
		if (arr[mid] < x) head = mid + 1;
		else tail = mid - 1;
	}
	return -1;
}
void test_binary_search(int n) {
	int* arr = new int[n];
	arr[0] = rand() % 10;
	for (int i = 1; i < n; i++)arr[i] = arr[i - 1] + rand() % 10;
	output(arr, n);
	int x;
	while (cin >> x)
	{
		if (x == -1)break;
		int ind = binary_search(arr, n, x);
		output(arr, n, ind);
	}
}
int main() {
#define MAX_N 10
	test_binary_search(MAX_N);
	return 0;
}