#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[300001];
int flag[300001]; //도달할 수 있는 마을인지 구분.

int main()
{
	int node, s, e, idx = 0;

	cin >> node;

	for (int i = 0; i < node - 2; i++) { //vertor v에 존재하는 다리 저장.
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}

	queue<int> q;
	q.push(1);
	flag[1] = 1;

	while (!q.empty()) { // 1에서 도달할 수 있는 모든 마을의 flag = 1.
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i];
			if (flag[next] == 0) {
				flag[next] = 1;
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= node; i++) { 
		if (flag[i] == 0) { //flag 값이 0이면 idx에 저장.
			idx = i;
			break;
		}
	}

	cout << 1 << " " << idx; //위에서 저장된 idx값 출력.

	return 0;
}
