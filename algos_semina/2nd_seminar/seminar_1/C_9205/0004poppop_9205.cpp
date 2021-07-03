#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset함수 헤더파일
using namespace std;

const int MAX = 102;
int N;
vector<int> graph[MAX];
bool visited[MAX];

int distance(pair<int, int> p1, pair<int, int> p2)
{
        return abs(p1.first - p2.first) + abs(p1.second - p2.second);
} // 맨해튼 거리 측정 함수

void DFS(int node)
{
        visited[node] = true;
        for (int i = 0; i < graph[node].size(); i++)
        {
                 int next = graph[node][i];
                 if (visited[next] == false)
                         DFS(next);
        }
}

int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int test_case;
        cin >> test_case;
    
        for (int i = 0; i < test_case; i++)
        {
                 for (int j = 0; j < MAX; j++)
                         graph[j].clear();
                 memset(visited, false, sizeof(visited)); // visited 메모리 블록의 크기만큼을 false로 채움

                 cin >> N;
                 vector<pair<int, int>> coord;

                 //출발점(0), 도착점(N + 1) 포함
                 for (int j = 0; j < N + 2; j++)
                 {
                         int y, x;
                         cin >> y >> x;
                         coord.push_back(make_pair(y, x));
                 }
                
                 for(int j=0; j<N+2; j++){
                         for(int k=j+1; k<N+2; k++){
                                 if (distance(coord[j], coord[k]) <= 50 * 20)
                                 {
                                          graph[j].push_back(k);
                                          graph[k].push_back(j);
                                 }  // 양방향 그래프
                         }
                 }   // 맥주 20병으로 갈 수 있는 거리 내에 있으면 그래프에 추가
                           
                 DFS(0);  // 출발점인 0부터 DFS 탐색
                

                 if (visited[N + 1])
                         cout << "happy\n";
                 else
                         cout << "sad\n";
        }
        return 0;
}
