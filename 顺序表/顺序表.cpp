#include<iostream>
#include<ctime>
#include<iomanip>


#define MAX 20
using namespace std;

//顺序表的结构定义
struct my_vector
{
	int size, count;
	int* mydata;
} myvector;

//创建顺序表
my_vector* get_new_vector(int n)
{
	my_vector* p = new my_vector;
	p->size = n;
	p->count = 0;
	p->mydata = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		p->mydata[i] = 0;
	}

	return p;
}

//清空表
void clear_vector(my_vector* v)
{
	if (v == nullptr) return;
	delete[] v->mydata;
	delete v;
	return;
}

//扩容
bool expand(my_vector* v)
{
	if (v == nullptr) return 0;
	int* newData = new int[2 * (v->size)];
	for (int i = 0; i < 2*(v->size); i++)
	{
		if (i < v->size)
			newData[i] = v->mydata[i];
		else
			newData[i] = 0;
	}

	delete[] v->mydata;
	v->mydata = newData;
	v->size = (v->size) * 2;
	newData = nullptr;
	cout << "扩容成功" << endl;
	return true;
}
//插入
int insert_vector(my_vector* v, int pos, int val)
{
	if (pos < 0 || pos > v->size) return 0;
	if (v->size == v->count && (!expand(v))) return 0;
	for (int i = v->count - 1; i >= pos; i--)
	{
		v->mydata[i + 1] = v->mydata[i];
	}
	v->mydata[pos] = val;
	v->count+=1;
	return 1;
}

void shou_vector (my_vector* v)
{
	int len = 0;
	for (int i = 0; i <= v->size - 1; i++,len++)
		 cout <<setw(4)<< i;
	cout << endl;
	for(int i = 0;i<len;i++)
		cout << "----";
	cout << endl;
	for (int i = 0; i < v->size ; i++)
		cout <<setw(4)<< v->mydata[i];
	cout << endl;
}

//删除
int erase_vector(my_vector* v, int pos)
{
	if (pos < 0 || pos >= v->count) return 0;
	for (int i = pos + 1; i < v->size-1; i++)
	{
		v->mydata[i - 1] = v->mydata[i];
	}

	v->count-=1;
	return 1;
}
int main()
{
	srand(time(0));
	my_vector* v = get_new_vector(5);

	for (int i = 0; i < MAX;i++)
	{
		int op = rand() % 4,pos,val;
		switch (op)
		{
			case 0:
			case 1:
			case 2:
				pos = rand() % (v->count +2);
				val = rand() % 100;
				if (insert_vector(v, pos, val))
					cout << "insert"<<val<<"at"<<pos<<"ok!" << endl;
				else
					cout << "insert" << val << "at" << pos << "no!" << endl;
				cout << "size" << v->size << endl;
				break;
			case 3:
				pos = rand() % (v->count + 2);
				if(erase_vector(v,pos))
					cout << "erase" << pos << "成功" << endl;
				else
					cout << "erase" << pos << "失败" << endl;
				break;
		}
		shou_vector(v);
	}
	
	clear_vector(v);
}