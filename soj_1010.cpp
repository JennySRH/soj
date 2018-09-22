
//soj_1010
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
int m = 0;int n = 0;
for (int i = 0; i < 10; i++) {
if (m == 5) {
c[i] = b[n++];
}
else if (n == 5) {
c[i] = a[m++];
}
else {
c[i] = a[m] < b[n] ? a[m++] : b[n++];
}
}
for (int i = 0; i < 10; i++) {
cout << c[i] << " ";
}
}
