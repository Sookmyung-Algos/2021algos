#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	char n[11];
	cin >> n;
	sort(n, n + strlen(n), greater<>());
	cout << n;
	return 0;
}
