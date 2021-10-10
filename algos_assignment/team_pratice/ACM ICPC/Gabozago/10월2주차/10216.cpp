#include <iostream>
#include <algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include<cmath>
using namespace std;
struct pos {
	int x;
	int y;
	int r;
}p;
int t, n;
int parent[3001];
int ans = 0;
int Find(int x) {
	if (parent[x] == x)return x;
	return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	int a = Find(x);
	int b = Find(y);

	if (a == b)return;
	else if(a != b)parent[a] = b;
}
int getDistance(int a, int b, int c, int d) {
	return pow(a - c, 2) + pow(b - d, 2);
  /*틀린계산
  return sqrt(pow(abs(a - c), 2) + pow(abs(b - d), 2));*/
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--) {
		vector<pos>v;
		cin >> n;
		for (int i = 0; i < n; i++) {
			parent[i] = i; //init
			int x, y, r;
			cin >> x >> y >> r;
			p.x = x; p.y = y; p.r = r;
			v.push_back(p);
		}
		ans = n; /*틀렸던 경우 -> ans=0 해놓고 ans++하는 경우 -> union을 통해 한 그룹이 되므로 n명에서 1명씩 빠지도록 생각해야되는듯 */
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (Find(i) == Find(j))continue; //이미 같은 그룹인 경우

				int x = v[i].x; int y = v[i].y; int r = v[i].r;
				int nx = v[j].x; int ny = v[j].y; int nr = v[j].r;
				if (getDistance(x, y, nx, ny) <= pow(r + nr,2)) {/*틀린코드 if (getDistance(x, y, nx, ny) <= r + nr) */
					Union(i, j);
					ans--;
				}
			}
		}
		cout << ans << '\n';
	}
}
