#include<iostream>
using namespace std;
struct Node
{
	string s;
	Node* next;
};

struct Hash
{
	Node* data;
	int cnt, size;
};

void clear(Hash* h);
bool insert(Hash* h, string s);
Node* get_new_node(string key)
{
	Node* p = new Node;
	p->s = key;
	p->next = nullptr;
	return p;
}

Hash* get_new_hash(int n)
{
	Hash* p = new Hash;
	p->data = new Node[n];
	p->cnt = 0;
	p->size = n;
	return p;
}

int hash_func(string s)
{
	int seed = 131,h = 0;
	for (int i = 0; s[i]; i++)
	{
		h = h * seed + s[i];
	}
	return h & 0x7fffffff;
}

bool find(Hash* h, string s)
{
	int hcode = hash_func(s), ind = hcode % h->size;
	Node* p = h->data[ind].next;
	while (p)
	{
		if (p->s == s) return true;
		p = p->next;
	}
	return false;
}

void expand(Hash* h)
{
	cout << "À©ÈÝ" << endl;
	Hash* new_h = get_new_hash(2 * h->size);
	for (int i = 0; i < h->size; i++)
	{
		Node* p = h->data[i].next;
		while (p)
		{
			insert(new_h, p->s); 
			p = p->next;
		}
	}
	swap(h->data, new_h->data);
	swap(h->cnt, new_h->cnt);
	swap(h->size, new_h->size);
	clear(new_h);
	return;
}

bool insert(Hash* h, string s)
{
	if (h->cnt >= h->size * 2) {
		expand(h);
	}
	int hcode = hash_func(s),ind = hcode % h->size;

	Node* n = get_new_node(s);
	n->next = h->data[ind].next;
	h->data[ind].next = n;
	h->cnt += 1;
	return true;
}

void output(Hash *h)
{
	for (int i = 0; i < h->size; i++)
	{
		cout << i;
		Node* n = h->data[i].next;
		while (n)
		{
			cout  << n->s << "n->" ;
			n = n->next;
		}
		cout << endl;
	}
	return;
}

void clear_node(Node* p)
{
	if (p == nullptr)return;
	delete p;
	return;
}

void clear(Hash* h)
{
	cout << "hash" << h->cnt << " " << h->size << " " << endl;
	if (h == nullptr)return;
	for (int i = 0; i < h->size; i++)
	{
		Node* p = h->data[i].next, * q;
		while (p)
		{
			q = p->next;
			clear_node(p);
			p = q;
		}
	}
	delete[] h->data;
	delete h;
	return;
}

int main()
{
	string s1;
	Hash* h = get_new_hash(2);
	while (cin >> s1)
	{
		if (s1 == "end")break;
		insert(h,s1);
	}

	output(h);

	cout << "ÊäÈëÒª²éÕÒµÄ×Ö·û´®" << endl;
	cin >> s1;
	cout << "find("<<s1<<") = " << find(h, s1) << endl;

	clear(h);
	return 0;
}