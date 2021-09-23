#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node* next;
	struct node* prev;
}node;

void print(node *n) {
	node* temp = n;
	temp = temp->next;
	while (temp) {
		printf("%c", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	node *head = (node*)malloc(sizeof(node));
	head->data = "!";
	head->prev = head->next = NULL;
	node *cur = head;
	char t;

	while ((t = getchar()) != '\n') {
		node *newnode = (node*)malloc(sizeof(node));
		newnode->data = t;
		newnode->prev = cur;
		newnode->next = NULL;
		cur->next = newnode;
		cur = newnode;
	}
	
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char c;
		scanf(" %c", &c);
		switch (c) {
			case 'L': { // 커서 왼쪽으로 한 칸 옮기기
				if (cur->prev) cur = cur->prev; // 커서가 맨 앞이 아닐 경우
				break;
			}case 'D': {// 커서 오른쪽으로 한 칸 옮기기
				if (cur->next) cur = cur->next;// 커서가 맨 뒤가 아닐 경우
				break;
			}case 'B':{// 커서 왼쪽에 있는 문자 삭제
				if (cur->prev == NULL) continue; // 커서가 맨 앞이면 무시
				node*del = (node*)malloc(sizeof(node)); // 새로운 node 생성
				del = cur; 
				cur = del->prev; // del의 이전노드를 cur
				if (del->next) { // 만약 del의 다음 노드가 있다면
					cur->next = del->next; // 그 다음 노드를 cur의 다음 노드로 연결
					del->next->prev = cur; // 그 다음 노드를 cur과 연결
					del->prev = NULL; // 지울 노드의 이전 노드는 NULL로
				}
				else { cur->next = NULL; } // del의 다음 노드가 없다면 cur의 다음노드를 NULL로
				free(del);
				break;
			}case 'P': { // 문자를 커서 왼쪽에 추가
				char tmp;
				scanf(" %c", &tmp); // 추가할 문자 입력받기
				node* newnode = (node*)malloc(sizeof(node)); //추가할 노드 newnode 생성
				newnode->data = tmp; 
				newnode->prev = cur;
				if (cur->next) { // cur의 다음 노드가 있다면
					newnode->next = cur->next; // newnode를 중간에 삽입
					cur->next->prev = newnode;
				}
				else { // cur의 다음 노드가 없으면
					newnode->next = NULL; // newnode의 다음 노드를 NULL로
				}
				cur->next = newnode; // cur의 다음 노드를 newnode로 만들기
				cur = cur->next; 
				break;
			}
		}
	}
	head = head->next;
	while (head) {
		printf("%c", head->data); // head의 데이터 출력
		head = head->next;
	}


	return 0;
}
