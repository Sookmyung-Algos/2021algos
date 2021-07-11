#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 100;

typedef struct{
    int y, x;
}Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int graph[MAX][MAX];
bool visited[MAX][MAX];
int M, N, K;
int cnt; 

void DFS(int y, int x){
        visited[y][x] = true;
        cnt++;
    
        for (int i = 0; i < 4; i++){
                 int nextY = y + moveDir[i].y;
                 int nextX = x + moveDir[i].x;

                 if (0 <= nextY && nextY < M && 0 <= nextX && nextX < N){
                     if (graph[nextY][nextX] == 0 && !visited[nextY][nextX]){
                         DFS(nextY, nextX);
                     }
                 }
        }

}

 

int main(void){       
        cin >> M >> N >> K;
    
        for (int i = 0; i < K; i++){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            for (int y = y1; y < y2; y++){
                for (int x = x1; x < x2; x++){
                    graph[y][x] = 1;
                }
            }
        }

        vector<int> result;
    
        for(int y=0; y<M; y++){
            for(int x=0; x<N; x++){
                if (graph[y][x] == 0 && !visited[y][x]){
                    cnt = 0;
                    DFS(y, x);
                    result.push_back(cnt);
                }
            }
        }

        cout << result.size() << endl;
        sort(result.begin(), result.end());
    
        for (int i = 0; i < result.size(); i++)
                 cout << result[i] << " ";

        cout << endl;
        return 0;
}
