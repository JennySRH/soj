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
	//�������pos(pos>0)�����֮ǰ�����½�㣬�½���ֵΪtoadd
	//����ʵ�ʽ���1��ʼ������
	//����ʱ�豣֤posС��������ʵ�ʽ���� 
	void insert(int toadd, int pos);
	void remove(int pos);
	// Data field
	ListNode *head; //headָ������ͷ��㣬head-nextָ���һ��ʵ�ʽ��
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
