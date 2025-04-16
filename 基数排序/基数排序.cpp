#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
using namespace std;


void radix_sort(vector<int> &arr)
{
	if (arr.empty())return;

	//寻找最大值，确定排序几轮
	int max_val = *max_element(arr.begin(), arr.end());
	
	//从个位开始排序
	for (int ind = 1; max_val / ind > 0; ind *= 10)
	{
		vector<queue<int>> vq_ra(10);

		//在对应位置放入对应数字
		for (int num : arr)
		{
			int temp = (num / ind) % 10;
			vq_ra[temp].push(num);
		}

		//取出
		int index = 0;
		for (int i = 0; i < 10; i++)
		{
			while (!vq_ra[i].empty())
			{
				arr[index++] = vq_ra[i].front();
				vq_ra[i].pop();
			}
		}
	}
}

void radix_sort_ne(vector<int> &arr)
{
	if (arr.empty())return;

	vector<int> neg, noneg;
	for (int num : arr)
	{
		if (num < 0)
			neg.push_back(num);
		else
			noneg.push_back(num);
	}

	radix_sort(noneg);
	radix_sort(neg);
	for (int num : neg) num = -num;
	reverse(neg.begin(), neg.end());

	arr = neg;
	arr.insert(arr.end(), noneg.begin(), noneg.end());
}

int main()
{
	vector<int> arr = { -2016,13,256,-6,99,754,281 };
	cout << "原来数组:"; for (int num : arr)cout << num << " ";
	cout << endl;

	radix_sort_ne(arr);

	cout << "排序后:"; for (int num : arr)cout << num << " ";
	cout << endl;
	return 0;

}