#include<iostream>
#include<vector>
using namespace std;



struct Tree					//树
{
	char ch;
	int val;
	Tree* zero, * one;
};

struct heap//堆
{
	Tree** __data,**data;//逻辑指针，使得data在使用时可以从1开始
	int n, size;//堆的数量和长度
};

int push_heap(heap* h, Tree* n);
Tree* top(heap* h);
int pop_heap(heap* h);
int push_heap(heap* h, Tree* n);

heap* get_new_heap(int size) {//获取一个堆
	heap* h = new heap;
	h->__data = new Tree*[size];
	h->data = h->__data - 1;
	h->n = 0;
	h->size = size;
	return h;
}

void clear_heap(heap* h) {//堆清空
	if (h == nullptr)return;
	delete[] h->__data;
	delete h;
	return;
}

Tree* get_new_node(int val, char ch)//获得一个新的节点
{
	Tree* p = new Tree;
	p->ch = ch;
	p->val = val;
	p->zero = nullptr;
	p->one = nullptr;
	return p;
}


Tree* build_haffman_tree(Tree** node_new, int n)//哈夫曼树
{
	heap* h = get_new_heap(n);//申请一个堆
	for (int i = 0; i < n; i++)//将获取的到节点压入堆中
	{
		push_heap(h, node_new[i]);
	}
	for (int i = 1; i < n; i++)//对小顶堆进行取头部节点，随后将新节点压入
	{
		Tree* node1 = top(h);
		pop_heap(h);
		Tree* node2 = top(h);
		pop_heap(h);
		Tree* node3 = get_new_node(node1->val + node2->val, 0);
		node3->zero = node1;
		node3->one = node2;
		push_heap(h, node3);
	}
	Tree* ret = top(h);
	clear_heap(h);
	return ret;
}

void extracthaffcode(Tree* root, char buff[], int k)//哈夫曼编码的输出，
{
	buff[k] = 0;
	if (root->one == nullptr && root->zero == nullptr)
	{
		cout << root->ch << ":" << buff << endl;
		return;
	}

	buff[k] = '0';
	extracthaffcode(root->zero, buff, k + 1);
	buff[k] = '1';
	extracthaffcode(root->one, buff, k + 1);
	return;
}
void clear_node(Tree* root)//清空树
{
	if (root == nullptr) return;
	clear_node(root->one);
	clear_node(root->zero);
	delete root;
	return;
}

void up_maintain(heap* h, int key)//向上调整
{
	while (key > 1 && h->data[key]->val < h->data[key / 2]->val)
	{
		swap(h->data[key], h->data[key / 2]);
		key = key / 2;
	}
	return;
}

void down_maintain(heap* h, int key)//向下调整
{
	while (key * 2 <= h->n)
	{
		int ind = key, l = key * 2,r = key * 2 + 1;
		if (h->data[l]->val < h->data[ind]->val) ind = l;
		if (r <= h->n && h->data[r]->val < h->data[ind]->val) ind = r;
		if (ind == key) break;
		swap(h->data[key], h->data[ind]);
	}
	return;
}

int full_heap(heap* h) {//判断堆是否满
	return h->n == h->size;
}

int push_heap(heap* h, Tree* n)//压入节点
{
	if (full_heap(h))return 0;
	h->n += 1;
	h->data[h->n] = n;
	up_maintain(h, h->n);
	return 1;
}


int empty_heap(heap* h)//判空
{
	return h->n == 0;
}

Tree* top(heap* h)
{
	if (empty_heap(h)) return nullptr;
	return h->data[1];
}
int pop_heap(heap* h)//弹出
{
	if (empty_heap(h)) return 0;
	h->data[1] = h->data[h->n];
	h->n -= 1;
	down_maintain(h, 1);
	return 1;
}
int main()
{
	char ch;
	int n, val;
	cin >> n;
	Tree** node_arr = new Tree * [n];
	for (int i = 0; i < n; i++)
	{
		cin >> ch >> val;
		node_arr[i] = get_new_node(val, ch);
	}

	Tree* root = build_haffman_tree(node_arr, n);
	char buff[1000];
	extracthaffcode(root, buff, 0);
	clear_node(root);

}