// templateQueuesProject.cpp
//

#include <iostream>
#include <cstdlib>
using namespace std;
class DynamicIntegerQueue {
	struct QueueNode {
		int value;
		QueueNode* next;
		QueueNode(int value1, QueueNode* next1 = NULL) {
			value = value1;
			next = next1;
		}
	};
	QueueNode* front;
	QueueNode* rear;
public:
	//constructor
	DynamicIntegerQueue();
	//destructor
	~DynamicIntegerQueue();
	//member functions
	void enqueue(int);
	void dequeue(int&);
	bool isEmpty() const;
	void clear();
};

// constructor
DynamicIntegerQueue::DynamicIntegerQueue() {
	front = nullptr;
	rear = nullptr;
}

// destructor
DynamicIntegerQueue::~DynamicIntegerQueue() {
	QueueNode* garbage = front;
	while (garbage != nullptr) {
		front = front->next;
		delete garbage;
		garbage = front;
	}
}

// enqueue
void DynamicIntegerQueue::enqueue(int num) {
	if (isEmpty()) {
		front = new QueueNode(num);
		rear = front;
	}
	else {
		rear->next = new QueueNode(num);
		rear = rear->next;
	}
}

// dequeue
void DynamicIntegerQueue::dequeue(int& num) {
	QueueNode* temp = nullptr;
	if (isEmpty()) {
		cout << "The queue is empty.\n";
		exit(1);
	}
	else {
		num = front->value;
		temp = front;
		front = front->next;
		delete temp;
	}
}

// isEmpty
bool DynamicIntegerQueue::isEmpty() const {
	if (front == nullptr)
		return true;
	else
		return false;
}

// clear
void DynamicIntegerQueue::clear() {
	int value;
	while (!isEmpty())
		dequeue(value);
}

int main()
{
    cout << "Template Queues by Kevin Bell\n\n";
	DynamicIntegerQueue iQueue;
	cout << "Enqueueing 5 items...\n";
	for (int i = 1; i < 5; i++) {
		iQueue.enqueue(i*i);
	}
	cout << "The values in the queue were:\n";
	while (!iQueue.isEmpty()) {
		int value;
		iQueue.dequeue(value);
		cout << value << endl;
	}
	cout << "The queue is now empty.\n";
	system("pause");
	return 0;
}