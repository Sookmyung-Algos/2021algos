// icpc D번

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int n, m;
bool arr[1005][1005];      //연결 확인
vector <int> v[1005];      //연결 저장
vector <int> group1;
vector <int> group2;
bool visit[1005];         //백트레킹 방문
bool check2[1005];
int ssize;
int result = 1001;

void bt(int idx);
int check(vector<int> group);

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> n >> m;
    memset(arr, false, sizeof(false));

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a][b] = true;
        arr[b][a] = true;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (v[i].size() == 0) {
            cout << "-1";
            return 0;
        }
    }

    memset(visit, false, sizeof(false));

    visit[1] = true;
    ssize = v[1].size();
    visit[v[1][0]] = true;
    bt(0);
    visit[v[1][0]] = false;
    bt(0);

    if (result == 1001)
        cout << "-11";
    else
        cout << result;
}

void bt(int idx) {
    if (idx == ssize - 1) {
        while (!group1.empty())
            group1.pop_back();

        while (!group2.empty())
            group2.pop_back();

        group1.push_back(1);
        for (int i = 0; i < v[1].size(); i++) {   //그룹벡터에 선택된 아이들 넣음
            if (visit[v[1][i]]) {
                group1.push_back(v[1][i]);
                cout << "그룹1" << i << ' ';
            }
        }

        for (int i = 1; i <= n; i++)
            check2[i] = false;
        for (int i = 0; i < group1.size(); i++) {
            check2[group1[i]] = true;
        }

        for (int i = 1; i <= n; i++) {
            if (!check2[i]) {
                group2.push_back(i);
                cout << "그룹2" << i << ' ';
            }
        }

        int a = check(group1);
        int b = check(group2);
        cout << a << " " << b << ' ';
        int temp = abs(a - b);
        if (a <= 0 || b <= 0) {
            temp = 1001;
        }
        result = (result > temp) ? temp : result;
        cout << "작동\n";
        return;
    }

    visit[v[1][idx + 1]] = true;
    //cout << "bt" << idx+1 << "\n";
    bt(idx + 1);
    visit[v[1][idx + 1]] = false;
    bt(idx + 1);

}

int check(vector<int> group) {
    int num = group.size();

    if (num == 1) {
        return -1;
    }

    bool flag = true;
    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            if (!arr[group[i]][group[j]]) {
                flag = false;
                break;
            }
        }
    }



    if (flag) {
        return num;
    }
    else
        return -1;
}
