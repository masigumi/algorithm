#include <stdio.h>

//https://www.acmicpc.net/problem/6198

int N; // 행성의 수 Number of planets 100,000
int W[100000 + 10]; // 행성 질량 Mass of planets
int stack[1000000 +10];
int top = 0;    //0은 비어있을때, push할 위치, pop은 (top-1)에서

void InputData(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &W[i]);
	}
}

int main(void) {
	int ans = 0;
    int last;

	InputData(); // 입력 Input 

    for(int i=0;i<N;i++) {
        while(top>0 && stack[top-1] <= W[i]) {
            last = stack[top-1];
            top--;
            if(top>0 && last < W[i]) {
//                printf("top:%d w[%d]:%d\n", stack[top], i, W[i]);
                ans++;
            }
        }
        stack[top] = W[i];
        top++;
    }
	// 코드를 작성하세요 Write from here

	printf("%d\n", ans +N-1); // 출력 Output

	return 0;
}