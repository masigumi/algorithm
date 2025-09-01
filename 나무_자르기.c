#include <stdio.h>
#include <stdlib.h>

unsigned int N,M;
unsigned int tree[1000000];

void input(void) {
    scanf("%u %u\n", &N, &M);
    for(int i=0;i<N;i++)
        scanf("%u", &tree[i]);
}

int compare(const void* a, const void* b)  {
    return (*(int *)a - *(int *)b);
}

int main(void) {
    unsigned long long min, max, mid, prev_mid;
    int ans = -1;
    unsigned long long sum;
    input();
    qsort(tree, N, sizeof(unsigned int), compare);
    /*
    for(int i=0;i<N;i++)
        printf("%u ", tree[i]);
        */

    min = 0;
    max = tree[N-1];

    while (max>=min) {
        mid = min + (max-min)/2;
//        printf("min:%d mid:%d max:%d\n", min, mid, max);

        sum = 0;
        for(int i=0;i<N;i++) {
            if(tree[i] > mid)
                sum +=  tree[i] - mid;
        }
 //       printf("sum:%d\n", sum);

        if (sum == M) {
            ans = mid;
            break;
        }
        else if(sum > M) { // mid를 오른쪽으로
            min = mid +1;
        }
        else
            max = mid -1;
    }
    if(ans < 0) {
//        printf("min:%d mid:%d max:%d sum:%lld\n", min, mid, max, sum);
        if(sum < M)
            ans = mid -1;
        else
            ans = mid;
    }

    printf("%d\n", ans);
    return 0;
}
