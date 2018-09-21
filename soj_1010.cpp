#include <iostream>
#include <vector>
using namespace std;
int main() {
	int a[5];
	int b[5];
	int c[10];
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 5; i++) {
		cin >> b[i];
	}
	int m = n = 0;
	for (int i = 0; i < 10; i++) {
		c[i] = a[m] < b[n] ? a[m] : b[n];
	}
}