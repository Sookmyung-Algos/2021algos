// 21735 눈덩이 굴리기(Silver 3)
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> snow;

int bf(int cnt, int index, int size){  // 시간, 현재 위치한 인덱스, 눈덩이 크기
    int ans = 0;
    if(cnt>m) // 시간 넘으면
        return 0;
    if(cnt==m||index==n)  // 제한시간과 같거나 앞마당 끝에 도달한 경우
        return size;
    if(index>n)  // 앞마당 끝보다 더 간 경우
        return 0;
    int move1 = bf(cnt+1, index+1, size+snow[index+1]);  // 1칸
    int move2 = bf(cnt+1, index+2, size/2+snow[index+2]);  // 2칸
    ans = max(move1, move2);
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    snow.resize(n);
    
    for(int i=0;i<n;i++)
        cin>>snow[i];
    cout << bf(0,-1,1);
    return 0;
}
