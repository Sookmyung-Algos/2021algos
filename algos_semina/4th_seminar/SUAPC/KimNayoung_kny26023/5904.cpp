#include <iostream>
#define n_ 2200
using namespace std;

typedef long long ll;
ll n, k, s;

int main(void) {
	cin >> n;
	k = 4;
	s = 3;
	while (n > s) {
		s = s * 2 + k;
		k += 1;
	}
	k -= 1;
	while (1) {
		ll t = (s - k) / 2;
		if (n <= t) {
			k--;
			s = t;
		}
		else if (n > t + k) {
			n -= (t + k);
			k--;
			s = t;
		}
		else {
			n -= t;
			break;
		}
	}
	if (n == 1) {
		cout << 'm' << endl;
	}
    else{
		cout << 'o' << endl;
	}
	return 0;
}
