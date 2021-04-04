#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{
	map<string, int> trees;	//나무이름이 key, 나무의 빈도가 value
	float total = 0;	//총 나무의 개수
	string tree;
	float howmany;  //나무 한 종류가 전체에서 차지하는 비중을 저장할 변수
	
	while (getline(cin, tree))	//EOF 입력되기 전까지 계속 입력받기
	{
		if (trees.find(tree) != trees.end())	//map에 이미 나무의 이름이 key로 있으면 value 값 증가
			trees[tree] += 1;
		else	//새로운 나무가 추가되는 경우이면 value 값을 1로 만들기
			trees[tree] = 1;
		total++;  //전체 나무의 개수 증가
	}
	cout << fixed;	//소숫점을 고정시켜 출력하겠다는 뜻
	cout.precision(4);	//소숫점 아래 4자리까지 표현

	map<string, int>::iterator iter; //iterator 타입의 반복자 선언
	for (iter = trees.begin(); iter != trees.end(); iter++)
	{
		howmany = (iter->second / total) * 100;		//나무 한 종류가 전체에서 차지하는 비중 계산
		cout << (iter->first) << " " << howmany << "\n";
	}
	return 0;
}
