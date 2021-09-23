#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

bool cmp(ll a,ll b){
    return a>b;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n;
    double a,b,c;
    ll num[500001];         //같은 기울기 개수
    
    cin>>n;
    vector <double> arr1(n);
    vector <double> arr2(n);
    
    for (int i=0;i<n;i++){
        cin>>a>>b>>c;
        if (b==0)               //y축에 평행인 경우
            arr1[i]=arr2[i]=1000000003;
        else
            arr1[i]=arr2[i]=a/b;
    }
    sort(arr1.begin(),arr1.end());
    arr1.erase(unique(arr1.begin(),arr1.end()),arr1.end());     //중복 제거 후 정렬
    
    map <double,ll> map;
    for (int i=0;i<arr1.size();i++)         //좌표압축
        map[arr1[i]]=i;
    
    for (int i=0;i<arr2.size();i++){        //같은 기울기 개수 구하기
        num[map[arr2[i]]]++;
    }
    sort(num,num+arr1.size(),cmp);          //내림차순 정렬
    ll result=(arr2.size()*(arr2.size()-1))/2;      //전체에서 2개씩 쌍 이루는 경우의 수
    
    int temp=0;
    while (num[temp]!=0){
        result-=((num[temp]*(num[temp]-1))/2);      //전체에서 같은 기울기가 쌍으로 뽑이는 경우 제외
        temp++;
    }
    cout<<result;
}
