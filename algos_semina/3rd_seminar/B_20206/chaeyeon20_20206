#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm> 
#include <queue>

#include <time.h>
#define MAX 100001
using namespace std;
int a, b, c;
int f;
int cmp[4];
int x11, x22, y11, y22;
vector <pair<int, int>> vect;
void aaa() {
	for (int i = 0; i < 4; i++) {
		if (cmp[i] == 1 || cmp[i] == 0) {
			f = cmp[i];
			return;
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> a >> b >> c;
	cin >> x11 >> x22 >> y11 >> y22;

	vect.push_back({ x11,y11 });
	vect.push_back({ x22,y22 });
	vect.push_back({ x22,y11 });
	vect.push_back({ x11,y22 });
	
	
	int chk[2] = { 0 };
	for (int i = 0; i < 4; i++) {
		if (vect[i].first * a + vect[i].second * b <= -c) {
			chk[0]++;
		}
		if (vect[i].first * a + vect[i].second * b >= -c) {
			chk[1]++;
		}
	}
	if (chk[0] == 4 || chk[1] == 4) {
		cout << "Lucky";
	}
	else cout << "Poor";
	return 0;
}
