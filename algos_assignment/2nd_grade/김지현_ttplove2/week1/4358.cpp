#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main()
{
	int index = 0, num;
	float cnt = 0.0;
	set<string> s;
	string tree;
	map<string, int> trees;
	while (getline(cin, tree)) {
		cnt++;	//입력 받은 총 나무 개수 세기
		if (trees.find(tree) == trees.end()) {
			trees[tree] = 1;
		}
		else {
			num = trees[tree];
			trees[tree] = ++num;
		}
	}
	map<string, int>::iterator it;
	for (it = trees.begin(); it != trees.end(); it++) {
		cout << fixed;
		cout.precision(4);
		cout << it->first << " " << (float)(it->second/cnt)*100 << "\n";
	}
	return 0;
}
