#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		stack<char> s;
		bool flag = true;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(') {
				s.push(str[j]);
			}
			else if (str[j] == '[') {
				if (s.empty()) {
					s.push(str[j]);
				}
				else if (s.top() == '(') {
					cout << "No" << endl;
					flag = false;
					break;
				}
				else {
					s.push(str[j]);
				}
			}
			else if (str[j] == '{') {
				if (s.empty()) {
					s.push(str[j]);
				}
				else if (s.top() == '(' || s.top() == '[') {
					cout << "No" << endl;
					flag = false;
					break;
				}
				else {
					s.push(str[j]);
				}
			}
			else if (str[j] == ')') {
				if (s.empty() || s.top() != '(') {
					cout << "No" << endl;
					flag = false;
					break;
				}
				s.pop();
			}
			else if (str[j] == ']') {
				if (s.empty() || s.top() != '[') {
					cout << "No" << endl;
					flag = false;
					break;
				}
				s.pop();
			}
			else if (str[j] == '}') {
				if (s.empty() || s.top() != '{') {
					cout << "No" << endl;
					flag = false;
					break;
				}
				s.pop();
			}
			
		}
		if (!s.empty()&& flag == true) {
			cout << "NO" << endl;
		}
		else if (flag == true) {
			cout << "Yes" << endl;
		}
	}
	system("pause");
}