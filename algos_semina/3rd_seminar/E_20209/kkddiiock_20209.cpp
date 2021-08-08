#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int n,k;
bool flag = true;
vector<int> btn[8];
bool check(vector<int>& v);
vector<int> pushButton(vector<int>& cube, int n);
int bfs(vector<int>& v);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    vector<int> cube(n);//큐브의 개수 N만큼 큐브 벡터 생성
    //N개의 큐브 위에 쓰여 있는 숫자를 cube 벡터에 저장
    for (int i = 0; i < n; i++) cin >> cube[i];
    for (int i = 0; i < k; i++) {
        int n; 
        cin >> n;//각 스위치에 연결된 큐브의 개수
        while (n--) {//연결된 큐브의 번호들을 저장
            int num;
            cin >> num;
            btn[i].push_back(num);
        }
    }
    cout << bfs(cube);//bfs로 최소 횟수를 탐색, 출력
    return 0;
}
int bfs(vector<int>& v) {
    map<vector<int>, int> m;//벡터를 key로 갖는 map 자료구조
    queue<vector<int>> q;//bfs를 위한 큐
    m[v] = 0;
    q.push(v);
    while (!q.empty()) {
        vector<int> current;
        current= q.front();
        q.pop();
        int cnt = m[current];
        if (check(current)) return cnt;//큐브의 값이 모두 동일하면
        for (int i = 0; i < k; i++) {//모든 값이 동일해질때까지 버튼 누르기
            vector<int> next = pushButton(current, i);
            if (m.find(next) == m.end()) {//map의 처음부터 끝까지
                m[next] = cnt + 1;
                q.push(next);
            }
        }
    }
    return -1;
}
vector<int> pushButton(vector<int>& cube, int n) {
    vector<int> v = cube;
    for (int i : btn[n]) v[i - 1] = (v[i - 1] + n + 1) % 5;
    return v;
}
bool check(vector<int>& v) {
    int n = v[0];
    for (int i : v) if (n != i) return false;
    return true;
}
