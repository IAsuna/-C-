#include<iostream>
#include<ctime>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

struct Tree
{
	int key;
	Tree* left, * right;
};

Tree* get_new_tree(int val)
{
	Tree* t = new Tree;
	t->key = val;
	t->left = t->right = nullptr;
	return t;
}

Tree* insert_tree(Tree* t, int val)
{
	if (t == nullptr) return get_new_tree(val);
	if (rand() % 2)t->left = insert_tree(t->left,val);
	else t->right = insert_tree(t->right,val);
	return t;
}

void clear_tree(Tree* t)
{
	if (t == nullptr)return;
	clear_tree(t->left);
	clear_tree(t->right);
	delete t;
	return;
}

queue<Tree*> qt;

void bfs(Tree* t)
{
	qt.push(t);
	while (!qt.empty())
	{
		
		cout << qt.front()->key << endl;;
		if (qt.front()->left)
		{
			qt.push(qt.front()->left);
			cout << qt.front()->key << "×ó->" << qt.front()->left->key << endl;
		}
		if (qt.front()->right)
		{
			qt.push(qt.front()->right);
			cout << qt.front()->key << "ÓÒ->" << qt.front()->right->key << endl;
		}
		qt.pop();
	}
}

int tot = 0;
void dfs(Tree* t)
{
	if (t == nullptr) return;
	int star = 0,end = 0;
	tot += 1;
	star = tot;
	if (t->left)dfs(t->left);
	if (t->right)dfs(t->right);
	tot += 1;
	end = tot;

	cout << t->key << "£º" << "[" << star << "," << end << "]" << endl;
}
int main()
{
	srand(time(0));
	Tree* t = nullptr;
	for (int i = 0; i < 10; i++)
	{
		t = insert_tree(t, rand() % 100);
	}
	bfs(t);
	dfs(t);
	return 1;
}