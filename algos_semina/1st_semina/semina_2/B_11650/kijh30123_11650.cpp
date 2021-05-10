#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>>v;
vector<int> vdata;

struct data
{
	int Xi;
	int Yi;
} m[100000];

bool cmp(struct data a, struct data b) {
	if (a.Xi == b.Xi) return a.Yi < b.Yi;
	return a.Xi < b.Xi;
}

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	int N, X, Y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X >> Y;
		m[i].Xi = X;
		m[i].Yi = Y;
	}
	sort(m, m + N, cmp);
	for (int i = 0; i < N; i++) {
		cout << m[i].Xi << " " << m[i].Yi << "\n";
	}
	return 0;
}
