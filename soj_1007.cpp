#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct twin{
	bool flag;
	int p;
};

bool front_is_max(queue<twin> a) {
	int temp = a.front().p;
	while (!a.empty()) {
		if (temp < a.front().p) {
			return false;
		}
		a.pop();
	}
	return true;
}

int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		int n, pos;
		cin >> n >> pos;
		queue<twin> priority;
		for (int j = 0; j < n; j++) {
			twin temp;
			cin >> temp.p;
			if (j == pos) {
				temp.flag = true;
				priority.push(temp);
			}
			temp.flag = false;
			priority.push(temp);
		}
		int minute = 0;
		while (true) {
			if (front_is_max(priority) && priority.front().flag == true) {
				minute++;
				cout << minute << endl;
				break;
			}
			else if (front_is_max(priority)) {
				priority.pop();
				minute++;
			}
			else {
				priority.push(priority.front());
				priority.pop();
			}
		}


	}
	system("pause");
}