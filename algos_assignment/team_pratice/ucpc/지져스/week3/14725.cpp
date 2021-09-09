#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    vector <string> v[1000];
    vector <string> s;

    int n,k,cnt;
    string x;
    
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>k;
        for (int j=0;j<k;j++){
            cin>>x;
            v[i].push_back(x);
        }
    }
    sort(v,v+n);
    
    for (int i=0;i<n;i++){
        cnt=0;              //겹치는 먹이 수
        for (int j=0;j<v[i].size() && j<s.size();j++){
            if (v[i][j]!=s[j])
                break;
            cnt++;
        }
        
        int temp=s.size();
        for (int j=cnt;j<temp;j++)          //겹치는 먹이 제외하고 벡터에서 삭제
            s.pop_back();
        
        for (int j=cnt;j<v[i].size();j++){      //겹치지 않는 먹이 출력 후 벡터에 삽입
            for (int k=0;k<s.size();k++)
                cout<<"—";
            cout<<v[i][j]<<'\n';
            s.push_back(v[i][j]);
        }
    }
}
