#include <iostream>
#define INF 123456789
using namespace std;

int map[251][251];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, k;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) map[i][j]=0;
            else map[i][j]=INF;
        }
    }
    int u, v, b;
    for(int i=0;i<m;i++){
        cin >> u >> v >> b;
        if(b==0){
            map[u][v]=0;
            map[v][u]=1;
        }
        else{
            map[u][v]=0;
            map[v][u]=0;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(map[i][k]+map[k][j]<map[i][j])
                    map[i][j]=map[i][k]+map[k][j];
            }
        }
    }
    cin >> k;
    int s, e;
    for(int i=0;i<k;i++){
        cin >> s >> e;
        cout << map[s][e] << "\n";
    }
}
