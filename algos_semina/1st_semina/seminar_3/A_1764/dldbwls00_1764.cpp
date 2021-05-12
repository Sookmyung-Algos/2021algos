#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main(){
	int n, m; //듣도 못한 사람의 수 n, 보도 못한 사람의 수 m
	cin >> n >> m;
 
	vector<string> inputname;
	vector<string> resultname;
	string name;
 
	for (int i=0;i<n;i++){ //듣도 못한 사람 이름 입력
		cin >> name;
		inputname.push_back(name);
	}
	sort(inputname.begin(), inputname.end()); // 정렬
 
	vector<string> mname ;//보도 못한 사람 이름 입력
	for (int i=0;i<n;i++){
		cin >> name;
		//중복값이 존재하는 경우 resultname에 따로 보관
		if(binary_search(inputname.begin(), inputname.end(), name))	resultname.push_back(name);
	}
	sort(resultname.begin(), resultname.end()); //정렬
 
	printf("%d\n", (int)resultname.size()); // 크기 출력
    for(int i=0; i<resultname.size(); i++)	printf("%s\n", resultname[i].c_str());
    // c_str(): 반환형이 char *, 해당하는 string의 첫 번째 문자의 주소값(포인터) 반환
	return 0;
}
