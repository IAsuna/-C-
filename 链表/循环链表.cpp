#include<iostream>
#include<ctime>
#include<iomanip>

using namespace std;

struct MyStruct
{
	int num;
	MyStruct* next;
};

MyStruct* GetStruct(int getnum)
{
	MyStruct* p = new MyStruct;
	p->num = getnum;
	p->next = nullptr;

	return p;
}

void clear_pos(MyStruct* mys,int pos)
{
	if (mys == nullptr)
	{
		cout << "��Ϊ��" << endl;
		return;
	}
	MyStruct* p = mys, * q = nullptr;

	for (int i = 1; i < pos; i++)
	{
		q = p;
		p = p->next;
	}

	q->next = p->next;
	delete p;
}

void clear(MyStruct*& mys)
{
	if (mys == nullptr)
	{
		cout << "��Ϊ��" << endl;
		return;
	}
	for (MyStruct* p = mys, *q = nullptr; p; p = q)
	{
		q = p->next;
		delete p;
	}
	mys = nullptr;
	return;
}

void shou(MyStruct* mys)
{
	if (mys == nullptr)
	{
		cout << "��Ϊ��" << endl;
		return;
	}
	for (MyStruct* p = mys; p; p = p->next)
		cout << setw(3) << p->num;
	cout << endl;
	return;
}

void find_Mystruct(MyStruct* mys,int val)
{
	int i = 1;
	for (MyStruct* p = mys; p; p = p->next,i++)
	{
		if (p->num == val)
		{
			cout << setw(3) << "���ҵ�����" << val << "λ��Ϊ" << i << endl;
			return;
		}
	}
	cout << "����ʧ��" << endl;
}

MyStruct* insert(MyStruct* mys, int pos, int val)
{
	MyStruct null_head,*p = &null_head;
	null_head.next = mys;
	MyStruct* new_mys = GetStruct(val);

	for (int i = 0; i < pos; i++) p = p->next;
	new_mys->next = p->next;
	p->next = new_mys;

	return null_head.next;
}

int main()
{
#define N 5
	srand(time(0));

	MyStruct* head = nullptr;
	for (int i = 0; i < N; i++)
	{
		int pos = rand() % (i + 1), val = rand() % 100;
		cout << "��" << pos << "λ�ò�����" << val << endl;
		head = insert(head, pos, val);
	}

	cout << "��ǰ��������Ϊ" << endl;
	shou(head);

	cout << "������Ҫ���ҵ�����" << endl;
	int i;
	cin >> i;
	find_Mystruct(head, i);

	cout << "������Ҫɾ����λ��" << endl;

	int pos;
	cin >> pos;
	clear_pos(head, pos);
	shou(head);

	clear(head);

	shou(head);

}