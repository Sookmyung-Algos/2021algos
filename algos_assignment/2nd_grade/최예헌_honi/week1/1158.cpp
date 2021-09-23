#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N,K,num=0,x;
    queue <int> q;
    scanf("%d %d",&N,&K);           //N,K 입력
    for (int i=1;i<=N;i++){         //N번 반복
        q.push(i);                  //큐에 1부터 N까지 push
    }
    printf("<");
    while (q.size()>1){             //큐의 크기가 1보다 클 때까지 반복
        num++;                      //순회
        if ((num%K)==0){            //K의 배수일 때
            x=q.front();
            printf("%d, ",x);       //큐의 front 값 출력
            q.pop();                //큐의 front 값 pop
        }
        else{
            q.push(q.front());      //큐의 front 값 push
            q.pop();                //큐의 front 값 pop
        }
    }                               
    x=q.front();
    printf("%d>",x);                //큐에 남은 값 출력
    return 0;
}
