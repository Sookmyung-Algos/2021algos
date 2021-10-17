#include <iostream>
#include <algorithm>
using namespace std;
struct pos {
	int num, g, s, b;
}p[101];
int n;
bool cmp(struct pos p, struct pos q) {
	int pmul = p.g * p.s * p.b;
	int qmul = q.g*q.s*q.b;
	int psum = p.g + p.s + p.b;
	int qsum = q.g + q.s + q.b;
	if (pmul == qmul && psum == qsum)return p.num < q.num;
	if (pmul == qmul)return psum < qsum;
	return pmul < qmul;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		p[i].num = a;
		p[i].g = b;
		p[i].s = c;
		p[i].b = d;
	}
	sort(p, p + n, cmp);
	for (int i = 0; i < 3; i++) {
		cout << p[i].num << ' ';
	}
}
