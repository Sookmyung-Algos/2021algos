#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> crane, box;
int avail[10000];

int main(void) {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int c, num, val, idx = 0, cnt = 0, t = 0;
	cin >> c;
    
	for (int i = 0; i < c; i++) {
		cin >> val;
		crane.push_back(val);
	}
	sort(crane.begin(),crane.end());
    
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> val;
		box.push_back(val);
	}
	sort(box.begin(), box.end());
    
	if (crane[c - 1] < box[num - 1]) {
		cout << -1;
		return 0;
	}
    
	for (int i = 0; i < num; i++) {
		if (crane[idx] >= box[i]) 	avail[idx]++;		
		else {
			idx++;
			i--;
		}
	}
    
	while (1) {
		for (int i = c - 1; i >= 0; i--) {
			for (int j = i; j >= 0; j--) {
				if (avail[j]) {
					avail[j]--;
					cnt++;
					break;
				}
			}
			if (cnt == num) break;
		}
		t++;
		if (cnt == num) break;
	}
	cout << t;
	return 0;
}
