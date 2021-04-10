#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> location;//queue<pair<int,int>> 

int tomato[1001][1001];

queue<location> q;//queue->q

int dy[4] = {1, 0, -1, 0};

int dx[4] = {0, 1, 0, -1};

int m,n;

int value, cnt;

void bfs(int y, int x){

    for(int i=0; i<4; i++){

        int ny=y+dy[i];

        int nx=x+dx[i];

        if(ny>=n || ny<0 || nx>=m || nx<0) continue;

        if(tomato[ny][nx]==0){

            tomato[ny][nx]=1; //방문표시(익은 토마토) 

            cnt++;

            q.push({ny,nx});

        }

    }

    return;

}

int main(){

    cin>>m>>n;

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin>>tomato[i][j];

            if(tomato[i][j]==1) q.push({i, j});

        }

    }

    value=q.size();

    cnt=0;

    int result=0;

    while(!q.empty()){

        location start=q.front();

        bfs(start.first, start.second);

        value--;

        if(value==0){

            value=cnt;

            cnt=0;

            result++;

        }

        q.pop();

    }

    result-=1;

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            if(tomato[i][j] == 0) result=-1;

        }

    }

    cout <<result<< '\n';

    return 0;

}
