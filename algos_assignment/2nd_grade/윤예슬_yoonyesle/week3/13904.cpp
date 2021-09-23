#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{
	int d, w;
} s_in;

bool comp(s_in a, s_in b) {
	if (a.w == b.w)
		return a.d < b.d;
	return a.w > b.w;
}

int main() {
	int n, days[1001] = {0};
	s_in in[1001];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &in[i].d, &in[i].w);
	sort(in, in + n, comp);
	for (int i = 0; i < n; ++i) {
		int j = in[i].d;
		while (j > 0) {
			if (!days[j]) {
				days[j] = in[i].w;
				break;
			}
			--j;
		}
	}
	int sum = 0;
	for (int i = 0; i < 1001; ++i) {
		sum += days[i];
	}
	printf("%d", sum);
	return 0;
}
