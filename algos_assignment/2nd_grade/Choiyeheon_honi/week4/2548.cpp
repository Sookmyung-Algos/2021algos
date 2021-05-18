#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N,mid;
    int v[20000];
    scanf("%d",&N);
    for (int i=0;i<N;i++)
        scanf("%d",&v[i]);
    sort(v,v+N);            //자연수 오름차순 정렬
    mid=(N-1)/2;            //오름차순으로 정렬되있으므로 중간에 있는 값이 대표 자연수
    printf("%d",v[mid]);
}
