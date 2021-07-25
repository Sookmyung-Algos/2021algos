#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int N,cnt;
int dx[] = {0,2,2,0,-2,-2};
int dy[] = {2,1,-1,-2,-1,1};
map<pair<int,int>,int> visited;

void backtrack(int x, int y, int dir, int n) {
    if (n == 0) { //이동횟수가 n번이고,
        //map은 찾을 수 없을 때 end()를 반환
        if (visited.find({x,y}) != visited.end()) //(x,y)를 찾았으면
            ++cnt; //카운트
        return;
    }
    else if (visited.find({x,y}) != visited.end()) //이동횟수가 n번이 아니면 return;
        return;

    visited[{x, y}] = true; //이동횟수가 n번이 아니고, (x,y)도 찾지 못했을 경우 방문 표시

    int right = (dir + 1) % 6; //현재 위치에서 오른쪽으로 이동
    int left = (dir + 5) % 6; //현재 위치에서 왼쪽으로 이동
    backtrack(x+dx[right], y+dy[right], right, n-1); //오른쪽 노드로 이동
    backtrack(x+dx[left], y+dy[left], left, n-1); //왼쪽 노드로 이동

    visited.erase({ x,y });
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    visited[{0, 0}] = true;
    backtrack(0, 2, 0, n);
    cout << cnt << '\n';

    return 0;
}
