#include <iostream>
#include <algorithm>

using namespace std;
int x[100000],y[100000];

int search(int s,int e,int key);

int main(){
    int N,M,result;
    scanf("%d",&N);
    for (int i=0;i<N;i++)       //N개의 정수 입력
        scanf("%d",&x[i]);
    
    scanf("%d",&M);
    for (int i=0;i<M;i++)       //M개의 정수 입력
        scanf("%d",&y[i]);
    
    sort(x,x+N);                //N의 배열 오름차순 정렬
    for (int i=0;i<M;i++)       //M 배열의 값이 N에 존재하는지 하나씩 확인
    {
        result=search(0,N-1,y[i]);
        printf("%d\n",result);
    }
}

int search(int s,int e,int key){
    int mid=(s+e)/2;
    if (s>e)                          //N 배열에 값이 존재하지 않는 경우
        return 0;
    if (x[mid]==key)                  //찾는 값이 존재하는 경우
        return 1;
    else if (x[mid]>key)              //찾는 값이 mid값보다 작은 경우
        return search(s,mid-1,key);           //e=mid-1로 한 후 재귀 이용
    else                              //찾는 값이 mid값보다 큰 경우
        return search(mid+1,e,key);           //s=mid+1로 한 후 재귀 이용
}
