#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;



int main() {
	int n;
	while(cin >> n) {
		stack<int> s1, s2;
		int * arr;
		arr = new int[n];
		vector<char> op;
		int count = 1;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < n; i++) {
			
			while (true) {
				bool flag = false;
				if (s1.empty() && s2.empty()) {
					break;
				}
				if (!s1.empty() && s1.top() == count) {
					s1.pop();
					op.push_back('b');
					flag = true;
					count++;
				}
				if (!s2.empty() && s2.top() == count) {
					s2.pop();
					op.push_back('d');
					flag = true;
					count++;
				}
				if (flag == false) {
					break;
				}
			}

			if (s1.empty() || s1.top() > arr[i]) {
				s1.push(arr[i]);
				op.push_back('a');
			}
			else if (s2.empty() || s2.top() > arr[i]) {
				s2.push(arr[i]);
				op.push_back('c');
			}
			else {
				cout << 0;
				op.clear();
				break;
			}
			while (true) {
				bool flag = false;
				if (s1.empty() && s2.empty()) {
					break;
				}
				if (!s1.empty() && s1.top() == count) {
					s1.pop();
					op.push_back('b');
					flag = true;
					count++;
				}
				if (!s2.empty() && s2.top() == count) {
					s2.pop();
					op.push_back('d');
					flag = true;
					count++;
				}
				if (flag == false) {
					break;
				}
			}

		}
		for (int i = 0; i < op.size(); i++) {
			cout << op[i];
			if (i < op.size() - 1) {
				cout << ' ';
			}
		}
		cout << endl;
	}
	system("pause");
}