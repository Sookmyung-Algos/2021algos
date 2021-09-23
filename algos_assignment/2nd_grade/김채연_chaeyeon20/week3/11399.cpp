#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	init();
	int n;
	int sum = 0;
	int arr[1004];
	
	cin >> n;
	for (int i =1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr+1, arr + n+1);
	for (int i =1; i <= n; i++) {
		int t = arr[i] * (n-i+1);
		sum += t;
	}
	cout << sum;
	return 0;
}
