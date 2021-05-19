#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int d;
	int w;
}Assignment;

const int MAX = 1000;
int plan[MAX];

bool cmp(Assignment a, Assignment b) {
	if (a.w > b.w) {
		return true;
	}
	if (a.w == b.w) {
		if (a.d < b.d) {
			return true;
		}
	}
	return false;
}

int main() {
	int n, score = 0;
	cin >> n;

	vector<Assignment> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].d >> v[i].w;
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		int j = v[i].d - 1;

		while (1) {
			if (plan[j] == 0 || j < 0)
				break;
			j--;
		}
		if (j >= 0) {
			plan[j] = v[i].w;
		}
	}
	
	for (int i = 0; i < MAX; i++) {
		score += plan[i];
	}
	cout << score;
}
