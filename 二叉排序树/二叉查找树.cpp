#include<iostream>
#include<ctime>
using namespace std;

struct Node
{
	int key;
	Node* left, * right;
};

Node* get_new_node(int k)
{
	Node* n = new Node;
	n->key = k;
	n->left = nullptr;
	n->right = nullptr;
	return n;
}

Node* insert(Node* n, int key)
{
	if (n == nullptr)return get_new_node(key);
	if (key == n->key)return n;
	if (key < n->key) n->left = insert(n->left, key);
	else n->right = insert(n->right, key);
	return n;
}

Node* pre_decessor(Node* n)
{
	Node* temp = n->left;
	while (temp->right)temp = temp->right;
	return temp;
}

Node* erase(Node* n,int key)
{
	if (n == nullptr)return n;
	if (key < n->key)n->left = erase(n->left, key);
	else if (key > n->key)n->right = erase(n->right, key);
	else
	{
		if (n->right == nullptr && n->left == nullptr) 
		{
			delete n; 
			return nullptr; 
		}
		else if(n->right == nullptr || n->left == nullptr)
		{
			Node* temp = n->left ? n->left : n->right;
			delete n;
			return temp;
		}
		else
		{
			Node* ln = pre_decessor(n);
			n->key = ln->key;
			n->left = erase(n->left, ln->key);
		}
	}
	return n;
}

void output(Node* n)
{
	if (n == nullptr) return;
	cout << n->key << "(" << (n->left ?n->left->key:-1) << "," << (n->right ? n->right->key : -1) << ") ";
	output(n->left);
	output(n->right);
	return;
}

void in_output(Node* n)
{
	if (n == nullptr)return;
	in_output(n->left);
	cout << n->key<<" ";
	in_output(n->right);
	return;
}

void clear(Node* n)
{
	if (n == nullptr)return;
	clear(n->left);
	clear(n->right);
	delete n;
	return;
}

int main()
{
	srand(time(0));
#define MAX_OP 10
	Node* node = nullptr;
	for (int i = 0; i < MAX_OP;i++)
	{
		int key = rand() % 100;
		 cout<< "插入了" << key<<endl;
		 node = insert(node, key);
	}

	cout << "遍历结果" << endl;
	output(node);
	cout << endl;
	cout << "结构" << endl;
	in_output(node);
	cout << endl;

	cout << "输入要删除的值" << endl;

	int x;
	cin >> x;
	node = erase(node,x);
	in_output(node);
	return 0;
}