#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, in[100001], x;
	scanf("%d", &n);
	for(int i= 0; i < n; ++i)
		scanf("%d", &in[i]);
	scanf("%d", &x);
	sort(in, in + n);
	int a = 0, b = n - 1, ans = 0;
	while (true){
		if (a >= b)
			break;
		if (in[a] + in[b] == x) {
			++ans;
			--b;
		}
		else if (in[a] + in[b] < x)
			++a;
		else
			--b;
	}
	printf("%d", ans);
	return 0;
}
