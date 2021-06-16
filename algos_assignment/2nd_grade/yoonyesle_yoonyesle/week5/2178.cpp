#include<stdio.h>
#include<stdlib.h>
typedef struct element{
	char i, j;
	int cost;
	struct element *link;
}element;
element *first=NULL, *end=NULL;
void enqueue(char i, char j, int cost){
	if(!first){
		first = (element*)malloc(sizeof(element));
		first->i = i;
		first->j = j;
		first->cost = cost;
		first->link = NULL;
		end = first;
	}
	else{
		end->link = (element*)malloc(sizeof(element));
		end = end->link;
		end->i = i;
		end->j = j;
		end->cost = cost;
		end->link = NULL;
	}
}
element* dequeue(){
	element *data = first;
	first = first->link;
	if(!first) end = NULL;
	return data;
}
int main(){
	int n, m;
	char maze[102][102]={0}, dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}, x;
	unsigned i, j, next_i, next_j;
	element *current;
	scanf("%d%d", &n, &m);
	getchar();
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			scanf("%c", &x);
			maze[i][j] = x-48;
		}
		getchar();
	}
	enqueue(1,1,1);
	maze[1][1]=0;
	while(1){
		current = dequeue();
		for(i=0; i<4; i++){
			next_i = current->i+dir[i][0];
			next_j = current->j+dir[i][1];
			if(next_i == n && next_j == m){
				printf("%d", current->cost+1);
				return 0;
			}
			if(maze[next_i][next_j]){
				enqueue(next_i, next_j, (current->cost)+1);
				maze[next_i][next_j]=0;
			}
		}
		free(current);
	}
	return 0;
}
