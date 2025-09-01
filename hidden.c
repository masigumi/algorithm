/*
// 숨은 그림을 의미하는 숫자가 2개인 숨은 그림을 찾는 코드
// Code to find hidden pictures with 2 numbers representing hidden pictures

#include <stdio.h>

int N; // 풍경화의 크기 size of landscape painting
int a[10 + 10][10 + 10]; // 풍경화 landscape painting
int X1, X2; // 숨은 그림을 의미하는 2개의 숫자 2 numbers representing hidden pictures

int di[8] = { -1,-1,0,1,1,1,0,-1 };
int dj[8] = { 0,1,1,1,0,-1,-1,-1 };
int Solve(void) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] != X1) continue;
			for (int k = 0; k < 8; k++) {
				int ni = i + di[k];
				int nj = j + dj[k];
				if (ni < 0 || ni >= N) continue;
				if (nj < 0 || nj >= N) continue;
				if (a[ni][nj] != X2) continue;
				count++;
			}
		}
	}
	return count;
}

void InputData(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	scanf("%d %d", &X1, &X2);
}

int main(void) {
	int ans;
	InputData();
	ans = Solve();
	printf("%d", ans);
	return 0;
}
*/

#include <stdio.h>

int N; // 풍경화의 크기 size of landscape painting
int a[10 + 10][10 + 10]; // 풍경화 landscape painting
int X1, X2, X3; // 숨은 그림을 의미하는 3개의 숫자 3 numbers representing hidden pictures

void InputData(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	scanf("%d %d %d", &X1, &X2, &X3);
}

int di[8] = { -1,-1,0,1,1,1,0,-1 };
int dj[8] = { 0,1,1,1,0,-1,-1,-1 };

int Solve(void) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] != X1) continue;
			for (int k = 0; k < 8; k++) {
				int ni = i + di[k];
				int nj = j + dj[k];
				if (ni < 0 || ni >= N) continue;
				if (nj < 0 || nj >= N) continue;
				if (a[ni][nj] != X2) continue;
                ni = i + (2*di[k]);
                nj = j + (2*dj[k]);
                if (ni < 0 || ni >= N) continue;
				if (nj < 0 || nj >= N) continue;
                if(a[ni][nj] != X3) continue;
				count++;
			}
		}
	}
	return count;
}

int main(void) {
	int ans = -1;
	InputData(); // 입력 input

	// 코드 작성 write code

    ans = Solve();

	printf("%d", ans); // 출력 output
	return 0;
}
