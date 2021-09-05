
#include<iostream> 
#include<vector>

using namespace std;
int t;
unsigned long long n, k, ans2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	vector <long long> v;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		unsigned long long ans1 = n*(n + 1) / 2;
		if (n > k+1) {
			ans2 = (n - k)*(n - k - 1) / 2;
		}
		else {
			ans2 = 0;
		}
		cout << (ans1 - ans2) * 4 << '\n';
	}
}
