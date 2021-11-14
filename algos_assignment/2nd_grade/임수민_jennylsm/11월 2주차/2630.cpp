#include <iostream>
using namespace std;

int white = 0, blue = 0;

int board[129][129];

bool isSame(int row_start, int row_end, int col_start, int col_end) {
	int pivot = board[row_start][col_start];

	for (int i = row_start; i <= row_end; i++) {
		for (int j = col_start; j <= col_end; j++) {
			if (pivot != board[i][j])
				return false;
		}
	}

	return true;
}

void colorPaper(int row_start, int row_end, int col_start, int col_end) {
	if (row_start == row_end) {                            
		if (board[row_start][col_start] == 0)
			white++;
		else
			blue++;
		return;
	}

	if (isSame(row_start, row_end, col_start, col_end)) {  
		if (board[row_start][col_start] == 0)
			white++;
		else
			blue++;
		return;
	}

	int row_mid = (row_start + row_end) / 2;
	int col_mid = (col_start + col_end) / 2;

	colorPaper(row_start, row_mid, col_start, col_mid);
	colorPaper(row_start, row_mid, col_mid + 1, col_end);
	colorPaper(row_mid + 1, row_end, col_start, col_mid);
	colorPaper(row_mid + 1, row_end, col_mid + 1, col_end);
}

int main() {
	int N;
	cin >> N;                         

	for (int i = 1; i <= N; i++) {    
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
	}

	colorPaper(1, N, 1, N);

	cout << white << '\n' << blue;
}
