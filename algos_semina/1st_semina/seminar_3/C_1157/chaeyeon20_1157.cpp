#include<stdio.h>
#define MAX 1000001
int main(){
char str[MAX];
int i;
int num[26]={0,};
int max;
int max_index=0;

scanf("%s",str);
for(i=0;str[i]!='\0'; i++){
    if(str[i]<97)
        str[i]+=32;
    num[str[i]-97]++;
}
    max=num[0];
    for(i=1; i<26; i++){
        if(max<num[i]){
            max=num[i];
            max_index=i;
        }
        else if(max==num[i]&&num[i]!=0){
            max_index=-1;
        }
    }
    if(max_index !=-1)
        printf("%c",65+max_index);
    else
        printf("?\n");

   
}
