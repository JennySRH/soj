#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <sstream>
#include<iomanip>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		stack<double> s;
		for (int j = 0; j < str.size(); j++) {
			if (isalpha(str[j])) {
				s.push(str[j]-'a'+1);
			}
			else {
				double a = s.top();
				s.pop();
				double b = s.top();
				s.pop();
				double c;
				if (str[j] == '+') {
					c = b + a;
				}
				else if (str[j] == '-') {
					c = b - a;
				}
				else if (str[j] == '*') {
					c = b * a;
				}
				else if (str[j] == '/') {
					c = b / a;
				}
				s.push(c);
			}
		}
		cout << fixed << setprecision(2)<<s.top() << endl;
	}
	system("pause");
}