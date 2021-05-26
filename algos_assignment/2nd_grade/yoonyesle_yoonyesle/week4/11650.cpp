#include <iostream>
#include <algorithm>
using namespace std;

struct loc{
	int x, y;
} a[100001];

bool cmp(loc a, loc b) {
	return a.x!=b.x?a.x<b.x:a.y<b.y;
}

int main() {
	int n, i;
	cin >> n;
	for(i=0; i<n; i++)
		cin >> a[i].x >> a[i].y;
	sort(a, a+n, cmp );
	for(i=0; i<n; i++)
		cout << a[i].x << ' ' << a[i].y << '\n';
	return 0;
}
