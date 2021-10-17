#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define endl "\n"
#define MAX 10 + 1
using namespace std;

int n, ans = 987654321;
int personNum[MAX]; //인구수
bool connection[MAX][MAX]; //구역 연결
bool select[MAX]; //조합 체크
bool visit[MAX]; //bfs

void input(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        personNum[i] = x;
    }

    for (int i = 1; i <= n; i++){
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++){
            int a;
            cin >> a;
            connection[i][a] = true; //연결
            connection[a][i] = true;
        }
    }
}

bool bfs(vector<int> v, bool t){ //connection check
    memset(visit, false, sizeof(visit)); //
    queue<int> q;
    q.push(v[0]);
    visit[v[0]] = true;
    int cnt = 1;

    while (q.empty() == 0){
        int x = q.front();
        q.pop();
        for (int i = 1; i <= n; i++){
             if (connection[x][i] == true && select[i] == t && visit[i] == false){
                //구역 연결, 선거구 확인, 방문 여부
                visit[i] = true;
                q.push(i);
                cnt++;
            }
        }
    }
    if (v.size() == cnt) return true; //선거구 일치
    return false;
}

bool check(){ //선거구 조건 체크: 포함된 구역의 개수, 모두 연결됐는지 여부
    vector<int> a, b;
    for (int i = 1; i <= n; i++){
        if (select[i] == true) a.push_back(i); // 1선거구 a
        else b.push_back(i);                   // 2선거구 b
    }
    
    if (a.size() == 0 || b.size() == 0) return false; //포함된 구역의 개수

    bool anow = bfs(a, true); //모두 연결됐는지
    if (anow == false) return false;
    bool bnow = bfs(b, false);
    if (bnow == false) return false;

    return true;
}

void calc(){ //인구수 차이
    int anum = 0, bnum = 0, difference;

    for (int i = 1; i <= n; i++){
        if (select[i] == true) anum = anum + personNum[i];
        else bnum = bnum + personNum[i];
    }
    difference = abs(anum - bnum);
    if (ans > difference) ans = difference;
}

void dfs(int idx, int cnt){ //조합
    if (cnt >= 1){
        if (check() == true)    calc();
    }
    for (int i = idx; i <= n; i++){
        if (select[i] == true)  continue;
        select[i] = true;
        dfs(i, cnt + 1);
        select[i] = false; 
    }
}
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    dfs(1, 0);
    if (ans == 987654321) cout << -1;
    else cout << ans;

    return 0;
}
 
