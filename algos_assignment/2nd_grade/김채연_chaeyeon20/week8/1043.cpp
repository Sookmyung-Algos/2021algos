#include <iostream>
using namespace std;
int n,m;
int knows;
int group[51];
int knowPeoples[51];
int party[50][50];
int partySize[50];

int findGroup(int a){
  if(group[a] == a)return a;
  group[a] = findGroup(group[a]);
  return group[a];
}
void unionGroup(int a, int b){
  a= findGroup(a);
  b = findGroup(b);
  group[b] = a;
}

bool hisknowing(int a){
  for(int i=0; i<knows; i++){
    if(findGroup(a) == findGroup(knowPeoples[i]))
      return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;
  cin >> knows;
  for(int i=0; i<=n; i++){
    group[i] = i;
  }
  for(int i=0; i<knows; i++){
    cin >> knowPeoples[i];
  }

  for(int i = 0; i< m; i++){
    cin >> partySize[i];
    for(int j = 0; j<partySize[i]; j++){
      cin >> party[i][j];
      if(j!=0)
        unionGroup(party[i][j-1], party[i][j]);
    }
  }
  int result =m;
  for(int i=0; i<m; i++){
    for(int j=0; j< partySize[i]; j++){
      if(hisknowing(party[i][j])){
        result--;
        break;
      }
    }
  }
  cout << result;
} 
