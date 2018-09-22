//soj_1011
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct node {
	int exponent;
	int coficient;
	node * next;
};

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int count = 0;
		int an, bn;
		node * ahead;
		ahead = new node;
		node * atemp = new node;
		atemp = ahead;
		cin >> an;
		for (int j = 0; j < an; j++) {
			node * temp = new node;
			cin >> temp->coficient;
			cin >> temp->exponent;
			atemp->next = temp;
			atemp = atemp->next;
		}
		atemp->next = NULL;

		node * bhead;
		bhead = new node;
		node * btemp = new node;
		btemp = bhead;
		cin >> bn;
		for (int j = 0; j < bn; j++) {
			node * temp = new node;
			cin >> temp->coficient;
			cin >> temp->exponent;
			btemp->next = temp;
			btemp = btemp->next;
		}
		btemp->next = NULL;

		atemp = ahead;
		btemp = bhead;
		node * chead = new node;
		node * ctemp = new node;
		ctemp = chead;
		while (atemp->next != NULL && btemp->next != NULL) {
			if (atemp->next->exponent > btemp->next->exponent) {
				count++;
				node * temp = new node;
				temp->coficient = atemp->next->coficient;
				temp->exponent = atemp->next->exponent;
				ctemp->next = temp;
				ctemp = ctemp->next;
				atemp = atemp->next;
			}
			else if (atemp->next->exponent < btemp->next->exponent) {
				count++;
				node * temp = new node;
				temp->coficient = btemp->next->coficient;
				temp->exponent = btemp->next->exponent;
				ctemp->next = temp;
				ctemp = ctemp->next;
				btemp = btemp->next;
			}
			else {
				node * temp = new node;
				temp->coficient = atemp->next->coficient + btemp->next->coficient;
				if (temp->coficient == 0) {
					atemp = atemp->next;
					btemp = btemp->next;
				}
				else {
					count++;
					temp->exponent = btemp->next->exponent;
					ctemp->next = temp;
					ctemp = ctemp->next;
					atemp = atemp->next;
					btemp = btemp->next;
				}
				
			}
		}
		while (atemp->next) {
			count++;
			node * temp = new node;
			temp->coficient = atemp->next->coficient;
			temp->exponent = atemp->next->exponent;
			ctemp->next = temp;
			ctemp = ctemp->next;
			atemp = atemp->next;
		}
		while (btemp->next) {
			count++;
			node * temp = new node;
			temp->coficient = btemp->next->coficient;
			temp->exponent = btemp->next->exponent;
			ctemp->next = temp;
			ctemp = ctemp->next;
			btemp = btemp->next;
		}
		ctemp->next = NULL;
		cout << count << endl;
		while (chead->next) {
			cout << chead->next->coficient << " " << chead->next->exponent << endl;
			chead = chead->next;
		}

		system("pause");

	}
}

