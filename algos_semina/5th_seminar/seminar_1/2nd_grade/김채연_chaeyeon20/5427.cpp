#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
 
int h, w, time;
char map[1000][1000];
bool visit[1000][1000];
 
queue<pair<int, int> > sq; 
queue<pair<int, int> > fq; 
 
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
 
bool bfs() {
    time = 0;
 
    while (!sq.empty()) {
        int fqsize = fq.size();
        int sqsize = sq.size();
        int x, y, nx, ny;
 
        time++;
 
       
        while (fqsize--) {
            x = fq.front().first;
            y = fq.front().second;
            fq.pop();
            for (int k = 0; k < 4; k++) {
                nx = x + dx[k];
                ny = y + dy[k];
        
                if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            
                if (map[nx][ny] == '#') continue;
                
                if (visit[nx][ny]) continue;
 
                fq.push({ nx,ny });
                visit[nx][ny] = true;
            }
        }
 

        while (sqsize--) {
            x = sq.front().first;
            y = sq.front().second;
            sq.pop();
            for (int k = 0; k < 4; k++) {
                nx = x + dx[k];
                ny = y + dy[k];
                if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
 
                    return true;
                }
          
                if (map[nx][ny] == '#') continue;
            
                if (visit[nx][ny]) continue;
 
                sq.push({ nx,ny });
                visit[nx][ny] = true;
            }
        }
    }
 
 

    return false;
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    while (T--) {        
     
        memset(visit, false, sizeof(visit));
        while (!fq.empty()) fq.pop();
        while (!sq.empty()) sq.pop();
        bool exitFlag = false;
 
 
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
                if (map[i][j] == '@') {
                    sq.push({ i,j });
                    map[i][j] = '.';
                    visit[i][j] = true;
                }
                else if (map[i][j] == '*') {
                    fq.push({ i,j });
                    visit[i][j] = true;
                }
            }
        }
 
 
        bool result = bfs();
 
        if (result) cout << time << '\n';
        else cout << "IMPOSSIBLE" << "\n";
    }
 
    return 0;
}
