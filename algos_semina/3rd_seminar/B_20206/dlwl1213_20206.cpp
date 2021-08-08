#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>

using namespace std;

string ans[]={"Poor", "Lucky"};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(false); cout.tie(false);
  
  int A,B,C;
  cin>>A>>B>>C;
  
  int x1,x2,y1,y2;
  
  vector<pair<int,int>> dots;
  
  cin>>x1>>x2>>y1>>y2;
  
  dots.push_back({x1,y1});
  dots.push_back({x1,y2});
  dots.push_back({x2,y1});
  dots.push_back({x2,y2});
  
  int chk[2]={0,};
  
  for(int i=0; i<dots.size(); i++){
    if(dots[i].first*a+dots[i].second*b<=-c)
      chk[0]++;
    if(dots[i].first*a+dots[i].second*b>=-c)
      chk[1]++;
  }
  
  if(chk[0]==4||chk[10]==4)
    cout<<ans[1];
  
  else
    cout<<ans[0];
  
  return 0;
}
  
