#include <iostream>
using namespace std;
long long t, n, k, cur, del;
int main() {
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		if (k == 0) 
			cout << 4 * n<<"\n";
		else {
			cur = (1 + n) * n / 2 * 4;
			n = n + k; // 5+2 = 7
			k = 1 + k * 2; // 5
			k = (n - k) > 0 ? n - k : 0;
			del = (1 + k) * k / 2 * 4;

			cout << cur - del << "\n";
		}				
	}
}
