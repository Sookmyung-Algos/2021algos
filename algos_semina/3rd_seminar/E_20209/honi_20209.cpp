#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int n,k;
vector<int> arr;
vector <int> v[8];

bool check(vector<int> temp){
    int num=temp[0];
    for(int i=0;i<temp.size();i++){
        if(num!=temp[i])
            return false;
    }
    return true;
}

int bfs(void){
    map<vector<int>,int> m;     //key: 큐브값이 저장되어있는 벡터, value: cnt
    queue<vector<int>> q;

    m[arr]=0;
    q.push(arr);

    while(!q.empty()){
        vector<int> temp = q.front();
        q.pop();

        int cnt = m[temp];
        if(check(temp)) return cnt;     //벡터의 큐브 값들이 모두 같은 경우 return

        for(int i=0;i<k;i++){
            vector<int> next = temp;        //next 벡터에 temp 벡터 복사
            
            for (int j=0;j<v[i].size();j++){
                next[v[i][j]-1]+=(i+1);     //next 벡터의 큐브값 저장(스위치)
                next[v[i][j]-1]%=5;
            }
            
            if(m.find(next)==m.end()){      //키 값(next)이 존재하지 않을 시
                m[next]=cnt+1;          //map에 키 값(next 벡터)과 value값 저장
                q.push(next);           //큐에 next 벡터 push
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>k;

    int x,y;
    for (int i=0;i<n;i++){      //큐브의 숫자
        cin>>x;
        arr.push_back(x);
    }

    for(int i=0;i<k;i++){       //스위치와 연결된 큐브
        cin>>x;
        for (int j=0;j<x;j++){
            cin>>y;
            v[i].push_back(y);
        }
    }

    int result=bfs();
    cout<<result;
}
