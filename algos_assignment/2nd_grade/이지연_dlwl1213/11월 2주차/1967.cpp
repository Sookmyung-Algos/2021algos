#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
 
int n;
int visited[10002]={0};
vector<pair<int,int>> node[10002];
 
int ans=0; //지름 길이
int end_point=0; //지름에 해당하는 끝점
void dfs(int point,int length){
    
    if(visited[point])
        return;
    
    visited[point]=1;
    if(ans<length){
        ans=length;
        end_point=point;
    }
    
    for(int i=0;i<node[point].size();i++){
        dfs(node[point][i].first,length+node[point][i].second);
    }
}
 
int main(){
    
    cin>>n;
    
    int parent,child,length;
    for(int i=0;i<n-1;i++){
        scanf("%d %d %d",&parent,&child,&length);
        node[parent].push_back(make_pair(child,length));
        node[child].push_back(make_pair(parent,length));
    }
    
    //가장 멀리 있는 정점(end_point) 구하기
    dfs(1,0);
 
    ans=0;
    memset(visited,0,sizeof(visited));
    
    //end_point와 가장 멀리 있는 정점과의 거리 구하기
    dfs(end_point,0);
    cout<<ans<<endl;
    
 
    return 0;
}
