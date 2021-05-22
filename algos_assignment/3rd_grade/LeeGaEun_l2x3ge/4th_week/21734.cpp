#include <iostream> 
#include <string>
#include<algorithm>
using namespace std;
int main(void) {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	string s;
	cin >> s;

	for (int i = 0;i < s.size();i++) {
		int k = s[i];
		int sum = 0;
		while (k) {
			sum += k % 10;
			k /= 10;
		}
		while (sum--) {
			cout << s[i];
		}
		cout << "\n";
	}
}
