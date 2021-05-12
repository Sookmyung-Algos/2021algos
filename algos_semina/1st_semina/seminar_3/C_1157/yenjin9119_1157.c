#include <stdio.h> 
#include <string.h> 
int main(void) {
    int i, j, max, result=0, len;
    char arr[1000000];
    int cnt[26] = {0, };// 알파벳 등장 횟수를 샐 배열
    int select = 0; 
    scanf("%s", arr); 
    len = strlen(arr);
    for(i = 'a'; i <= 'z'; i++) {
        for(j = 0; j < len; j++) { 
            if(i == arr[j]) cnt[i-'a']++; } }//a-z까지의 알파벳을 0-25의 인덱스처럼 사용해 해당 글자의 등장횟수를 세준다
    for(i = 'A'; i <= 'Z'; i++) 
    { for(j = 0; j < len; j++) {
        if(i == arr[j]) cnt[i-'A']++; } } 
    max = cnt[0];
    for(i = 1; i < 26; i++) 
    { if(max < cnt[i]) { max = cnt[i]; select = i; } }//등장 횟수를 비교하여 가장 많이 나온 알파벳이 무엇인지 찾는 과정
    for(i = 0; i < 26; i++) 
    { if(max == cnt[i]) result++; } // 최대 등장 횟수가 한 알파벳에만 해당하는지 확인하는 과정.
  //만약 두개 이상의 알파벳의 등장횟수가 최대 등장횟수와 같다 == '?' 출력해야 함.
    if(result > 1) 
        printf("?\n");
    else printf("%c", select+'A');//출력은 대문자로 하는 것이 조건이었으므로  'A'를 더해 아스키코드를 이용해 문자를 출력함
    return 0;
}
