#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;

// 변수 선언
int N, d, k, c;
int again, cnt, coupon, maxi = 0;
int sushi[300001];
int check[3001];
vector<int> eat; // 먹는 경우 int타입의 vector로

int main(){

	// N:접시수 d:초밥 가짓수 k:연속접시 C:쿠폰번호
	cin >> N >> d >> k >> c;

	// 회전벨트 위 초밥
	for (int i = 0; i < N; i++) 
		cin >> sushi[i];

	// 슬라이딩 윈도우
	for (int i = 0; i < N; i++)
	{
		again = 0; // 중복된 스시 체크
		coupon = 1; // 쿠폰 스시가 있는지 확인
		for (int j = i; j < i + k; j++)
		{
			if (check[sushi[j % N]] == 1) // 이미 먹은 경우 
				again++; // 중복	
			else // 처음 
				check[sushi[j % N]] = 1; // 체크		

			if (sushi[j % N] == c) // 쿠폰있으면
				coupon = 0; 
		}

		maxi = max(maxi, k - again + coupon); 	
		memset(check, 0, sizeof(check)); // 체크 초기화
	}

	cout << maxi;
}
