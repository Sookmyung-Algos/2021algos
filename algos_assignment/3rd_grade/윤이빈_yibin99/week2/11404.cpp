#include <iostream>
using namespace std;

int INF = 10000000;
int bus[101][101] = {INF, };

int main(){
    int n, m;
    int a, b, c;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(i!=j) bus[i][j]=INF;
    }
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        if(bus[a][b]>c)
            bus[a][b] = c;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(bus[i][k]+bus[k][j] < bus[i][j])
                    bus[i][j] = bus[i][k]+bus[k][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(bus[i][j]==INF)
                cout << 0 << " ";
            else cout << bus[i][j] << " ";
        }
        cout << "\n";
    }
}
