#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N,C,x;
    int v[200000];
    int l,r,mid;
    int count,max=0;

    cin>>N>>C;                  //집의 개수와 공유기의 개수 입력
    for (int i=0;i<N;i++)
    {
        cin>>x;                 //집의 좌표
        v[i]=x;
    }
    sort(v,v+N);                //집의 좌표 오름차순으로 정렬
    
    l=0; r=v[N-1]-v[0];         //최대 거리 = 집의 좌표가 가장 큰 값-가장 작은 값
    
    while (l<=r)
    {
        mid=(l+r)/2;            //가장 인접한 두 공유기의 거리
        count=1;                //맨 처음 공유기가 설치될 때는 한번에 두 공유기가 설치되므로 먼저 1 추가해줌
        for (int i=0;i<N;i++)
        {
            for (int j=i+1;j<N;j++)
            {
                if (v[j]-v[i]>=mid)       //두 좌표사이의 거리가 mid보다 크거나 같은 경우
                {
                    count++;              //count 증가
                    i=j-1;                //v[j]는 공유기가 마지막으로 설치된 집의 좌표 , for문을 통해 i가 1 증가할 것이기 때문에 if문에서 1 감소시킴
                    break;
                }
            }
        }
        
        if (count<C)                  //count가 공유기의 개수보다 작은 경우
            r=mid-1;                  //mid값이 작아져야 함
            
        else
        {
            l=mid+1;                  //mid값이 커져야함
            if (max<mid)
                max=mid;
        }
    }
    cout<<max;
}
