#include <iostream>
using namespace std;

int graph[101][101];
int d[101][101] = {0, };

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> graph[i][j];
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(graph[i][j]==1)
                    d[i][j]=1;
                else if(d[i][k]==1 && d[k][j]==1)
                    d[i][j]=1;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout << d[i][j] << " ";
        cout << "\n";
    }
}
