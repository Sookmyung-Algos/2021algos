#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct medal {
	int num;
	int gold;
	int silver;
	int bronze;
}p[1001];
int n, m;
vector<medal>v;
bool cmp(struct medal p1, struct medal p2) {
	if (p1.gold > p2.gold)return true;
	else if (p1.gold == p2.gold) {
		if (p1.silver > p2.silver)return true;
		if (p1.silver == p2.silver) {
			if (p1.bronze > p2.bronze)return true;
			//동일한 순위일때 m번째 나라가 먼저 오도록
			else if (p1.bronze == p2.bronze)return p1.num == m;
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int k, a, b, c;
		cin >> k >> a >> b >> c;
		p[i].num = k;
		p[i].gold = a;
		p[i].silver = b;
		p[i].bronze = c;
		v.push_back(p[i]);
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		if (v[i].num == m) {
			cout << i + 1;
			break;
		}
	}
	return 0;
}
