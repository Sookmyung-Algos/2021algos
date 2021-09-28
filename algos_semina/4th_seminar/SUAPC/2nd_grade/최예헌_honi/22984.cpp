//기존 전구 개수의 확률변수(X)+불 들어온 추가 전구 개수의 확률변수(Y)
//임의의 확률변수 X,Y에 대해서 "E(X+Y)+E(X)+E(Y)" 만족
//확률변수 X,Y가 서로 독립 아니어도 성립

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

int n;
vector <double> v;


int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    double x;
    double sumx=0;      //기존 전구에 대한 기댓값
    double sumy=0;      //추가 전구에 대한 기댓값
    
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x;
        sumx+=x;
        v.push_back(x);
    }
    
    for (int i=0;i<n-1;i++){
        sumy+=(v[i]*(1-v[i+1]))+(v[i+1]*(1-v[i]));
    }
    cout<<fixed;
    cout.precision(6);
    cout<<sumx+sumy;
}
