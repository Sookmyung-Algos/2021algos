#include<iostream>
#include<vector>
#include<queue>
using namespace std;

queue<int> q;
vector<vector<int>> num;
vector<int> visited;
vector<int> res;
int n;
void bfs() {
    while (!q.empty()) {
        int fro = q.front();
        q.pop();
        for (int i = 0; i < num[fro].size(); i++) {
            if (visited[num[fro][i]] == 1)continue; //방문한 경우 스킵
            else {      //방문 표시
                visited[num[fro][i]] = 1;
                q.push(num[fro][i]);  //결과를 큐에 저장
                res[num[fro][i]] = fro;
            }
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n + 1; i++) {
        vector<int> z;
        num.push_back(z);
        visited.push_back(0);
        res.push_back(0);
    }
    for (int i = 0; i < n - 1; i++) {
        vector<int> z;
        int a, b;
        scanf("%d %d", &a, &b); //각 노드에서 연결된 노드 표시
        num[a].push_back(b);
        num[b].push_back(a);
    }
    q.push(1);
    visited[1] = 1;
    bfs();
    for (int i = 2; i < res.size(); i++) {
        printf("%d\n", res[i]);     //결과 출력
    }

}
