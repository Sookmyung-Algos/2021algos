#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
vector <int> arr[11];           //인접한 지역
int per[11];
vector <int> l;
vector <int> v1;
vector <int> v2;
bool visit[11];
int mmin=10000,result,sum;

int solve(void);
bool bfs(vector <int> v);

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int x,y;
    int cnt=0;
    cin>>n;
    
    for (int i=1;i<=n;i++)              //per배열에 인구수 저장
        cin>>per[i];
    
    for (int i=1;i<=n;i++){
        cin>>x;
        for (int j=0;j<x;j++){
            cin>>y;
            arr[i].push_back(y);
        }
        if (arr[i].size()==0)
            cnt++;
    }
    
    if (n==1){
        cout<<"-1";
        return 0;
    }
    result=solve();
    if (result==10000)
        cout<<"-1";
    else
        cout<<result;
}

int solve(void){                   //모든 경우로 두 선거구 나누기
    vector <int> l;
    l.clear();
    
    for (int k=1;k<=n/2;k++){
        l.clear();
        
        for (int i=0;i<k;i++)
            l.push_back(1);
        
        for (int i=0;i<n-k;i++)
            l.push_back(0);
        
        sort(l.begin(),l.end());
        
        do{
            v1.clear();
            v2.clear();
            for (int i=0;i<l.size();i++){
                if (l[i]==1)
                    v1.push_back(i+1);
                else
                    v2.push_back(i+1);
            }
            
            if (bfs(v1) && bfs(v2)){                //선거구가 각각 서로 연결되어있는 경우
                int sum1=0,sum2=0;
                
                for (int i=0;i<v1.size();i++)
                    sum1+=per[v1[i]];
                for (int i=0;i<v2.size();i++)
                    sum2+=per[v2[i]];
                
                sum=abs(sum1-sum2);
                if (mmin>sum)
                    mmin=sum;
            }
        }while(next_permutation(l.begin(),l.end()));
    }
    return mmin;
}

bool bfs(vector <int> v){               //연결되어있는지 확인
    queue <int> q;
    memset(visit,false,sizeof(visit));
    
    visit[v[0]]=true;
    q.push(v[0]);
    
    while (!q.empty()){
        int temp=q.front();
        q.pop();
        
        for (int i=1;i<v.size();i++){
            bool flag=false;
            if (!visit[v[i]]){
                for (int j=0;j<arr[temp].size();j++){
                    if (arr[temp][j]==v[i]){
                        flag=true;
                        break;
                    }
                }
                
                if (flag){                  //인접하다면 큐에 push
                    visit[v[i]]=true;
                    q.push(v[i]);
                }
            }
        }
    }
    
    for (int i=0;i<v.size();i++){
        if (!visit[v[i]])
            return false;
    }
    return true;
}
