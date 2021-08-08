#include <iostream>
#include <vector>
using namespace std;

int n, m, h;
int ans = 0;  // 마실 수 있는 우유 개수
vector<pair<int, int>> milk;  // 우유의 위치를 좌표로 저장
pair<int, int> house;  // 집 위치를 좌표로 저장
bool visited[10];

void dfs(pair<int, int> curLocation, int life, int cnt) {
    int houseDist = abs(curLocation.first - house.first) + abs(curLocation.second - house.second);
    if (houseDist <= life)  // 현재 체력으로 집 도착 가능하다면
        ans = max(ans, cnt);  // 더 큰 값으로 ans 값 갱신
    if (life <= 0 || cnt == milk.size())
        return;

    for (int i = 0; i < milk.size(); i++) {
        int dist = abs(curLocation.first - milk[i].first) + abs(curLocation.second - milk[i].second);
        if (dist <= life && !visited[i]) {  // 
            visited[i] = true;
            dfs(milk[i], life - dist + h, cnt + 1);
            visited[i] = false;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> h;
    int input;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> input;
            if (input == 1) {
                house.first = i;
                house.second = j;
            }
            else if (input == 2)
                milk.push_back({ i,j });
        }
    }

    dfs(house, m, 0);
    cout << ans;
    return 0;
}
