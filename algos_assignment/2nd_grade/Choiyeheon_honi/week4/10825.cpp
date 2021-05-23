#include <iostream>
#include <algorithm>

using namespace std;

struct person{
    string name;
    int ko;
    int en;
    int ma;
}p[100000];

bool compare(struct person a,struct person b){
    if (a.ko==b.ko)                 //국어점수가 같은 경우
    {
        if (a.en==b.en)             //영어점수가 같은 경우
        {
            if (a.ma==b.ma)         //수학점수가 같은 경우
                return a.name<b.name;       //이름 사전순
            return a.ma>b.ma;       //수학점수 감소하는 순
        }
        else
            return a.en<b.en;       //영어점수 증가하는 순
    }
    else
        return a.ko>b.ko;           //국어점수 감소하는 순
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin>>N;
    for (int i=0;i<N;i++)
        cin>>p[i].name>>p[i].ko>>p[i].en>>p[i].ma;
    sort(p,p+N,compare);
    
    for (int i=0;i<N;i++)
        cout<<p[i].name<<'\n';
}
