#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N,M,x,sum=0;
    int l,r,mid,total,max=0;
    vector <int> v;
    
    scanf("%d",&N);         //지방의 수 입력
    for (int i=0;i<N;i++)
    {
        scanf("%d",&x);
        sum+=x;             //예산요청의 총 합
        v.push_back(x);
    }
    scanf("%d",&M);         //총 예산 입력
    sort(v.begin(),v.end());        //오름차순으로 정렬
    
    if (sum<=M)         //예산요청의 합이 총 예산보다 작다면
    {
        printf("%d",v.back());      //배정된 예산 중 최댓값은 예산요청의 최대값
        return 0;
        
    }
    
    l=0; r=sum;             //0~예산요청합 중 상한액의 최댓값(max) 찾기
    while (l<=r)
    {
        total=0;
        mid=(l+r)/2;
        
        for (int i=0;i<N;i++)
        {
            if(v[i]<mid)        //예산요청의 값이 상한액보다 작은 경우
                total+=v[i];
            else
                total+=mid;
        }
        
        if (total<=M){          //mid가 상한액인 경우의 예산요청 합이 총 예산보다 작은 경우
            l=mid+1;
            if (mid>max)        //상한액이 max보다 큰 경우
                max=mid;
        }
        
        else
            r=mid-1;
    }
    printf("%d",max);
}
