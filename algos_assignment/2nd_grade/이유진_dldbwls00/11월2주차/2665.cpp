#include<iostream>
#include<queue>
#include<string>
using namespace std;
#define MAX 50

int n;
int map[MAX][MAX];
int visited[MAX][MAX];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int returnmin(int a, int b) {
    if (a < b) return a;
    return b; 
}
void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)    map[i][j] = s[j] - '0';
    }
}
void solution(){
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++)   visited[i][j] = 987654321;

    }
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = 0;

    while (q.empty() == 0){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n){
                if (map[nx][ny] == 1){
                    if (visited[nx][ny] > visited[x][y]){
                        visited[nx][ny] = visited[x][y];
                        q.push(make_pair(nx, ny));
                    }
                }
                else{
                    if (visited[nx][ny] > visited[x][y] + 1){
                        visited[nx][ny] = visited[x][y] + 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}
int main(void){
    input();
    solution();
    cout << visited[n - 1][n - 1];
    return 0;
}
