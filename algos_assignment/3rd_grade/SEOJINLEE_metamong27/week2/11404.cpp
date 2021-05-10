

#include <bits/stdc++.h>

using namespace std;

int n, m;

int Map[101][101];

void floydWarshall(){

    for(int k=1; k<=n; k++){

        for(int i=1; i<=n; i++){

            for(int j=1; j<=n; j++){

                if (i==j || j==k || i==j)continue;

    //map[i][i]는 존재하지 않아서 비교x 

                if(Map[i][j]>Map[i][k]+Map[k][j]) {

                    Map[i][j]=Map[i][k]+Map[k][j];

                    //거쳐가는 값이 더 작으면 갱신  

                }

            }

        }

    }

}

int main(void)

{

    cin>>n>>m; 

    memset(Map,0x2f,sizeof(Map));//Map 메모리 할당 

    for(int i=0; i<m; i++)  {

        int s,e,c;

        cin>>s>>e>>c;

        if(s==e) continue;

        if(Map[s][e]>c){//start,end,cost

            Map[s][e]=c;

        }

    }

    for(int i=1; i<=n; i++){

        Map[i][i] = 0;

    }

    floydWarshall();

    for(int i=1; i<=n; i++) {

        for(int j=1; j<=n; j++) {

            if(Map[i][j]<1000001) cout<<Map[i][j]<<" ";

            else cout<<0<<" ";

        }

        cout << "\n";

    }

}

​
