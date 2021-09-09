#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Time {
	int start;
	int finish;
};

bool cmp(Time f, Time s) {
	if (f.finish == s.finish) return (f.start < s.start);
	else return (f.finish < s.finish);
}

int main() {
	int N;
	cin >> N;

	vector <Time> t(N);
	for (int i = 0; i<N; i++) {
		cin >> t[i].start >> t[i].finish;
	}
	sort(t.begin(), t.end(), cmp);

	int cnt = 0;
	int n = 0;

	for (int i = 0; i<t.size(); i++) {
		if (n <= t[i].start) {
			n = t[i].finish;
			cnt++;
		}
	}
	cout << cnt << endl;
}
