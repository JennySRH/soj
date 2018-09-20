#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		stack<char> s;
		cin >> temp;
		int mid = 999;
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j] == '_') {
				mid = j;
				break;
			}
			s.push(temp[j]);
		}
		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
		if(mid != 999)
			cout << '_';
		for (int j = mid+1; j < temp.size(); j++) {
			s.push(temp[j]);
		}
		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
		cout << endl;
	}
	
}