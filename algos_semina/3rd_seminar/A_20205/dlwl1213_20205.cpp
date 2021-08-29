#include <iostream>

using namespace std;

bool pixel[105][105];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(false);
  cout.tie(false);
  
  int n,k;
  
  cin>>n>>k;
  
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      bool chk;
      cin>>chk;
      
      for(int a=i*k; a<i*k+k; a++)
        for(int b=j*k; b<j*k+k; b++)
          pixel[a][b]=chk;
    }
  }
  
  for(int i=0; i<n*k; i++){
    for(int j=0; j<n*k; j++) {
      cout<<pixel[i][j]<<' ';
    }
    
    cout<<'\n';
  }
  return 0;
}
