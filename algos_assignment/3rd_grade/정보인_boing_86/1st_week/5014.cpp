#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int f, s, g, u, d;
bool v[1000001] = { false, };
int c[1000001] = { 0, };
int ele[2] = { 0, 0 };
queue <int> q;

/*void bfs(int start) {
	int fl, nfl;
	q.push(start);
	v[start] = true;

	while (!q.empty()) {
		fl = q.front();
		q.pop();

		for (int i = 0; i <= 1; i++) {
			nfl = fl + ele[i];

			if (nfl >= 1 && nfl <= f && (v[nfl] == false)) {
				q.push(nfl);
				v[nfl] = true;
				c[nfl] = c[fl] + 1;
			}
		}
	}
	if (nfl == g) { //이 조건은 왜 안되지?
		cout << c[nfl];
	}
	else {
		cout << "use the staris";
	}
}*/

int main() {
	cin >> f >> s >> g >> u >> d;

	if (s == g) {
		cout << "0";
		return 0;
	}

	ele[0] = ele[0] + u;//up/down 표시
	ele[1] = ele[1] - d;

	int fl = 0, nfl = 0;
	q.push(s);
	v[s] = true;

	while (!q.empty()) {
		fl = q.front();
		q.pop();

		for (int i = 0; i <= 1; i++) {
			nfl = fl + ele[i];

			if (nfl > 0 && nfl <= f && v[nfl] == false) {
				q.push(nfl);
				v[nfl] = true;
				c[nfl] = c[fl] + 1;
			}
		}
	}
	//cout << c[g] << endl;
	
	if (c[g]) {
		cout << c[g];
	}
	else {
		cout << "use the stairs";
	}
}
