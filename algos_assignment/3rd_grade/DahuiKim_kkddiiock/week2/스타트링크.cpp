#include<iostream>
#include<queue>
using namespace std;
int f, s, g, u, d;
int ans = -1;
bool v[1000001] = { 0, };
queue <pair<int, int>>q;
void bfs();
int main(){
	cin >> f >> s >> g >> u >> d;
	q.push(make_pair(s, 0));
	v[s] = 1;
	bfs();
	if (ans != -1) cout << ans << endl;
	else cout << "use the stairs" << endl;
	return 0;
}
void bfs() {
	while (!q.empty()) {
		int curr_floor = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (curr_floor == g) {
			ans = cnt;
			break;
		}//10 1 10 2 1
		if (curr_floor + u <= f&&v[curr_floor+u]==0) {
			int next_floor = curr_floor + u;
			int next_cnt = cnt + 1;
			v[next_floor] = 1;
			q.push(make_pair(next_floor, next_cnt));
		}
		if (curr_floor-d >= 1 && v[curr_floor - d] == 0) {
			int next_floor = curr_floor - d;
			int next_cnt = cnt + 1;
			v[next_floor] = 1;
			q.push(make_pair(next_floor, next_cnt));
		}

	}
}
