#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	stack<string> s;
	string strings;
	string temp;
    
	int sum;
	int result = 1;
    
	cin >> strings;
    
	for (int i = 0; i < strings.size(); i++) {
		temp = strings.at(i);
        
		if (temp == "(" || temp == "[")
			s.push(temp);
        
		else {
			sum = 1;
            
			while (!s.empty() && s.top() != "(" && s.top() != "[") {

				sum *= stoi(s.top());
				s.pop();
			}

			if (s.empty() || (temp == ")" && s.top() != "(") || (temp == "]"&& s.top() != "[")) {
				result = 0;
				break; 
			}

			if (temp == ")")
				sum *= 2;
			else
				sum *= 3;
            
			s.pop();

			while (!s.empty() && s.top() != "(" && s.top() != "[") {
				sum += stoi(s.top());
				s.pop();
			}
            
			s.push(to_string(sum));
		}
	}
    
	if (result == 0 || s.size()!=1 || s.top()=="[" || s.top()=="(" )
		cout << 0;
	else
		cout << s.top();

	return 0;
}
