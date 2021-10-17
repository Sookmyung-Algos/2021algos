#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

bool cmp(tuple<int,int,int> a, tuple<int,int,int> b){
    if (get<0>(a)==get<0>(b)){
        if (get<1>(a)==get<1>(b)){
            return get<2>(a) < get<2>(b);
        }
        else
            return get<1>(a) < get<1>(b);
    }
    else
        return get<0>(a) < get<0>(b);
}

int main(){
    vector <tuple<int,int,int>> v;      //곱, 합, 등번호
    int n,b,p,q,r;
    
    cin>>n;
    while (n--){
        cin>>b>>p>>q>>r;
        v.push_back({p*q*r,p+q+r,b});
    }
    sort(v.begin(),v.end(),cmp);
    for (int i=0;i<3;i++){
        cout<<get<2>(v[i])<<' ';
    }
}
