#include<iostream>
#include<ctime>
#include<iomanip>

#define HEAD 1
using namespace std;

struct PQ {
	int* data,* __data;
	int size, count;
};

PQ* init_new_PQ(int size) {
	PQ* pq = new PQ;
	pq->__data = new int[size];
	pq->data = pq->__data - HEAD;
	pq->size = size;
	pq->count = 0;
	return pq;
}

void UP(int* data, int key) {
	if(key == HEAD) return;
	if (data[key] > data[key / 2]) {
		swap(data[key], data[key / 2]);
		UP(data, key / 2);
	}
	/*
	* while(key > HEAD && data[key] > data(key / 2)) {
	*	swap(data[key],data[key / 2]);
	*	key = key / 2;
	* }
	*/

	return;
}


void DOWN(int* data, int key,int count) {
	int left = 2 * key;
	int right = 2 * key + 1;
	while (left <= count)
	{
		int ind = key;
		if (data[left] > data[ind]) ind = left;
		if (right <= count && data[right] > data[ind]) ind = right;
		if (ind == key) break;
		swap(data[ind], data[key]);
		key = ind;
	}
	return;
}

int empty(PQ* pq) {
	return pq->count == 0;
}

int full(PQ* pq) {
	return pq->count == pq->size;
}

int top(PQ* pq) {
	return pq->data[HEAD];
}

int push_pq(PQ* pq, int val) {
	if (full(pq)) {
		cout << "���������޷�����" << endl;
		return 0;
	}

	pq->count += 1;
	pq->data[pq->count] = val;
	UP(pq->data,pq->count);
	return 1;
}

int pop_pq(PQ* pq) {
	if (empty(pq)) {
		cout << "��Ϊ��" << endl;
		return 0;
	}
	if (HEAD == pq->count)
		pq->data[HEAD] = 0;
	pq->data[HEAD] = pq->data[pq->count];
	pq->count -= 1;
	DOWN(pq->data, HEAD,pq->count);
	return 1;
}

void clear_PQ(PQ* pq) {
	if (pq == nullptr) return;
	delete[] pq->__data;
	delete pq;
	return;
}

void shou_pq(PQ* pq) {
	cout << "��ǰ����" << pq->count << "��Ԫ��" << endl;
	for (int i = 1; i <= pq->count; i++) {
		cout <<setw(4)<< pq->data[i];
	}
	cout << endl;
	return;
}
int main() {
	int cz, val;
	PQ* pq = init_new_PQ(5);
	while (cin >> cz)
	{
		if (cz == -1) break;
		if (cz == 1) {
			cin >> val;
			cout << "����" << val << endl;
			push_pq(pq, val);
			shou_pq(pq);
		}
		else {
			cout <<"��ǰ��ɾ���ĶѶ�Ԫ��Ϊ" << top(pq) << endl;
			pop_pq(pq);
			shou_pq(pq);
		}	
	}

	clear_PQ(pq);
	return 0;
}