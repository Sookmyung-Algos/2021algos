#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int miro[1001][1001];

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d", &miro[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            miro[i][j]+=max({miro[i-1][j],miro[i][j-1],miro[i-1][j-1]});
        }
    }
    printf("%d", miro[n][m]);
}
