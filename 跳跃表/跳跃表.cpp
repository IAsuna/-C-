#include<iostream>
#include<ctime>
#include<cinttypes>
#include<iomanip>
using namespace std;

struct MyStruct
{
	int key,level;
	MyStruct* next,*down,*up;
};
#define MAX_LEVEL 32

struct skiplist
{
	MyStruct* tail,*head;
	int max_level;
};

MyStruct* get_new_node(int key,int n)
{
	MyStruct* p = new MyStruct[n];
	for (int i = 0; i < n; i++)
	{
		p[i].key = key;
		p[i].level = i;
		p[i].next = nullptr;
		p[i].down = (i ? p + (i - 1) : nullptr);
		p[i].down = (i + 1 < n? p + (i + 1) : nullptr);
	}
	return p + n - 1;
}

skiplist* get_new_skip_list(int n) 
{
	skiplist* p = new skiplist;
	p->head = get_new_node(INT32_MIN,n);
	p->tail = get_new_node(INT32_MAX,n);
	MyStruct* q = p->head, * t = p->tail;
	while (q && t)
	{
		q->next = t;
		q = q->down, t = t->down;
	}
	while (p->head->down != nullptr)p->head = p->head->down;
	return p;
}


MyStruct *find(skiplist *s,int x)
{
	MyStruct* p = s->head;
	while (p && p->key != x)
	{
		if (p->next->key <= x)p = p->next;
		else p = p->down;
	}
	return p;
}

double randDouble() {
#define MAX_RAND_N 1000000
	return (rand() % MAX_RAND_N) * 1.0 / MAX_RAND_N;
#undef MAX_RAND_N
}
int randLevel(skiplist* s)
{
	int level = 1;
	double p = 1.0 / 2.0;
	while (randDouble() < p)level += 1;
	return min(s->max_level, level);
}
void insert(skiplist* s, int x)
{
	int level = randLevel(s);
	while (s->head->level + 1 < level) s->head = s->head->up;
	MyStruct* node = get_new_node(x, level);
	MyStruct* p = s->head;
	while (p->level != node->level)p = p->down;
	while (p) 
	{
		while (p->next->key < node->key) p = p->next;
		node->next = p->next;
		p->next = node;
		p = p->down;
		node = node->down;
	}
	return;
}

void clear(MyStruct* p)
{
	if (p == nullptr)return;
	delete[] p;
}
void clear_skiplist(skiplist* s)
{
	MyStruct* p = s->head,*q;
	while (p->level != 0) p = p->down;
	while (p)
	{
		q = p->next; 
		clear(p);
		p = q;
	}
	delete[] s;
}

void output(skiplist* s) 
{
	MyStruct* p = s->head;
	int len = 0;

	for (int i = 0; i < s->head->level; i++)
	{
		len++;
		cout << setw(4) << i;
	}
	cout << endl;
	for (int i = 0; i < len; i++)
		cout << "-----";
	cout << endl;
	while (p->level > 0) p = p->down;
	while (p)
	{
		bool flag = (p->key != INT32_MIN && p->key != INT32_MAX);
		for (MyStruct* q = p; flag && q; q = q->up) {
			cout << setw(4) << q->key;
		}
		cout << endl;
		p = p->next;
	}
	return;
}
int main()
{
	srand(time(0));
	int x;
	skiplist* s = get_new_skip_list(MAX_LEVEL);
	while (cin>>x)
	{
		if (x == -1)break;
		insert(s, x);
	}
	output(s);

	cout << "-----------------" << endl;

	while (cin >> x)
	{
		MyStruct* p = find(s, x);
		cout << "ур╣╫ак" << endl;
		if (p) cout << p->key << " " << p->level;
		else cout << "©у" << endl;
	}
	return 0;
}