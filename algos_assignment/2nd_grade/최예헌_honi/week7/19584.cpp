#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,m;
    ll x,y;
    ll u,v,c;
    
    cin>>n>>m;
    
    vector <ll> arr1(n);
    vector <ll> arr2(n);
    vector <ll> sum(n+1);
    
    for (int i=0;i<n;i++){
        cin>>x>>y;
        arr1[i]=arr2[i]=y;              //y좌표값 저장 {3,4,4,0,2}
    }
    sort(arr1.begin(),arr1.end());
    arr1.erase(unique(arr1.begin(),arr1.end()),arr1.end());     //y좌표 중복제거 후 정렬  {0,2,3,4}
    
    map <ll,ll> map;
    for (int i=0;i<arr1.size();i++){
        map[arr1[i]]=i;             //좌표압축 -> map[0]=0,map[2]=1,map[3]=2,map[4]=3
    }
    
    for (int i=0;i<n;i++){
        arr2[i]=map[arr2[i]];           //arr2의 배열값이 저장된 arr1의 인덱스값 저장
    }
    
    for (int i=0;i<m;i++){                //누적합
        cin>>u>>v>>c;
        sum[min(arr2[u-1],arr2[v-1])]+=c;           
        sum[max(arr2[u-1],arr2[v-1])+1]-=c;
    }
    
    ll result=sum[0];
    for (int i=1;i<n;i++){
        sum[i]+=sum[i-1];
        result=max(result,sum[i]);
    }
    cout<<result;
}
