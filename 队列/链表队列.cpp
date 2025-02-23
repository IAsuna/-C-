#include<iostream>
#include<iomanip>
using namespace std;

struct link_list_node{

	int data;
	link_list_node* next;
};

struct my_link_list {
	
	link_list_node head,*tail;
};

int empty_list(my_link_list* l) {
	return l->head.next == nullptr;
}
link_list_node* get_new_link_node(int val) {
	link_list_node* p = new link_list_node;
	p->data = val;
	p->next = nullptr;
	return p;
}

my_link_list* init_link_list() {
	
	my_link_list* l = new my_link_list;
	l->head.next = nullptr;
	l->tail = &(l->head);
	return l;
}

void clear_link_list(my_link_list* l) {
	
	link_list_node* p = l->head.next, * q;
	while (p) {
		q = p->next;
		delete p;
		p = q;
	}
	delete(l);
	return;
}

int insert_tail_link_list(my_link_list* l, int val) {

	link_list_node* node = get_new_link_node(val);
	l->tail->next = node;
	l->tail = node;
	return 1;
}

int erase_head_link_list(my_link_list* l) {
	if (empty_list(l)) return 0;
	link_list_node* p = l->head.next;
	l->head.next = p->next;
	if (p == l->tail) l->tail = &(l->head);
	delete p; 
	return 1;
}

int front_link_list(my_link_list* l){

	if (empty_list(l))return 0;
	return l->head.next->data;
}
struct Queue
{
	my_link_list* data;
	int count;
};

Queue* init_queue(int n) {
	Queue* q = new Queue;
	q->count = 0;
	q->data = init_link_list();
	return q;
}

//入队
int push_queue(Queue* q, int val) {
	insert_tail_link_list(q->data, val);
	q->count += 1;
	return 1;
}

//判断是否为空
int empty(Queue* q) {
	
	return q->count == 0;
}

//查看队首元素
int front(Queue* q) {
	if (empty(q)) return 0;
	return front_link_list(q->data);
}

//出队
int pop_queue(Queue* q) {
	if (empty(q)) return 0;
	erase_head_link_list(q->data);
	q->count -= 1;
	return 1; 
}

//清空
void clear_queue(Queue* q) {
	if (q == nullptr) return;
	clear_link_list(q->data);
	delete q;
	return;
}

//展示
void shou_queue(Queue* q) {
	cout << "队列内容为" << endl;
	link_list_node* p = q->data->head.next;
	for (int i = 0; i < q->count; i++) {
		cout <<setw(3)<< p->data;
		p = p->next;
	}
	cout << endl;
	return;
}

int main()
{
	srand(time(0));
#define MAX 20
	Queue* q = init_queue(5);
	for (int i = 0; i < MAX; i++) {
		int it = rand() % 5, val = rand() % 100;
		switch (it)
		{
		case 0: {
			int a = front(q);
			if (a != 0)
				cout << "删除元素" << a << endl;
			else
				cout << "队伍为空，删除失败" << endl;
			pop_queue(q);
			break;
		}
		case 1:
		case 2:
		case 3:
		case 4:
			cout << "插入" << val << endl;
			push_queue(q, val);
			break;
		}

		shou_queue(q);
	}
}