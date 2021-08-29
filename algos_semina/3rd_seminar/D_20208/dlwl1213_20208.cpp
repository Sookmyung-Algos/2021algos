#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int n,m,h;
vector<pair<int,int>> vMilk;
pair<int,int> house;
int result=0;

int addMilk(const int & bit, int idx){
  return bit | (1<<idx);
}

int countMilk(const int&bit) {
  int ret=0;
  
  for(int i=0; i<vMilk.size(); i++)
    if(bit & (1<<i)
       ret++;
       
  return ret; 
}

void printMilk(int bit) {
  vector<bool> b;
  while(bit>0) {
    b.push_back(bit%2);
    bit/=2;
  }
  
  for(int i=b.size()-1; i>=0; i--)
    cout<<b[i];
  
  cout<<'\n';
}
   
int dist(const pair<int,int> &a, const pair<int,int> &b) {
  return abs(a.first-b.first) + abs(a.second - b.second);
}
       
void dfs(int curBit, int hp, pair<int,int> lPoint) {
  if(curBit == (1<<vMilk.size())-1) {
    if(dist(lPoint,house)<=hp)
      result=max(result,(int)vMilk.size());
    return;
  }
  
  for(int i=0; i<vMilkd.size(); i++){
    int d=dist(lPoint,vMilk[i]);
    
    if(d<=hp && !(curBit & (1<<i)))
      dfs(addMilk(curBit,i), hp-d+h, vMilk[i]);
  }
  
  if(dist(lPoint, house)<=hp){
    result=max(result, countMilk(curBit));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(false); cout.tie(false);
  
  cin>>n>>m>>h;
  
  for(inti=0; i<n; i++){
    for(int j=0; j<n; j++) {
      int num;
      cin>>num;
      
      if(num>0){
        if(num==1)
          house=make_pair(i,j);
        else
          vMilk.push_back({i,j});
      }
    }
  }
  
  dfs(0,m,house);
  
  cout<<result<<'\n';
  
  return 0;
}
  
       
       
