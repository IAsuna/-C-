/*#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;


struct  Node
{
	int data;
	struct Node *next;
};

Node *getNewMyda(int val)
{
	Node* p = new Node;
	p->data = val;
	p->next = nullptr;
	
	return p;
}

Node* insert(Node* head, int pos, int val)
{
	Node new_head, * p = &new_head;
	Node* node = getNewMyda(val);
	new_head.next = head;

	for (int i = 0; i < pos; i++) p = p->next;
	node->next = p->next;
	p->next = node;

	/*if (pos == 0)
	{
		Node* p = getNewMyda(val);
		p->next = head;
		return p;
	}

	Node* p  = head;
	for (int i = 1; i < pos; i++) p = p->next;

	Node* node = getNewMyda(val);
	node->next = p->next;
	p->next = node;
	return new_head.next;
}

void shou(Node* head)
{
	int len = 0, n = 0;

	for (Node* p = head; p; p = p->next) n += 1;
	for (int i = 0; i < n; i++)
		cout << setw(4) << i;

	cout << endl;
	for (Node* p = head; p; p = p->next)
		cout <<setw(4)<<p->data;

	cout << endl;
}
void clear(Node* head)
{
	if (head == nullptr) return;
	for (Node* p = head, *q; p; p = q)
	{
		q = p->next;
		delete p;
	}

	return;
}

void find(Node* head, int val)
{
	Node* p = head;
	int i = 0;
	bool t = false;
	while (p)
	{
		
		if (p->data == val)
		{
			cout << "查找成功" << endl;
			shou(head);
			for (int j = 0;; j++)
			{
				if (j == i)
				{
					cout << setw(5) << "↑";
					break;
				}
				cout << setw(3) << " ";
			}

			t = true;
		}
		i++;
		p = p->next;
	}
	if (!t)
		cout << "查找失败" << endl;
	t = false;
}

int main1()
{
	srand(time(0));
	#define MAX 5
	Node* head = nullptr;
	for (int i = 0; i < MAX; i++)
	{
		int pos = rand() % (i + 1), val= rand() % 100;
		cout << "在" << pos << "位置插入了" << val << endl;
		head = insert(head, pos, val);
		shou(head);
	}
	
	int a = 0;
	cout << "请输入要查找的数字" << endl;
	cin >> a;
	
	find(head, a);
	return 0;
}*/