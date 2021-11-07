#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};
int n;
double answer;
double probability[4];
char dir[4] = {'E', 'W', 'S', 'N'};
int visited[29][29];
vector<char> route;

void dfs(int len, int y, int x, double result) {
    if (len > n) return;
    if (len == n) {
        string str;
        for(int i = 0; i < route.size(); i++)
            str += route[i];

        answer += result;
    }
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i]; 
        
        if (visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        route.push_back(dir[i]);
        dfs(len+1, ny, nx, result * probability[i]);
        route.pop_back();
        visited[ny][nx] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < 4; i++) {
        int tmp;
        cin >> tmp;
        probability[i] = tmp * 0.01;
    }
    
    visited[14][14] = 1;
    dfs(0, 14, 14, 1);
    cout.precision(9); // 소수점 자리 설정
    cout << fixed << answer;
    return 0;
}
