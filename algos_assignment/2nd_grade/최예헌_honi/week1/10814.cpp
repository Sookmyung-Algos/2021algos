#include <iostream>
#include <algorithm>

using namespace std;

struct person{                           //구조체 이용
    int age;
    char name[101];
    int join;
}member[100001];

bool compare(struct person a, struct person b){         //비교함수
    if (a.age == b.age)                                 //나이가 같다면
        return a.join<b.join;                           //먼저 가입한 사람 먼저
    else
        return a.age<b.age;                             //나이 적은 사람 먼저
}

int main() {
    int N;
    scanf("%d",&N);                                     //회원의 수
    for(int i=0;i<N;i++){
        scanf("%d" "%s",&member[i].age,member[i].name);    //각 회원의 나이와 이름 입력
        member[i].join=i;                                //회원의 가입순서는 변수 i의 값
    }
    
    sort(member,member+N,compare);            //구간 [member,member+N)에서 compare 함수의 return 값에 맞게 정렬 동작
    for(int j=0;j<N;j++){
        printf("%d %s\n",member[j].age,member[j].name);
    }
}
