#include <iostream>
using namespace std;

int n, k, people;
long long taste[20000001];
void merge(long long num[], int left, int mid, int right);

void mergesort(long long taste[]) { //합병정렬 하는 함수
	int mid;

	while (people >= k) { //정렬 진행중인 회원이 k일때까지 반복
		int chicken = n / people; //한 묶음의 원소의 개수
		int left = 0; //정렬의 첫 시작 인덱스 0으로 초기화 
		for (int i = 0; i < people; i++) { //회원의 수만큼
			int mid = left+chicken/2; //중간값은 맨 왼쪽 원소의 인덱스에 한 묶음의 원소의 개수/2만큼 더한 값으로 설정
			merge(taste, left, mid, left + chicken-1); //해당 배열에 대해 merge 함수 실행
			left += chicken; //원소의 개수만큼 맨 왼쪽 원소의 인덱스 더해줌
		}
		people /= 2; //다음 정렬엔 회원을 반으로 줄임
	}
}

void merge(long long num[], int left,int mid, int right) { //합병하는 함수
	int i, left_end, num_items, tmp_pos;
	long long temp[2000001]; //임의의 배열 생성

	left_end = mid - 1; //첫번째 묶음의 맨 오른쪽 인덱스는 mid-1
	tmp_pos = left; //맨 왼쪽 원소부터 탐색 시작 
	num_items = right - left + 1; //현재 합병하고 있는 원소의 개수

	while ((left <= left_end) && (mid <= right)) { //두 묶음에 대해 탐색 
		if (num[left] <= num[mid]) { //첫번째 묶음의 맨 왼쪽 원소가 두번째 묶음의 맨 왼쪽 원소보다 작거나 같다면
			temp[tmp_pos++] = num[left++]; //첫번째 묶음의 맨 왼쪽 원소를 temp에 저장
		}
		else { //첫번째 묶음의 맨 왼쪽 원소가 두번째 묶음의 맨 왼쪽 원소보다 크다면
			temp[tmp_pos++] = num[mid++]; //두번째 묶음의 맨 왼쪽 원소를 temp에 저장
		}
	}

	while (left <= left_end) { //남은 첫번째 묶음의 원소들을 temp에 저장
		temp[tmp_pos++] = num[left++];
	}

	while (mid <= right) { //남은 두번째 묶음의 원소들을 temp에 저장
		temp[tmp_pos++] = num[mid++];
	}

	for (int i = 0; i < num_items; i++) { //해당하는 원소들만큼
		num[right] = temp[right]; //temp의 원소들을 num에 저장
		right--; 
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> taste[i];
	}
	cin >> k;

	people = n/2; 
	
	mergesort(taste); //taste 배열에 대해 mergesort 함수 실행

	for (int i = 0; i < n; i++) {
		cout << taste[i]<<' '; //저장된 배열 출력
	}
	cout << endl;

	return 0;
}
