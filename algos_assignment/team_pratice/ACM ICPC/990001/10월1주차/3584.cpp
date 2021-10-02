#include <iostream>
#include <vector>
#define MAX 10001
using namespace std;

int t,n,a,b;
int node1, node2;
vector<int> parent;  // parent[i]는 i의 부모노드 번호
bool visited[MAX];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        parent.resize(n+1);
        for(int k=0;k<=n;k++)
            parent[k] = k;
        fill(&visited[0], &visited[MAX-1], false);
        for(int j=0;j<n-1;j++){
            cin >> a >> b;  // a가 b의 부모
            parent[b]=a;
        }
        
        cin >> node1 >> node2;
        visited[node1] = true;
        while(true){  // node1의 조상들에 대해 먼저 방문
            if(node1 == parent[node1])
                break;
            visited[parent[node1]] = true;
            node1=parent[node1];
        }
        while(true){  // node2의 조상들에 대해 확인
            if(visited[parent[node2]]){
                cout << parent[node2] << "\n";
                break;
            }
            node2 = parent[node2];
        }
    }
    return 0;
}
