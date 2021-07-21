#include <iostream>
#include <queue>
using namespace std;
int main() {
    int count = 0;
    int test_case;
    cin >> test_case;
    int n, m, ipt;//문서의 개수, 궁금한 문서 위치, 중요도
    for (int i = 0; i < test_case; ++i) {
        count = 0;
        cin >> n >> m;
        queue<pair<int, int>> q;
        priority_queue<int> pq; // 우선순위 큐
        for (int j = 0; j < n; ++j) {
            cin >> ipt;
            q.push({ j, ipt });// 일반 큐에는 인덱스와 우선순위를 묶어 저장
            pq.push(ipt);//우선순위가 높은 수가 가장 뒤에(->선입선출) 있음
        }
        while (!q.empty()) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop(); //가장 먼저 들어온 것을 없앰(=가장 뒤에 있는것)
            if (pq.top() == value) {//동일 => 현재 index == 목표index인지 확인
                pq.pop();
                ++count;
                if (index == m) {
                    cout << count << endl;
                    break;
                }
            }
            /*만약 우선순위 큐의 front!= 큐의 front
            => 다시 맨 앞으로 넣어줌
            (=until 우선순위가 높은 것이 pop될 때 까지)*/
            else q.push({ index,value });
        }
    }
}
1926
#include <iostream>
#include <queue>
using namespace std;
bool visit[501][501] = { false };
int pic[501][501] = { 0 };
int dx[4] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
void bfs(int a,int b) {
    queue<pair<int,int>> q;
    pair<int, int> n;
    int count = 0;
    int max = 0;
    int area = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (pic[i][j] == 1 && !visit[i][j]) {
                q.push({ i, j });
                visit[i][j] = true;
                count++;
            }

            while (!q.empty()) {
                n = q.front();
                q.pop();

                area++;


                for (int k = 0; k < 4; k++) {
                    if (n.first + dx[k] < 0 || n.first + dx[k] >= a || n.second + dy[k] < 0 || n.second + dy[k] >= b) {
                        continue;
                    }
                    if (pic[n.first + dx[k]][n.second + dy[k]] == 1 && visit[n.first + dx[k]][n.second+ dy[k]] == false) {
                        q.push({ n.first + dx[k],n.second + dy[k] });
                        visit[n.first + dx[k]][n.second + dy[k]] = true;
                    }
                }
            }
            if (max < area) {
                max = area;
            }
            area = 0;
        }
    }
    cout << count << endl << max;
}
int main() {
    int n, m;
    cin >> n>> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> pic[i][j];
        }
    }
    bfs(n,m);
}
