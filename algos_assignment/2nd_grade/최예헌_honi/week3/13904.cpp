#include <iostream>
#include <algorithm>

using namespace std;

struct project{
    int d;
    int w;
}p[1000];

bool compare(struct project a,struct project b){
    if (a.w==b.w)                 //점수가 같은 경우는 마감일이 빠른 과제 먼저
        return a.d<b.d;
    return a.w>b.w;               //점수가 큰 과제 먼저
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N,d,w,day,sum=0;
    int s[1000]={0,};           
    
    cin>>N;
    for (int i=0;i<N;i++)
    {
        cin>>d>>w;              //제출마감일과 점수 입력
        p[i].d=d;
        p[i].w=w;
    }
    sort(p,p+N,compare);        //내림차순 정렬
    
    for (int i=0;i<N;i++)
    {
        day=p[i].d;
        if (s[day]==0)         //마감일에 해야하는 과제가 없는 경우
            s[day]=p[i].w;     //배열의 인덱스 값은 점수값
      
        else
        {
            while (1)
            {
                day--;              //하루 앞으로 이동
                if (s[day]==0)      //그 날에 해야하는 과제가 없는 경우
                {
                    s[day]=p[i].w;      //배열의 인덱스 값은 점수값
                    break;
                }
            }
        }
    }
    
    for (int i=1;i<1000;i++)        //할 수 있는 과제 점수 합하기
    {
        sum+=s[i];
    }
    cout<<sum;
}
