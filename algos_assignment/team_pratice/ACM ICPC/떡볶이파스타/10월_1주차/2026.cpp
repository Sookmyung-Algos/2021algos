#include <iostream>
using namespace std;

int visit[902];
int relation[902][902];
bool check = false; // 맨 처음 구한 값 후에는 return 하기 위해
int k, n, f, a, b;

bool friendcheck(int idx);
void combination(int num, int idx);

int main(){
    cin >> k >> n >> f;
    for (int i = 0; i < f; i++) {
        cin >> a >> b;
        relation[a][b] = 1;
        relation[b][a] = 1;
    }
    for (int i = 1; i <= n; i++) {// nCk할 점 선택
        if (check == true) break;
        if (!visit[i] && (n - i + 1) >= k) {
            visit[i] = true;
            combination(1, i);
            visit[i] = false;
        }
    }

    if (check == false) cout << "-1" << "\n";
    return 0;
}
bool friendcheck(int idx) {
    for (int i = 1; i <= n; i++) {
        if (visit[i] == true) {
            if (relation[i][idx] == 0)  return false;
        }
    }
    return true;
}
void combination(int num, int idx) {
    if (check == true) return;
    if (num == k) {
        check = true;
        for (int i = 1; i <= n; i++) {
            if (visit[i] == true) {
                cout << i << "\n";
            }
        }
        return;
    }

    for (int i = idx + 1; i <= n; i++) {
        if (!visit[i] && (num + n - i + 1) >= k && (relation[idx][i] == 1 || relation[i][idx] == 1)) {
            if (friendcheck(i) == false) continue;
            visit[i] = true;
            combination(num + 1, i);
            visit[i] = false;
        }
    }
}
