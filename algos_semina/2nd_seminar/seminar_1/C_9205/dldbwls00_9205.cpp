#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
 
const int MAX = 100 + 2; //출발, 도착 포함
int n;
vector<int> graph[MAX];
bool visited[MAX];
int distance(pair<int, int> p1, pair<int, int> p2); //맨해튼거리
void dfs(int node);
 
int main(void){
    int test;
    cin >> test;
    
    for (int i = 0; i < test; i++){
        for (int j = 0; j < MAX; j++)   graph[j].clear();
 
        memset(visited, false, sizeof(visited)); //메모리 초기화
        cin >> n;
        vector<pair<int, int>> v;
        for (int j = 0; j < n + 2; j++){
            int y, x;
            cin >> y >> x;
            v.push_back(make_pair(y, x));
        }
      
        for (int j = 0; j < n + 2; j++) {//맥주 20병으로 갈 수 있는 거리 내에 있는 경우
            for (int k = j + 1; k < n + 2; k++) {
                if (distance(v[j], v[k]) <= 50 * 20) {//양방향 그래프
                    graph[j].push_back(k);
                    graph[k].push_back(j);
                }
            }
        }
        dfs(0);
        if (visited[n + 1]) cout << "happy\n"; //0이 출발점, n+1이 도착점
        else cout << "sad\n";
    }
    return 0;
}
int distance(pair<int, int> p1, pair<int, int> p2){ //맨해튼 거리
     return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
void dfs(int node){
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (visited[next] == false) dfs(next);
    }
}
