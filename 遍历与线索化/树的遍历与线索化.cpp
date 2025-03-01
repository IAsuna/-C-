#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;

struct Tree
{
	int key, ltag, rtag;//1����Ϊ������0��Ϊ��
	Tree* left, * right;
};

Tree* get_new_tree(int val) 
{
	Tree* t = new Tree;
	t->key = val;
	t->left = t->right = nullptr;
	t->ltag = t->rtag = 0;
	return t;
}

Tree* insert(int val, Tree* t)
{
	if (t == nullptr) return get_new_tree(val);
	if (rand() % 2 == 0) t->left = insert(val, t->left);
	else t->right = insert(val,t->right);
	return t;
}

void pre_order(Tree * t)
{
	if (t == nullptr) return;
	cout << setw(3) << t->key;
	if(t->ltag == 0) pre_order(t->left);
	if(t->rtag == 0) pre_order(t->right);
	return;
}

void in_order(Tree* t)
{
	if (t == nullptr)return;

	if (t->ltag == 0) in_order(t->left);
	cout << setw(3) << t->key;
	if (t->rtag == 0) in_order(t->right);
	return;
}

void post_order(Tree* t)
{
	if (t == nullptr)return;
	if (t->ltag == 0) post_order(t->left);
	if (t->rtag == 0) post_order(t->right);
	cout << setw(3) << t->key;
	return;
}

void clear_tree(Tree* t)
{
	if (t == nullptr) return;
	if(t->ltag == 0) clear_tree(t->left);
	if(t->rtag == 0) clear_tree(t->right);
	delete t;
	return;
}

//�������������
Tree* st = nullptr,*in_t = nullptr;
void __build_in_order_thread(Tree* t)
{
	if (t == nullptr)return;

	if (t->ltag == 0) __build_in_order_thread(t->left);
	if (in_t == nullptr) in_t = t;
	
	if (t->left == nullptr)
	{
		t->left = st;
		t->ltag = 1;
	}

	if (st && st->right == nullptr)
	{
		st->right = t;
		st->rtag = 1;
	}
	st = t;
	if (t->rtag == 0) __build_in_order_thread(t->right);

	return;
}

void build_in_order_thread(Tree* t)
{
	__build_in_order_thread(t);
	st->right = nullptr;
	st->rtag = 1;
	return;
}

Tree* get_next(Tree* t)
{
	if (t->rtag == 1)return t->right;
	t = t->right;
	while (t->ltag == 0 && t->left) t = t->left; 
	return t;
}

int main()
{
	srand(time(0));
	Tree* t = nullptr;
	for (int i = 0; i < 10; i++)
	{
		t = insert(rand() % 100,t);
	}

	//����������
	build_in_order_thread(t);
	st = nullptr;
	//ǰ�����
	pre_order(t);
	cout << endl;

	//�������
	in_order(t);
	cout << endl;

	//�������
	post_order(t);
	cout << endl;

	//��������������������
	Tree* node = in_t;
	while (node)
	{
		cout << setw(3) << node->key;
		node = get_next(node);
	}
	clear_tree(t);
	return 1;
}