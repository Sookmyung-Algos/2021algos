#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<vector<int>> edge;
vector<vector<int>> visited;
vector<int> v, v2;

vector<int> apart_num;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n, cnt = 0;

void bfs(int x, int y){
    
    visited[x][y] = 1;
    apart_num[cnt]++;
    
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
            
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && edge[nx][ny] != 0) {
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                apart_num[cnt]++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        edge.push_back(v);
        visited.push_back(v2);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char a;
            
            cin >> a;
            
            edge[i].push_back(a-'0');
            visited[i].push_back(0);
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(edge[i][j] == 1 && visited[i][j] != 1){
                apart_num.push_back(0);
                bfs(i, j);
                cnt++;
            }
            
        }
    }
    
    bfs(0, 0);
    
    sort(apart_num.begin(), apart_num.end());
    
    int size = (int)apart_num.size();
    
    cout << size << "\n";
    
    for(int i = 0; i < size; i++){
        cout << apart_num[i] << "\n";
    }
}
