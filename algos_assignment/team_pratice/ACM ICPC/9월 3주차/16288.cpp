#include <iostream>
#include <set>
using namespace std;

typedef pair<int,int> P;

int main() {
	int n, k, arr[101];
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
	set<P, greater<P>> s; set<P, greater<P>>::iterator it;
	for (int i = 0; i < k; ++i)
		s.insert({0, i});
	for (int i = 0; i < n; ++i) {
		int cur = arr[i];
		for (it = s.begin(); it != s.end(); it++) {
			if ((*it).first < cur) {
				s.erase(it);
				s.insert({cur, 0});
				break;
			}
		}
		if (it == s.end()) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}
