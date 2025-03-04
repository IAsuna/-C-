#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;

//���������ṹ��
struct Tree
{
	int key;
	Tree* left, * right;
};

//�������Ľڵ�
Tree* get_new_tree_node(int val)
{
	Tree* t = new Tree;
	t->key = val;
	t->left = nullptr;
	t->right = nullptr;
	return t;
}

//��ʼ����
Tree* insert(Tree* t, int val)
{
	if (t == nullptr) return get_new_tree_node(val);
	if (rand() % 2)t->left = insert(t->left, val);
	else t->right = insert(t->right, val);
	return t;
}

//���
void clear_tree(Tree* t)
{
	if (t == nullptr) return;
	clear_tree(t->left);
	clear_tree(t->right);
	delete t;
	return;
}

//��������һ����
Tree* get_new_tree(int val)
{
	Tree* root = nullptr;
	for (int i = 0; i < val; i++)
	{
		root = insert(root, rand() % 100);
	}

	return root;
}


vector<char> vt;//���ڴ���������������л�������

//���л�
void __serialize(Tree* t)
{
	if (t == nullptr) return;
	for (char c : to_string(t->key))
	{
		vt.push_back(c);
	}
	if (t->right == nullptr && t->left == nullptr) return;
	vt.push_back('(');
	__serialize(t->left);
	if (t->right)
	{
		vt.push_back(',');
		__serialize(t->right);
	}
	vt.push_back(')');
	return;
}

//�����װ������������
void serialize(Tree* t)
{
	__serialize(t);
	return;
}

//չʾ����������
void print_tree(Tree* t)
{
	if (t == nullptr) return;
	cout << (t ? t->key : 0) << endl;;
	print_tree(t->left);
	print_tree(t->right);
	return;
}

//�����л�����ջ
Tree* dserialize(vector<char> t)
{
	stack<Tree*> st;
	int flag = 0;
	Tree* nt = nullptr, * root = nullptr;

	for (vector<char>::iterator it = vt.begin(); it != vt.end(); it++)
	{
		if (*it >= '0' && *it <= '9') {
			int num = 0;
			while (*it <= '9' && *it >= '0')
			{
				num = num * 10 + (*it - '0');
				it++;
			}
			nt = get_new_tree_node(num);
			if (!st.empty())
			{
				switch (flag)
				{
				case 0:st.top()->left = nt; break;
				case 1:st.top()->right = nt; break;
				}
			}
		}

		if (*it == '(')
		{
			st.push(nt);
			flag = 0;
		}
		if (*it == ',')
			flag = 1;
		if (*it == ')')
		{
			root = st.top();
			st.pop();
		}
	}
	return root;
}

int main()
{
	srand(time(0));
	Tree* node = get_new_tree(10);
	serialize(node);
	cout << "��ǰ��Ϊ" << endl;
	print_tree(node);
	cout << "------------------------" << endl;
	for (vector<char>::iterator it = vt.begin(); it != vt.end(); it++)
	{
		cout << *it;
	}
	cout << endl;
	cout << "------------------------" << endl;
	Tree* new_tree = dserialize(vt);
	print_tree(new_tree);
	return 0;
}