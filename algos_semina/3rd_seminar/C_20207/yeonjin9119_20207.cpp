#include <iostream>
using namespace std;
int arr[365] = { 0 };
bool visit[365];
int main() {
	int n, d1, d2,mx=0,my=0,sum=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d1 >> d2;
		for (; d1 <= d2; d1++) {
			if (visit[d1] == true) {
			}
			else {
				visit[d1] = true;
			}
			arr[d1]++;
		}
	}		
	int a = 0;
	while (a<366) {
		if (visit[a] == true) {
			mx = a;
			for (; visit[a] == true; a++) {
				if (arr[a] > my) {
					my = arr[a];
				}
			}
			mx = a - mx;
		}
		sum += mx * my;
		mx = 0, my = 0;
		a++;
	}
	cout << sum;
	return 0;
}
