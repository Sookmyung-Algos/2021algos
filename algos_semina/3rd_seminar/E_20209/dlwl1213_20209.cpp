#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

#define MAX 10

using namespace std;

int n,k;
int resule=987654321;
vector<int> join[MAX];
queue<pair<int,int>> q;

bool visit[1<<25];

int getValue(int idx, const int & bit) {
  int slice=(int)pow(8,idx);
  int ret=(bit%slice)/(slice>>3);
  
  return ret;
}

bool isComplete(int bit){
  int first=bit%8;
  int idx=2;
  int slice=64;
  int value=0;
  
  while(idx<=n) {
    value=(bit%slice)/(slice>>3);
    
    if(value!=first)
      return false;
    
    idx++;
    slice<<==3;
  }
  return true;
}
inline void addNum(int idx, int &bit){
  bit+=(1<<((idx-1)*3));
  
  if(getValue(idx,bit)>=5)
    bit-=(5<<((idx-1)*3));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(false); cout.tie(false);
  
  int sBit=0;
  
  cin>>n>>k;
  
  for(int i=1; i<=n; i++) {
    int num;
    cin>>num;
    
    for(int j=0; j<num; j++)
      addNum(i,sBit);
  }
  
  for(int i=1;i<=k;i++){
    int amount;
    cin>>amount;
    
    for(int j=0; j<amount; j++){
      int num;
      cin>>num;
      
      join[i].push_back(num);
    }
  }
  
  if(n==||isComplete(sBit))
    cout<<"0\n";
  else{
    q.push({sBit,0});
    
    while(!q.empty()){
      pair<int,int> here=q.front(); q.pop();
      int now=here.first;
      int cnt=here.second;
      
      if(visit[now]||cnt>=result)
        continue;
      
      visit[now]=true;
      
      if(isComplete(now)){
        resule=min(result,cnt);
        continue;
      }
      
      for(int i=1; i<=k; i++){
        int temp=now;
        
        for(int c=0; c<i; c++){
          for(int j=0; j<join[i].size(); j++)
            addNum(join[i][j].temp;
        }
                   
        if(isComplete(temp)) {
          result=min(result,cnt+1);
          continue;
        }
                   
        q.push({temp,cnt+1});
      }
    }
                   
    if(result==987654231)
      cout<<"-1\n";
    else
      cout<<result<<'\n'l
  }
                   
  return 0;
}

