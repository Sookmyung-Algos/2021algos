#include <iostream>
using namespace std;

int main() {
	int t = 0;
	while (true) {
		int n;
		scanf("%d", &n);
		if (!n) break;
		char s[1000001];
		scanf("%s", s);
		int pi[1000001] = {0};
		for (int i = 1, j = 0; i < n; ++i) {
			while (j && s[i] != s[j])
				j = pi[j - 1];
			if (s[i] == s[j])
				pi[i] = ++j;
		}
		printf("Test case #%d\n", ++t);
		for (int i = 2; i <= n; ++i) {
			int ans = pi[i - 1];
			if (ans && !(i % (i - ans)))
				printf("%d %d\n", i, (i / (i - ans)));
		}
		printf("\n");
	}
	return 0;
}
