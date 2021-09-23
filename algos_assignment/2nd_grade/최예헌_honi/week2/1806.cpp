#include <iostream>

using namespace std;

int main(){
    
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N,S;
    int num[100001];
    int s=0,e=0,sum=0,count=0,min;
    
    cin>>N>>S;
    min=N;                      //min값을 최대의 경우로 설정
    for (int i=0;i<N;i++)
        cin>>num[i];            //N개의 수열 입력
    
    while (s<=e)
    {
        if(sum>=S)              //합이 S 이상인 경우
        {
            if (min>e-s)        //min값이 e-s(=현재 길이)보다 크면
                min=e-s;        //min값을 e-s로 변경
            sum-=num[s++];
            count++;
        }
        else if (e==N)
            sum-=num[s++];
        else
            sum+=num[e++];
    }
    
    if (count==0){      //합을 만드는 것이 불가능한 경우
        cout<<0;        //0 출력
        return 0;
    }
    cout<<min;
}
