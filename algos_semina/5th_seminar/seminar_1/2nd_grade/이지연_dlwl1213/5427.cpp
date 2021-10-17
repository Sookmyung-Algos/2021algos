#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring> //memset

using namespace std;

const int MAX = 1000;

typedef struct{
        int y, x;
}Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int W, H;
string graph[MAX];
bool visited[MAX][MAX];
pair<int, int> start;
vector<pair<int, int>> fire;

int BFS(void){
        queue<pair<int, int>> q;
        q.push(start);
        queue<pair<int, int>> flame;
        for (int i = 0; i < fire.size(); i++)
                 flame.push(fire[i]);

        int result = 0;
        while (!q.empty()){
                 //불을 먼저 붙여줌
                 int flameSize = flame.size();
                 for (int i = 0; i < flameSize; i++){
                         int y = flame.front().first;
                         int x = flame.front().second;
                         flame.pop();

                         for (int i = 0; i < 4; i++){
                                 int nextY = y + moveDir[i].y;
                                 int nextX = x + moveDir[i].x;
                           
                                 if (0 <= nextY && nextY < H && 0 <= nextX && nextX < W)
                                          if (graph[nextY][nextX] == '.'){
                                                  graph[nextY][nextX] = '*';
                                                  flame.push(make_pair(nextY, nextX));
                                          }
                         }
                 }

                 //다음에 사람이 움직임
                 int curSize = q.size();
                 for (int i = 0; i < curSize; i++){
                         int y = q.front().first;
                         int x = q.front().second;
                         q.pop();

                         //끝자락에 있을 경우 다음에는 무조건 건물 탈출
                         if (y == 0 || y == H - 1 || x == 0 || x == W - 1)
                                 return result + 1;

                         for (int i = 0; i < 4; i++){
                                 int nextY = y + moveDir[i].y;
                                 int nextX = x + moveDir[i].x;

                                 //벽이 아니고 불이 아니라면
                                 if (0 <= nextY && nextY < H && 0 <= nextX && nextX < W)
                                          if (!visited[nextY][nextX] && graph[nextY][nextX] != '*' && graph[nextY][nextX] != '#'){
                                                  visited[nextY][nextX] = true;
                                                  q.push(make_pair(nextY, nextX));
                                          }
                         }
                 }
                 result++;
        }
        return -1;
}

int main(void){
        int test_case;
        cin >> test_case;

        for (int i = 0; i < test_case; i++){
                 fire.clear();
                 memset(visited, false, sizeof(visited));

                 cin >> W >> H;

                 for (int j = 0; j < H; j++){
                         cin >> graph[j];
                   
                         for (int k = 0; k < W; k++)
                                 if (graph[j][k] == '@')
                                          start = make_pair(j, k);
                                 else if (graph[j][k] == '*')
                                          fire.push_back(make_pair(j, k));
                 }
                 int result = BFS();
                 if (result == -1)
                         cout << "IMPOSSIBLE" << "\n";
                 else
                         cout << result << "\n";
        }
        return 0;
}
