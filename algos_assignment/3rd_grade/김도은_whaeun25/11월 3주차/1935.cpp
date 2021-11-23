#include <iostream>
#include <string>
#include <stack>
#include<vector>

using namespace std;

vector<int>num;
stack<double> s;


int main() {
	
	int n;
	string str;

	cin >> n;
	cin >> str;

	for (int i = 0; i<n; i++) {

		int k;

		cin >> k;

		num.push_back(k);
	}

	for (int i = 0; i<str.size(); i++) {

		if (str[i] >= 'A' && str[i] <= 'Z') {
		
			int index = str[i] - 'A';
		
			s.push(num[index]);
		
		}
		else {
			
			double temp2 = s.top();
			
			s.pop();
			
			double temp1 = s.top();
			
			s.pop();
			
			if (str[i] == '*') {
				s.push(temp1*temp2);
			}
			else if (str[i] == '+') {
				s.push(temp1 + temp2);
			}
			else if (str[i] == '-') {
				s.push(temp1 - temp2);
			}
			else if (str[i] == '/') {
				s.push(temp1 / temp2);
			}
		}

	}


	printf("%.2f", s.top());

}
