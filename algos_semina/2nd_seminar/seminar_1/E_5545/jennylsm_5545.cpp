#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int dPrice, tPrice;
int dCalorie;
int tCalorie[100];
double result;

int main() {

	cin >> N;
	cin >> dPrice >> tPrice;
	cin >> dCalorie;
	for (int i = 0; i < N; i++) {
		cin >> tCalorie[i];
	}

	sort(tCalorie, tCalorie + N);

	double totalCalorie = dCalorie;
	double totalPrice = dPrice;

	for (int i = N - 1; i >= 0; i--) {
		if ((totalCalorie / totalPrice) < (totalCalorie + tCalorie[i]) / (totalPrice + tPrice)) {
			totalCalorie = totalCalorie + tCalorie[i];
			totalPrice = totalPrice + tPrice;
		}
		else {
			result = floor(totalCalorie / totalPrice);
			break;
		}
		result = floor(totalCalorie / totalPrice);
	}

	cout << result;
}
