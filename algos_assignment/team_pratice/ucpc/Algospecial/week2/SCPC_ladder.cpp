#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>

#define INF 1e9

using namespace std;

int n, k, m;
int Answer;

int dist[6000][6000];

vector<int>change_node;

vector<vector<pair<int, int>>> graph;
vector<pair<int, int>> v;

void bfs(){
    
    priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    //첫 i는 도착, 두번 째 i는 시작
    for(int i = 1; i <= n; i++){
        pq.push({0, {i, i}});
    }
    
    while(!pq.empty()){
        
        int start_node = pq.top().second.first;
        int node = pq.top().second.second;
        int weight = pq.top().first;
        
        pq.pop();
        
        //cout << "start_node: "<< start_node << " node: " << node << " weight: " << weight << "\n";
        
        if(dist[start_node][node] > weight){
            
            dist[start_node][node] = weight;
            //cout << "dist22: " << dist[start_node][node] << "\n";
        }
        
        for(int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i].first;
            
            pq.push({graph[node][i].second + weight, {start_node, next}});
        }
    }
    
}

int main(int argc, char** argv)
{
    int T, test_case;

    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {

        Answer = 0;
        
        //초기화
        for(int i =0; i<6000; i++){
            for(int j = 0; j < 6000; j++){
                dist[i][j] = INF;
            }
        }
        
        graph.clear();
        change_node.clear();
        
        cin >> n >> k >> m;
        
        for(int i =0; i<=n + 2 * k; i++){
            graph.push_back(v);
        }
        
        for(int i = 0; i<= n; i++){
            change_node.push_back(i);
        }
        
        for(int i =0; i < k; i++){
            int a, b;
            
            cin >> a >> b;
            
            graph[change_node[a]].push_back({n + 2*i + 1, 1});
            graph[change_node[a]].push_back({n + 2*i + 2, 0});
            graph[change_node[b]].push_back({n + 2*i + 1, 0});
            graph[change_node[b]].push_back({n + 2*i + 2, 1});
            
            
            change_node[a] = n+2*i + 1;
            change_node[b] = n+2*i + 2;
            
        }
        
        bfs();
        
        for(int i =0; i< m; i++){
            int start, end;
            
            cin >> start >> end;
            
            //cout << "end: " << change_node[end] << "\n";
            
            //cout << "dist: " << dist[start][change_node[end]] << "\n";
            
            if(dist[start][change_node[end]] == INF){
                dist[start][change_node[end]] = -1;
            }
            
            Answer += dist[start][change_node[end]];
        }
    
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }

    return 0;
}
