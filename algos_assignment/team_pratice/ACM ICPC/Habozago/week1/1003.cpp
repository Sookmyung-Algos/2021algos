#include <iostream>
#include <string>
using namespace std;
long long fiboarr[50] = { 0, 1, };

long long fibonacci(int n) {
	if (n == 0 || n == 1) {
		return fiboarr[n];
	} 
	else if(fiboarr[n] == 0){
		fiboarr[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
	return fiboarr[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, num;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> num;
		if (num == 0) cout << "1 0\n";
		else {
			cout << fibonacci(num - 1) << " " << fibonacci(num) << "\n";
		}
	}
}
