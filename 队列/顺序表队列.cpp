/*#include<iostream>
#include<time.h>
#include<iomanip>
using namespace std;

struct my_vector{

	int size;
	int* v_data;
};

my_vector* init_vector(int n){

	my_vector* p = new my_vector;
	p->size = n;
	p->v_data = new int(n);
	return p;
}

int insert_vector(my_vector* p, int pos, int val){
	if (pos < 0 || pos >= p->size) return 0;
	p->v_data[pos] = val;
	return 1;
}

int vector_char(my_vector* p, int pos) {
	if (pos < 0 || pos >= p->size) return -1;
	return p->v_data[pos];
}

void clear_vector(my_vector* p) {
	if (p == nullptr) return;
	delete[] p->v_data;
	delete p;
	return;
}


struct Queue{

	my_vector* data;
	int size, head, tail, count;
};
//初始化
Queue* init_queue(int n){

	Queue* q = new Queue;
	q->data = init_vector(n);
	q->size = n;
	q->head = q->tail = q->count = 0;
	return q;
}

//入队
int push_queue(Queue* q, int val) {
	if (q->size == q->count) {
		cout << "队伍已满，插入失败" << endl;
		return 0;
	}
	insert_vector(q->data, q->tail, val);
	q->tail += 1;
	if (q->tail == q->size) q->tail = 0;
	q->count += 1;
	return 1;
}
//判断是否为空
int empty(Queue* q) {
	return q->count == 0;
}
//查看队首元素
int front(Queue* q) {
	return vector_char(q->data, q->head);
}
//出队
int pop_queue(Queue* q) {
	if (empty(q)) return 0;
	q->head += 1;
	q->count -= 1;
	return 1;
}
//清空
void clear_queue(Queue* q) {
	if (q == nullptr) return;
	clear_vector(q->data);
	delete q;
	return;
}

void shou_queue(Queue* q) {
	cout << "队列中的元素" << endl;
	for (int i = 0; i < q->count; i++) {
		cout <<setw(3)<< vector_char(q->data, (q->head + i) % q->size);
	}
	cout << endl;
	return;
}

int main() {
	srand(time(0));
#define MAX 20
	Queue* q = init_queue(5);
	for (int i = 0; i < MAX; i++){
		int it = rand() % 5,val = rand()%100;
		switch (it)
		{
		case 0:
			cout << "删除队首元素" << front(q) << endl;;
			pop_queue(q);
			break;
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
}*/