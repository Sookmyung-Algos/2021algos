#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int alpha[26] = {0, };

int main(){
    char str[1000000]={0, }, c;
    int max=0, cnt=0;
    scanf("%s", str);
    for(int i=0;str[i]!=0;i++)
        alpha[toupper(str[i])-'A']++;
    for(int i=0;i<26;i++){
        if(alpha[i]==0) continue;
    	if(alpha[i]>max){
    		max=alpha[i], cnt=1;
    		c=i+'A';
    	}
        else if(alpha[i]==max) cnt++;
    }
    if(cnt>1) printf("?");
    else printf("%c", c);
}
