#include <iostream>
#include <algorithm>
using namespace std;
int n, m, b;
int block[2500000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> b;
	
	for (int i = 0; i < n*m; i++) {
		cin >> block[i];
	}
	int Min = *min_element(block, block + n * m);
	int Max = *max_element(block, block + n * m);

	int h_plus = 0;
	int h_minus = 0;
	int H = 0;
	long long Shortest_time = 100000000000000000;
	int longest_h = 0;

	for (int H = 0; H <= 256; H++) {
		for (int i = 0; i < n * m; i++) {
			if (H > block[i]) {
				h_minus += (H - block[i]);
			}
			else if (H < block[i]){
				h_plus += (block[i] - H);
			}
		}
		int time = h_plus * 2 + h_minus;
		if (time < Shortest_time && h_minus <= b+h_plus) {
			Shortest_time =time;
			longest_h = H;
		}
		else if (time == Shortest_time && h_minus <= b+h_plus) {
			if (longest_h < H) {
				longest_h = H;
			}
		}
		h_plus = 0;
		h_minus = 0;
	}
	
	cout << Shortest_time <<" " << longest_h;
	
}
