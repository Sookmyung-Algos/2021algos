#include <iostream>

using namespace std;

int main(){
    
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N,M;
    int num[10001];
    int s=0,e=0,count=0,sum=0;
    
    cin>>N>>M;
    for (int i=0;i<N;i++)
        cin>>num[i];        //N개의 수열 입력
    
    while (s<=e)
    {
        if(sum>=M || e==N)  //현재까지의 합이 M보다 큰 경우 or e와 N이 같을 경우(e가 끝까지 간 경우)
            sum-=num[s++];  //s를 한칸 뒤로 이동 후 합에서 배열의 s 인덱스 값(=새로 제외된 원소) 빼기
        else
            sum+=num[e++];  //e를 한칸 뒤로 이동 후 합에서 배열의 e 인덱스 값(=새로 포함된 원소) 더하기
        if (sum==M)         //합이 M과 같은 경우
            count++;        //카운트값 증가
    }
    cout<<count;
}
