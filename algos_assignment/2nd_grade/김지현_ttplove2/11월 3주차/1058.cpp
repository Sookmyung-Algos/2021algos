#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
int fri[50][50] = { 0, };

int solve()
{
	int n[50] = { 0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (fri[i][j] == 1) 
				n[i]++;
			else {
				for (int k = 0; k < N; k++) {
					if (fri[i][k] == 1 && fri[j][k] == 1) {
						n[i]++;
						break;
					}
				}
			}
		}
	}
	int maxn = 0;
	for (int i = 0; i < N; i++)
		maxn = max(maxn, n[i]);

	return maxn;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(); cout.tie();
	
	char c;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> c;
			if (c == 'Y') fri[i][j] = 1;
		}
	}
	cout << solve() << "\n";
	return 0;
}
