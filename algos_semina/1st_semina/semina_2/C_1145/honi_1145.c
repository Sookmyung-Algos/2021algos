#include <stdio.h>

main(){
    int num[5];
    int count,x;
    for (int i=0;i<5;i++){          //5개의 자연수 입력
        scanf("%d",&num[i]);
    }
    
    for(x=1;;x++)
    {
        count=0;
        for(int i=0;i<5;i++)
        {
            if (x%num[i]==0)        //x를 num[i]로 나눈 나머지가 0인 경우(=num[i]의 배수가 x인 경우)
                count++;            //count 증가
        }
        if (count>=3)               //count값이 3 이상인 경우(=대부분의 배수인 경우)
            break;                  //반복문 빠져나옴
    }
    printf("%d",x);
}
