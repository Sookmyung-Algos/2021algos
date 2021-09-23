#include <iostream>
using namespace std;

int main() {
	int n;
	long long line[100] = { 0, };
	long long peri[100] = { 0, };
	cin >> n;

	line[1] = 1, line[2] = 1;
	peri[1] = 4, peri[2] = 6;
	
	for (int i = 3; i <= n; i++) {
		line[i] = line[i - 1] + line[i - 2];
		peri[i] = (line[i] * 2 + line[i - 1]) * 2;
	}

	cout << peri[n];
}
