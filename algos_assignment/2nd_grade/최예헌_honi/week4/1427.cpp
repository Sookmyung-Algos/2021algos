#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N;
    vector <int> v;
    cin>>N;
    
    while (N>0)             //각각의 수를 벡터에 삽입
    {
        v.push_back(N%10);
        N=N/10;
    }
    sort(v.begin(),v.end());
    
    for (int i=v.size()-1;i>=0;i--)     //내림차순으로 출력
        cout<<v[i];
}
