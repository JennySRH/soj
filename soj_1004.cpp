#include<iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	stack<char> s;
	string post;
	for (int i = 0; i < str.size(); i++) {
		if (isalpha(str[i])) {
			post += str[i];
		}
		else {
			bool flag = true;
			while (flag) {
				if (s.empty() || ( (str[i] != '+' && str[i] != '-') && (s.top() == '+' || s.top() == '-') ) ) {
					s.push(str[i]);
					flag = false;
				}
				else {
					post += s.top();
					s.pop();
				}
			}
			
		}
	}
	while (!s.empty()) {
		post += s.top();
		s.pop();
	}
	cout << post;
	system("pause");
}