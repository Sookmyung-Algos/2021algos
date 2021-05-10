#include <iostream>
#include <algorithm>

using namespace std;

struct point{       //좌표 나타낼 구조체
    int x;
    int y;
}p[100000];

bool compare (struct point a,struct point b){   //비교함수(사용자 지정 함수)
    if (a.x==b.x)                               //x값이 같다면
        return a.y<b.y;                         //y값을 오름차순으로
    else                                        //x값이 다르다면
        return a.x<b.x;                         //x값을 오름차순으로
}

int main(){
    
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    
    cin>>N;
    for (int i=0;i<N;i++)
        cin>>p[i].x>>p[i].y;                    //x좌표,y좌표 입력
    
    sort (p,p+N,compare);                       //[p,p+N)의 구간에서 compare 함수를 이용해 오름차순으로 정렬
    for (int i=0;i<N;i++)
        cout<<p[i].x<<' '<<p[i].y <<'\n';
}
