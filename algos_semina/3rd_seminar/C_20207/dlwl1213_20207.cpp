#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct sc{
  int start;
  int end;
};

sc sche[1005];
cool chk[1005][370];
int maxHeight[370];

queue<pair<int,int>> startPoint;
queue<pair<int,int>> q;

int dy[]={0,-1,0,1};
int dx[]={1,0,-1,0};

bool operator<(const sc&a, const sc&b){
  if(a.start==b.start)
    return a.end>b.end;
  return a.start<b.start;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(false); cout.tie(false);
  
  int n;
  cin>>n;
  
  for(int i=0; i<n; i++)
    cin>>sche[i].start >> sche[i].end;
  
  sort(sche,sche+n);
  
  for(int i=0; i<n; i++){
    sc now=sche[i];
    int height=1;
    
    while(height<=n){
      if(chk[height][now.start])
        height++;
      else
        break;
    }
    
    for(int j=now.start; j<=now.end; j++){
      chk[height][j]=true;
      maxHeight[j]=max(maxHeight[j],height);
    }
  }
  
  int result=0;
  
  int maxH=0;
  int l=0;
  
  for(int i=1; i<=365; i++) {
    if(maxHeight[i]!=0){
      l++;
      maxH=max(maxHeight[i],maxH);
    }
    else{
      result+=maxH*l;
      maxH=0;
      l=0;
    }
  }
  
  result+=maxH*l;
  cout<<result<<'\n';
  
  return 0;
}
