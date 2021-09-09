#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int n, k, l;
bool body[101][101];
bool appl[101][101];
deque<pair<int, char>> d; // 방향전환
deque<pair<int, int>> vam;
int ans = 0;
int dir[4][2] = { {-1, 0}, {0, 1},{1, 0},{0, -1} }; //시계방향

int main() {
    int nowx = 0, nowy = 0; // x가 행 y가 열
    int dirx = 0, diry = 1; // 나아갈 방향 dir로 정하기
    cin >> n;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        appl[a - 1][b - 1] = true;
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;
        d.push_back({ x, c });
    }
    body[0][0] = true;
    vam.push_back({ 0,0 });
    while (true) {
        ans++;
        nowx += dirx;
        nowy += diry;
        if (body[nowx][nowy] == true || nowx < 0 || nowy < 0 || nowx >= n || nowy >= n) {
            //몸을 만나거나 벽에 부딪히면 break;
            cout << ans;
            return 0;
        }
        body[nowx][nowy] = true;
        vam.push_back({ nowx,nowy }); // 뱀 현재 위치 저장

        if (appl[nowx][nowy] == true) { //사과 있는 곳이면
            appl[nowx][nowy] = false;//사과 없앰, 꼬리 그대로
        }
        else {//꼬리이동, pop
            body[vam.front().first][vam.front().second] = false; // 꼬리 있던 부분 다시 빈칸으로
            vam.pop_front();
        }
        if (!d.empty()) {
            if (d.front().first == ans) { // 방향 바꿀 때이면
                char nextD = d.front().second;
                d.pop_front();
                if (nextD == 'L') {
                    if (dirx == 0 && diry == 1) // 오른쪽 가는 중에 왼쪽 회전
                        dirx = -1, diry = 0;
                    else if (dirx == 0 && diry == -1) // 왼쪽 가는 중에 왼쪽 회전
                        dirx = 1, diry = 0;
                    else if (dirx == -1 && diry == 0) // 위쪽 가는 중에 왼쪽 회전
                        dirx = 0, diry = -1;
                    else if (dirx == 1 && diry == 0) // 아래쪽 가는 중에 왼쪽 회전
                        dirx = 0, diry = 1;
                }
                if (nextD == 'D') {
                    if (dirx == 0 && diry == 1) // 오른쪽 가는 중에 오른쪽 회전
                        dirx = 1, diry = 0;
                    else if (dirx == 0 && diry == -1) // 왼쪽 가는 중에 오른쪽 회전
                        dirx = -1, diry = 0;
                    else if (dirx == -1 && diry == 0) // 위쪽 가는 중에 오른쪽 회전
                        dirx = 0, diry = 1;
                    else if (dirx == 1 && diry == 0) // 아래쪽 가는 중에 오른쪽 회전
                        dirx = 0, diry = -1;
                }
            }
        }
    }  
}
