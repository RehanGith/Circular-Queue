#include <iostream>
using namespace std;


class Queue {
	int* arr;
	int size;
	int front; 
	int rear;
public:
	Queue(int s) : size(s+1),front(0), rear(0) {
		arr = new int[s];
	}
	void enqueue(int x);
	int dequeue();
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
Queue::~Queue() {
	delete[]arr;
}
int main() {
	Queue q(3);
	q.enqueue(1);
	q.enqueue(2);
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

}