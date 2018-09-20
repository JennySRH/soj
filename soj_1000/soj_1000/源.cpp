
//1000
#include <iostream>
using namespace std;
struct node {
	int data;
	node * next;

};

typedef int Stack_entry;


class Stack {
public: //Êý¾ÝÓò
	node * head;
	int count;
public:
	// Standard Stack methods
	Stack() {
		head = new node;
		head->next = NULL;
		count = 0;
	}
	bool empty() const {
		return (count == 0);
	}
	/* Returns true if the stack is empty, otherwise, returns false.
	*/
	int size() const {
		return count;
	}
	/* Returns the number of elements in the stack.
	*/
	void push(const Stack_entry &item) {
		node * new_element = new node;
		new_element->data = item;
		new_element->next = NULL;
		node * temp = new node;
		temp = head->next;
		head->next = new_element;
		new_element->next = temp;
		count++;
	}
	/*item is pushed into the stack and it becomes the new top element.
	*/
	void pop() {
		if (count == 0) {
			return;
		}
		node * temp = head->next;
		head->next = temp->next;
		delete[]temp;
		count--;
	}
	/*The top item is removed if the stack is not empty.
	Otherwise, nothing happens.
	*/

	const Stack_entry & top() const {
		return head->next->data;
	}
	/* The top element is returned by item if the stack is not empty,
	and the stack remains unchanged.
	Nothing happens if the stack is empty.
	*/
	// Safety features
	~Stack(){
		delete[]head;
	}
	Stack(const Stack &original) {
		Stack original_temp;
		node *temp = new node;
		temp = original.head->next;
		for (int i = 0; i < original.size(); i++) {
			original_temp.push(temp->data);
			temp = temp->next;
		}

		head = new node;
		head->next = NULL;
		count = 0;

		node * temp2 = new node;
		temp2 = original_temp.head->next;
		for (int i = 0; i < original_temp.size(); i++) {
			push(temp2->data);
			temp2 = temp2->next;
		}
	}
	void operator =(const Stack &original) {
		Stack original_temp;
		node *temp = new node;
		temp = original.head->next;
		for (int i = 0; i < original.size(); i++) {
			original_temp.push(temp->data);
			temp = temp->next;
		}

		head->next = NULL;
		count = 0;

		node * temp2 = new node;
		temp2 = original_temp.head->next;
		for (int i = 0; i < original_temp.size(); i++) {
			push(temp2->data);
			temp2 = temp2->next;
		}
	}
};


typedef Stack MyStack;
int main() {
	Stack s;
	s.push(1);

	s.pop();
	s.push(2);

	cout << s.top() << endl;

	Stack a = s;
	cout << a.top() << endl;
	s.push(5);
	s.push(3);
	a = s;
	while (!a.empty()) {
		cout << a.top();
		a.pop();
	}
	//cout << a.top() << endl << a.size();
	system("pause");
}




//or if your are using templates
