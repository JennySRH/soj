#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool can_be_the_same_stack(int * arr,int n,int i,int j) {
	if (arr[i] >= arr[j]) {
		return true;
	}
	for (int k = j + 1; k < n; k++) {
		if (arr[k] < arr[i]) {
			return false;
		}
	}
	return true;
}



void get_color( int color[], int pos,int n,bool ** same_stack) {
	stack<int> node;
	node.push(pos);
	color[pos] = 1;
	while (!node.empty()) {//深度优先搜索
		bool flag = false;
		int temp = node.top();
		for (int i = 0; i < n; i++) { //遍历与temp相邻的点
			if (same_stack[temp][i] == false && !color[i]) { //如果相邻并且没有被染色
				if (color[temp] == 1) {
					color[i] = 2;
				}
				else {
					color[i] = 1;
				}
				node.push(i);
				flag = true;
				break;
			}
		}
		if (flag == false) {
			node.pop();
		}
	}
}

int main() {
	int n;
	while (cin >> n) {
		int * arr;
		arr = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		bool ** same_stack;
		same_stack = new bool*[n];
		for (int i = 0; i < n; i++) {
			same_stack[i] = new bool[n];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				same_stack[i][j] = true;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				same_stack[i][j] = can_be_the_same_stack(arr,n,i,j);
				same_stack[j][i] = same_stack[i][j];
			}
		}

		int color[1001] = {0};
		for (int i = 0; i < n; i++) {
			if (!color[i]) {
				get_color(color, i, n, same_stack);
			}
		}
		bool flag = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (same_stack[i][j] == false) {
					if (color[i] == color[j]) {
						flag = false;
					}
				}
			}
		}

		if (flag == false) {
			cout << 0 << endl;
		}
		else {
			int count = 1;
			stack<int> s1;
			stack<int> s2;
			vector<char> op;
			for (int i = 0; i < n; i++) {
				if (arr[i] == count) {
					count++;
					if (color[i] == 1) {
						op.push_back('a');
						op.push_back('b');		
					}
					else {
						op.push_back('c');
						op.push_back('d');
					}
					while (true) {
						if (!s1.empty() && s1.top() == count) {
							s1.pop();
							op.push_back('b');
							count++;
						}
						else if(!s2.empty() && s2.top() == count){
							s2.pop();
							op.push_back('d');
							count++;
						}
						else {
							break;
						}
					}
				}
				else {
					if (color[i] == 1) {
						s1.push(arr[i]);
						op.push_back('a');
					}
					else {
						s2.push(arr[i]);
						op.push_back('c');
					}
				}
			}

			for (int i = 0; i < op.size(); i++) {
				cout << op[i];
				if (i < op.size() - 1) {
					cout << " ";
				}
			}
			cout << endl;

		}





	}
}