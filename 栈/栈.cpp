#include<iostream>
#include<time.h>
#include<iomanip>
using namespace std;

struct Stack
{
	int* data;
	int size, top;
};

Stack* init_Stack(int n)
{
	Stack* s = new Stack;
	s->data = new int(n);
	s->size = n;
	s->top = -1;
	return s;
}

int empty(Stack* s)
{
	return s->top == -1;
}

int stack_top(Stack* s)
{
	if (empty(s)) return 0;
	return s->data[s->top];
}

int push_back(Stack* s, int val)
{
	if (s->top + 1 == s->size) return 0;
	s->top += 1;
	s->data[s->top] = val;
	return 1;
}

int pop_back(Stack* s)
{
	if (s == nullptr || empty(s))
	{
		cout << "栈为空，无法删除" << endl;
		return 0;
	}
	s->top -= 1;
	return 1;
}

void clear_stack(Stack* s)
{
	if (s == nullptr) return;
	delete[] s->data;
	delete s;
	return;
}

void shou_stack(Stack* s)
{
	if (empty(s))
		cout << "当前数据为空" << endl;
	else
	{
		cout << "当前栈数据为" << endl;
		for (int i = s->top; i >= 0; --i)
		{
			cout << setw(3) << s->data[i];
		}

		cout << endl;
	}
	return;
}

int main()
{
	srand(time(0));
#define MAX 10

	Stack* s = init_Stack(5);
	for (int i = 0; i < MAX; i++)
	{
		int o = rand() % 3, val = rand() % 100;
		switch (o)
		{
		case 0:
			cout << "删除了" << stack_top(s) << endl;
			pop_back(s);
			break;
		case 1:
		case 2:
			cout << "插入了" << val << endl;
			push_back(s, val);
			break;
		}

		shou_stack(s);
	}
	return 1;
}