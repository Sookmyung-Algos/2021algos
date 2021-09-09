#include <iostream>
#include <vector>
using namespace std;

int arr[10001];

int main() {

	for (int i = 1; i <= 10000; i++) {
		int n;
		n = i + i / 1000 + i / 100 % 10 + i / 10 % 10 + i % 10;
		arr[n] = 1; 
	}

	for (int i = 1; i <= 10000; i++) {
		if (arr[i] == 0)
			cout << i << "\n";
	}

	return 0;
}
