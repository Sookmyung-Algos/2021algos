#include <iostream>
#include <queue>
using namespace std;

int N,X;
queue<int> q;
bool visited[100002];
int t[100002];

void bfs(int node){
    q.push(node);
    
    while(!q.empty()){
        int num = q.front();
        q.pop();
        
        if (num == X) return;
        
        if (!visited[num+1] && num+1>=0 && num+1<100001){
            visited[num+1] = true;
            q.push(num+1);
            t[num+1] = t[num]+1;
        }
        if (!visited[num-1] && num-1>=0 && num-1<100001){
            visited[num-1] = true;
            q.push(num-1);
            t[num-1] = t[num]+1;
        }
        if (!visited[2*num] && 2*num>=0 && 2*num<100001){
            visited[2*num] = true;
            q.push(2*num);
            t[2*num] = t[num]+1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> X;
    bfs(N);
    cout << t[X];
}
