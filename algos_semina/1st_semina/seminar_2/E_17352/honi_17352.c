//분리 집합(Disjoint Set, Union Find) 알고리즘 사용
#include <stdio.h>


int getP(int x);            //부모노드의 값 결정
int unionP(int x,int y);    //두 노드를 연결하는 함수
int findP(int x,int y);     //노드가 서로 연결되있는지 확인하는 함수

int bridge[300000];

int main(){
    
    int N,x,y;
    
    scanf("%d",&N);                 //섬(노드)의 개수
    for (int i=1;i<=N;i++)
        bridge[i]=i;        //각 노드의 부모노드에 노드 번호 부여
    for (int i=0;i<N-2;i++) //N-2개의 다리
    {
        scanf("%d %d",&x,&y);          //연결할 섬 입력
        unionP(x,y);        //섬 연결
    }
    for (int i=1;i<=N;i++)      //두 섬이 이어져있는지 확인
    {
        for (int j=i+1;j<=N;j++)
        {
            if (!findP(i,j))    //이어져있지 않는 경우(0리턴)
            {
                printf("%d %d",i,j);
                return 0;
            }
        }
    }
    return 0;
}

int getP(int x){            //부모노드의 값 결정
    if(bridge[x]==x)        //노드 번호 x와 부모 노드가 같은 경우
        return x;           //부모노드는 x
    return bridge[x]=getP(bridge[x]);   //아닌 경우 재귀를 통해 부모노드 구하기
}

int unionP(int x,int y){    //두 노드를 연결하는 함수
    x=getP(x);              //x의 부모노드 읽기
    y=getP(y);              //y의 부모노드 읽기
    
    if (x<y)                //x의 부모 노드가 y의 부모노드보다 작은 경우
    {
        bridge[y]=x;        //x,y의 부모노드는 x
        return x;
    }
    else                    //아닌 경우
    {
        bridge[x]=y;        //x,y의 부모노드는 y
        return y;
    }
}

int findP(int x,int y){     //노드가 서로 연결되있는지 확인하는 함수
    x=getP(x);
    y=getP(y);
    if (x==y)               //x,y의 부모노드가 서로 같은 경우
        return 1;           //서로 연결 따라서 1 리턴
    return 0;               //아닐 경우 0 리턴
}
