#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct info
{
	int y; 
	int x;
	bool checked;
};

int N, M, H;
int result = 0;

struct info house;
vector <info> mint;

void dfs(int y, int x, int cur, int cnt, int health) 
{
	if (cnt > result) 
    {
		if (abs(y - house.y) + abs(x - house.x) <= health)
			result = cnt;
	}
	if (health <= 0)
		return;
	for (int i = 0; i < mint.size(); i++)
    {
		int len = abs(mint[i].y - y) + abs(mint[i].x - x);
		if (len <= health && mint[i].checked == 0) 
        {
			mint[i].checked = 1;
			dfs(mint[i].y, mint[i].x, i + 1, cnt + 1, health - len + H);
			mint[i].checked = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> M >> H;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) 
        {
			int map;
            cin >> map;
			if (map == 1)
				house.y = i, house.x = j;
			else if (map == 2)
				mint.push_back({ i,j,0 });
		}
	}

	dfs(house.y, house.x, 0, 0, M);
	cout << result << endl;
	return 0;
}
