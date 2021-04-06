#include <stdio.h>
#include <string.h>
#define STACK_SIZE 100000
int stack[STACK_SIZE];
int top = -1;

void push(int item);
int pop();

int main() {
	int n;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {          
		char s[100000] = { 0 };
		scanf("%s", s);
		top = -1;
		for (int j = 0; j < strlen(s); j++) {     
			if (top != -1) {                      //빈 스택이 아닐 경우
				if (stack[top] == s[j])          //스택에 top값과 들어온 값이 같은 경우
					pop();
				else                              //다른 경우
					push(s[j]);
			}
			else                                 //빈 스택일 경우
				push(s[j]);
		}
		if (top == -1)                           //다 끝내고 나서 빈 스택이면 좋은 문자열
			cnt++;
	}
	printf("%d", cnt);
}

void push(int item) {                           
	if (top >= STACK_SIZE - 1) {                
		printf("stack full");
		return;
	}
	stack[++top] = item;                       
}

int pop() {
	if (top < 0) {
		printf("stack empty");
		return -999;
	}
	else 
		--top;
}
