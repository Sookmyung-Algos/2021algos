#include <stdio.h>

int main(){
    int n, num[1000], i, j;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &num[i]);
    }
    for(i=n-1; i>0; i--){
        for(j=0; j<i; j++){
            if(num[j]>num[j+1]){
                int temp= num[j];
                num[j]= num[j+1];
                num[j+1]= temp;
            }
        }
    }
  //sort를 해준다.
    for(i=0; i<n; i++){
        printf("%d\n", num[i]);
    }
    return 0;
}
