#include <iostream>
using namespace std;
template <typename T> class Queue {
public:
	Queue() {
		rear = front = count = 0;
	}
	~Queue() {}
	Queue(const Queue &rhs) {
		rear = front = 0;
		count = 0;
		for (int i = 0; i < count; i++) {
			push(rhs[i]);
		}
	}
	const Queue & operator = (const Queue &rhs) {
		count = 0;
		front = rear = 0;
		for (int i = 0; i < count; i++) {
			push(rhs[i]);
		}
	}
	bool empty()const {
		return (count == 0);
	}
	bool full()const {
		return ((rear+1)%100 == front%100);
	}
	int size()const {
		return count;
	}
	bool push(const T &x) {
		if (full()) {
			return false;
		}
		arr[rear] = x;
		rear = (rear + 1) % 100;
		count++;
		return true;
	}
	bool pop() {
		if (empty()) {
			return false;
		}
		front = (front + 1) % 100;
		count--;
		return true;
	}
	const T & front()const {
		return arr[front];
	}
	T operator[](int i) {
		return arr[(front + i) % 100];
	}
private:
	T arr[100];
	int front, rear;
	int count;
	//using a static array of size 100.   

};

int main() {
	Queue<int> a;
	a.push(1);
	a.push(2);
	a.push(3);
	cout << a.size() << endl;
	cout << a.front() << endl;
	Queue<int> s = a;
	cout << s.front() << endl;
	system("pause");
}