#include <stdio.h>
#include <stdlib.h>
int N; // 이물질의 개수 number of foreign matter 1<=N<=50,000
int K; // 장비 최대 사용가능 횟수 maximum number of equipment available 1<=K=<10
int X[50000]; // 이물질의 위치 location of foreign matter 0<=X<=1,000,000,000
int min[10];
int max[10];
int mid[10];
int v_arry[10];

void InputData(void) {
	int i;
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++) {
			scanf("%d", &X[i]);
	}
}

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int is_covered(int V) {
    int used = 0;
    int limit;
    int i= 0;
    while(i<N) {
        used ++;
        if (used > K)
            return 0;
        limit = X[i] + (2*V);
        while(X[i] <= limit)
            i++;
    };
    return 1;
}
int main(void){
	int ans = -1;
    int V;
    int v_max;
    int v_tmp;
    int low,high,mid;
	InputData(); // 입력 받는 부분 input

    qsort(X, N, sizeof(int), compare);

    /*
    for (int i=0;i<N;i++)
        printf("[%d] ", X[i]);
    printf("\n");
    */

    v_max = (X[N-1]-X[0] +1)/2;
    low = 0;
    high = v_max;
    ans = high;
    while(high >= low) {
        mid = (high + low) /2;
        if (is_covered(mid) == 1) {
            ans = mid;
            high = mid -1;
        }
        else
            low = mid +1;
    }

	// 여기서부터 작성 write code
	printf("%d\n", ans);// 출력하는 부분 output
	return 0;
}