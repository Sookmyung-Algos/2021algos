#include<iostream>
#include<cstring>
using namespace std;

int N, M;
int nCheeze = 0;
int map[101][101] = { 0 };
int visit[101][101] = { 0 };
int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };

void outAir(int x, int y) {
    if (visit[x][y] == 0)visit[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (map[nx][ny] == 0 && visit[nx][ny] == 0) outAir(nx, ny);
    }
    return;
}
void melt() {
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (visit[nx][ny] == 1) {
                    if (map[i][j] == 1) {
                        map[i][j] = 0;
                        nCheeze--;
                        break;
                    }
                }
            }

        }
    }
}


int main() {
    int time = 0;
    int final_cheeze = 0;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) nCheeze++;
        }
    }
    while (1) {

        final_cheeze = nCheeze;
        memset(visit, 0, sizeof(visit));
        
        outAir(0, 0);
        melt();
        time++;
        if (nCheeze == 0)break;
      
    }

    cout << time << "\n";
    cout << final_cheeze;

}
