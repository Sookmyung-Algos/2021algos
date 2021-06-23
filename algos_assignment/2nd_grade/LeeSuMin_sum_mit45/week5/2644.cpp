#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> chonsu; 
vector<bool> visit;
vector<int> chon;

// bfs 구현
void bfs(int x, int stack)
{
	visit[x] = true;
	chon[x] = stack;
	while (!chonsu[x].empty())
	{
		int num = chonsu[x].back();
		chonsu[x].pop_back();
		if (!visit[num])
		{
			bfs(num, stack + 1);
		}
	}
}

int main()
{

	int n; // 전체 사람 수
	int x,y; // 촌수 계산 두명
	int m; // 관계 개수
	int parent = 0, child = 0;

	cin >> n;
	cin >> x >> y;
	cin >> m;

	chonsu.resize(n + 1);
	visit.resize(n + 1, false);
	chon.resize(n + 1, 0);

	// 부모 자식 관계 입력
	for (int i = 0; i < m; ++i)
	{
		cin >> parent >> child;
		chonsu[parent].push_back(child);
		chonsu[child].push_back(parent);
	}

	bfs(x, 0);

	if (visit[y])
		cout << chon[y] << endl;
	else
		cout << -1 << endl;
	return 0;
}
