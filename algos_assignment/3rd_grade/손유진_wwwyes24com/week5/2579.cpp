#include <iostream>
using namespace std;

int main() {
	int n;
	int stair[310];
	int res[310];

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> stair[i];

	res[0] = 0, stair[0] = 0;
	res[1] = stair[1];
	res[2] = stair[1] + stair[2];
	
	for (int i = 3; i <= n; i++) 
		res[i] = max(res[i - 3] + stair[i - 1] + stair[i], res[i - 2] + stair[i]);

	cout << res[n];
}
