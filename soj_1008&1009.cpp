#include <iostream>
using namespace std;
struct ListNode
{
	int data;
	ListNode *next;
};

class List
{
public:
	List()
	{
		head = new ListNode;
		head->next = NULL;
	}

	~List()
	{
		ListNode* curNode;
		while (head->next)
		{
			curNode = head->next;
			head->next = curNode->next;
			delete curNode;
		}
		delete head;
	}
	//在链表第pos(pos>0)个结点之前插入新结点，新结点的值为toadd
	//链表实际结点从1开始计数。
	//调用时需保证pos小等于链表实际结点数 
	void insert(int toadd, int pos);
	void remove(int pos);
	// Data field
	ListNode *head; //head指向虚拟头结点，head-next指向第一个实际结点
};


void List::insert(int toadd, int pos) {
	ListNode * temp = new ListNode;
	temp = head;
	for (int i = 1; i < pos; i++) {
		temp = temp->next;
	}
	ListNode * new_node = new ListNode;
	new_node->data = toadd;
	new_node->next = temp->next;
	temp->next = new_node; 
}

void List::remove(int pos) {
	ListNode * temp = new ListNode;
	temp = head;
	for (int i = 1; i < pos; i++) {
		temp = temp->next;
	}
	ListNode * todel = new ListNode;
	todel = temp->next;
	temp->next = todel->next;
	delete todel;
}
