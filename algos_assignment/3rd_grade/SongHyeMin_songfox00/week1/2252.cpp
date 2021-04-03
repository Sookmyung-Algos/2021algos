#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int>v[100001];
int ind[100001] = { 0, };
int n, m;
queue<int>q;

void bfs() {
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0)	//차례가 됨
			q.push(i);
	}

	for (int i = 1; i <= n; i++) {
		int next = q.front();	
		q.pop();

		cout << next << ' ';

		for (int j = 0; j < v[next].size(); j++) {
			int nx = v[next][j];
			ind[nx]--;	//앞의 숫자를 하나 뺐으므로 차수-1
			if (ind[nx] == 0)	//in degree==0
				q.push(nx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		ind[b]++;
	}
	bfs();

	return 0;
}
