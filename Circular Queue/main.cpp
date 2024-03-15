#include <iostream>
using namespace std;


class Queue {
	int* arr;
	int size;
	int front; 
	int rear;
public:
	Queue(int s) : size(s+1),front(0), rear(0) {
		arr = new int[size];
	}
	void enqueue(int x);
	int dequeue();
	bool full();
	bool empty();
	int first();
	int last();
	~Queue();
};
void Queue::enqueue(int x) {
	if ((rear + 1)%size == front) {
		cout << "Queue is full" << endl;
		exit(-1);
	}
	rear = (rear + 1) % size;
	arr[rear] = x;
}

int Queue::dequeue() {
	if (front == rear) {
		cout << "Queue is empty" << endl;
		exit(-1);
	}
	front = (front + 1) % size;
	int n = arr[front];
	arr[front] = 0;
	return n;
}
bool Queue::full() {
	if ((rear + 1) % size == front) {
		return true;
	}
	return false;
}
bool Queue::empty() {
	if (rear == front) {
		return true;
	}
	return false;
}
int Queue::first() {
	if (front == rear)
		exit(-1);
	front = (front + 1) % size;
	return arr[front];
}
int Queue::last() {
	if (front == rear)
		exit(-1);
	return arr[rear];
}
Queue::~Queue() {
	delete []arr;
}
int main() {
	Queue q(3);
	cout << q.empty() << endl;
	q.enqueue(1);
	q.enqueue(2);
	cout << q.first() << endl;
	q.enqueue(9);
	cout << q.last() << endl;
	cout << q.dequeue() << endl;
	return 0;
}