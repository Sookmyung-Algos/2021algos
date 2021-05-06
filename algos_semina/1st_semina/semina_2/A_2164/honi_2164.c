#include <stdio.h>
#define QUEUE_SIZE 500001
int front,rear;
int queue[QUEUE_SIZE];
void addq(int i);
int deleteq();

main(){
    int N,temp;
    front=rear=0;
    scanf("%d",&N);             //N 입력
    for (int i=1;i<=N;i++)      //1~N 값을 큐에 삽입
        addq(i);
    while (rear!=(front+1)%QUEUE_SIZE)      //rear이 front보다 1 큰 경우(=큐에 값이 하나 남은 경우)가 아닐 때까지 반복
    {
        deleteq();              //맨 앞의 카드 삭제
        temp=deleteq();         //그 다음 카드 삭제 후
        addq(temp);             //맨 뒤에 삽입
    }
    printf("%d",queue[rear]);   //큐에 남은 하나의 카드 값 출력
}

void addq(int i){               //큐에 원소 삽입하는 함수
    rear=(rear+1)%QUEUE_SIZE;           //rear 포인터 값 증가
    queue[rear]=i;                      //rear 위치에 i 값 삽입
}

int deleteq(){                  //큐의 원소 삭제하는 함수
    front=(front+1)%QUEUE_SIZE;         //front 포인터 값 증가
    return queue[front];                //front 위치의 값 반환
}
