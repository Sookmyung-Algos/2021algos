#include <iostream>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n,k;
    int v[11][11];
    cin>>n>>k;
    
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            cin>>v[i][j];
    }
    
    for (int i=0;i<n;i++){
        for (int x=0;x<k;x++){
            for (int j=0;j<n;j++){
                for (int y=0;y<k;y++)
                    cout<<v[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
}
