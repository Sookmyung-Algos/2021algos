#include <iostream>
#include <string>
using namespace std;

int main() {
	string N;
	int min1, min2, min3, max1, max2, max3, size,tmp,index;
	bool flag,finished;
	cin >> N;
	size = N.size()-1;
	min1 = N[0] - '0';
	max1 = N[size] - '0';
	if (size >=1) {
		min2 = (N[0] - '0') * 10 + (N[1] - '0');
		max2 = (N[size - 1] - '0') * 10 + (N[size] - '0');
		if (size >= 2) {
			min3 = (N[0] - '0') * 100 + (N[1] - '0') * 10 + (N[2] - '0');
			max3 = (N[size - 2] - '0') * 100 + (N[size - 1] - '0') * 10 + (N[size] - '0');
		}
	}
	if (size == 1 && N[0] == N[1]) {
		printf("%d %d", min2, max2);
		return 0;
	}
	if (size == 2 && N[0] == N[1] &&N[0]== N[2]) {
		printf("%d %d", min3, max3);
		return 0;
	}
	//1,1
	finished = false; flag = true; index = 0;
	for (tmp = min1; tmp < max1; tmp++) {
		if (N[index++] - '0' == tmp) continue;
		else {
			flag != flag;
			break;
		}
	}
	if (tmp == max1)finished = true;
	if(min1+1==max1)flag=false;
	if (flag&&finished) {
		printf("%d %d", min1, max1);
		return 0;
	}
	//1,2
	finished = false; flag = true; index = 0;
	for (tmp = min1; tmp < max2; tmp++) {
		if (tmp < 10) {
			if (N[index++] - '0' == tmp) continue;
			else {
				flag != flag;
				break;
			}
		}
		else {
			if ((N[index++] - '0') * 10 + (N[index++] - '0') == tmp) continue;
			else {
				flag != flag;
				break;
			}
		}
	}
	if (tmp == max2)finished = true;
	if (flag && finished) {
		printf("%d %d", min1, max2);
		return 0;
	}
	//1,3
	finished = false; flag = true; index = 0;
	for (tmp = min1; tmp < max1; tmp++) {
		if (tmp < 10) {
			if (N[index++] - '0' == tmp) continue;
			else {
				flag != flag;
				break;
			}
		}
		else if (tmp >= 0 && tmp < 100) {
			if ((N[index++] - '0') * 10 + (N[index++] - '0') == tmp) continue;
			else {
				flag != flag;
				break;
			}
		}
		else {
			if ((N[index++] - '0') * 100 + (N[index++] - '0') * 10 + (N[index++] - '0') == tmp) continue;
			else {
				flag != flag;
				break;
			}
		}
	}
	if (tmp == max3)finished = true;
	if (flag && finished) {
		printf("%d %d", min1, max3);
		return 0;
	}
	//2,2
	finished = false; flag = true; index = 0;
	for (tmp = min2; tmp < max2; tmp++) {
		if (tmp < 100) {
			if ((N[index++] - '0') * 10 + (N[index++] - '0') == tmp) continue;
			else {
				flag != flag;
				break;
			}
		}
		else {
			if ((N[index++] - '0') * 10 + (N[index++] - '0') == tmp) continue;
			else {
				flag != flag;
				break;
			}
		}
	}
	if (tmp == max2)finished = true;
	if(min1+1==max1){
	    if(min2+1==max2){
	        flag=false;
	    }
	    else{
    	    printf("%d %d", min2, max2);
    		return 0;
	    }
	}
	if (flag && finished) {
		printf("%d %d", min2, max2);
		return 0;
	}
	//2,3
	finished = false; flag = true; index = 0;
	for (tmp = min2; tmp < max3; tmp++) {
		if (tmp < 100) {
			if ((N[index++] - '0') * 10 + (N[index++] - '0') == tmp) continue;
			else {
				flag != flag;
				break;
			}
		}
		else {
			if ((N[index++] - '0') * 100 + (N[index++] - '0') * 10 + (N[index++] - '0') == tmp) continue;
			else {
				flag != flag;
				break;
			}
		}
	}
	if (tmp == max3)finished = true;
	if (flag && finished) {
		printf("%d %d", min2, max3);
		return 0;
	}
	//3,3
	finished = false; flag = true; index = 0;
	for (tmp = min3; tmp < max3; tmp++) {
		if ((N[index++] - '0') * 100 + (N[index++] - '0') * 10 + (N[index++] - '0') == tmp) continue;
		else {
			flag != flag;
			break;
		}
	}
	if (tmp == max3)finished = true;
	if(min2+1==max2){
	    printf("%d %d", min3, max3);
		return 0;
	}
	if (flag && finished) {
		printf("%d %d", min3, max3);
		return 0;
	}
}
