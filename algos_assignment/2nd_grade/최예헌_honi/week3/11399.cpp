#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    vector <int> v;
    int N,x,time,total=0;
    
    scanf("%d",&N);              //사람의 수 입력
    for (int i=0;i<N;i++)        //각 사람이 걸리는 시간 입력 후 벡터에 삽입
    {
        scanf("%d",&x);
        v.push_back(x);
    }
    sort(v.begin(),v.end());     //오른차순으로 정렬(앞에 있는 수들이 반복되므로 반복되는 수가 작을수록 결과가 최소)

    for (int i=0;i<N;i++)
    {
        time=0;
        for (int j=0;j<=i;j++)
        {
            time+=v[j];          //각 사람이 필요한 시간
        }
        total+=time;             //시간의 합
    }
    printf("%d\n",total);
    return 0;
}
