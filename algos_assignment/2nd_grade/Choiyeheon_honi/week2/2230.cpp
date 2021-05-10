#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N,M;
    int num[100001];
    int s=0,e=1,x;
    int min=2000000001;
    
    cin>>N>>M;
    for (int i=0;i<N;i++)
        cin>>num[i];        //수열 입력
    
    sort(num,num+N);        //수열 오름차순으로 정렬
    
    while (s!=N)
    {
        x=num[e]-num[s];    //x는 두 수열의 차
        if (x<M)            //차가 M 미만인 경우
            e++;            //e 포인터 증가

        else if (x>=M || e==N)  //차가 M 이상 또는 e 포인터가 N인 경우
        {
            if (x<min)      //만약 차가 현재 최소차보다 작다면
                min=x;      //최소차는 x
            s++;            //s 포인터 증가
        }
    }
    cout<<min;
}
