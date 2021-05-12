#include <algorithm>
#include <string>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}
int n;
int k;
string num;
int main() {
	init();


	cin >> n >> k;
	cin >> num;
	deque <char> arr;
	
	int n = num.size();
	for (int i = 0; i < n; i++) {
		while (k && !arr.empty() && arr.back() <num[i]) {
			arr.pop_back();
			k--;
		}
		arr.push_back(num[i]);
	}
	for (int i = 0; i < arr.size() - k; i++) {
		cout << arr[i];
	}
	return 0;
}
