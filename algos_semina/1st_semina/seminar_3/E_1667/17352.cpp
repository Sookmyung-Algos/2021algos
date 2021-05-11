#include <iostream>
#define MAX 300002
using namespace std;
int arr[MAX];

int func1(int a) {
	if (arr[a] == a) return a;
	return func1(arr[a]);
}

void func2(int a, int b) {
	a = func1(a);
	b = func1(b);
	if (a < b) arr[b] = arr[a];
	else arr[a] = arr[b];
}

int main() {
	int n, a, b;
	cin >> n;
	for (int i = 1; i <= n; i++)
		arr[i] = i;
	for (int i = 1; i < n - 1; i++) {
		cin >> a >> b;
		func2(a, b);
	}
	
	a = func1(1);
	for (int i = 2; i <= n; i++) {
		b = func1(i);
		if (a != b) {
			cout << a << " " << b << '\n';
			return 0;
		}
	}

	return 0;
}
