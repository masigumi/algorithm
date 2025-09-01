#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    int stage;
} Queue;
int S, E1, E2;
int ans1, ans2;
int visited[10000] = {0,};
Queue queue[10000];
int head =0,tail =0;

void InputData(void)
{
	scanf("%d %d %d", &S, &E1, &E2);
}

int divisor(int input) {
    int cnt = 0;
    for(int i=1;(i*i)<=input;i++) {
        if((i*i) == input)
            cnt ++;
        else if((input %i) == 0)
            cnt +=2;
    }
    return cnt;
}

int bfs(int start, int end) {
    int count = 0;
    int num;
    int stage;
    int num_k;
    int num_h;
    int num_t;
    int num_o;
    int new_num;
    int div_num, div_new;

    head =0;
    tail =0;
    for(int i=0;i<10000;i++)
        visited[i] = 0;
    queue[tail].data = start;
    queue[tail].stage = 0;
    tail++;
    visited[start] = 1;

    while(tail > head) {
    //    printf("queue[head]:%d, div:%d, tail:%d, head:%d, count:%d\n", queue[head].data, divisor(queue[head].data), head, count);
        if(queue[head].data == end) {
         //   printf("found end : %d, count %d\n", end, count);
            return queue[head].stage;
        }
        num = queue[head].data;
        stage = queue[head].stage;
        head++;
        count ++;

        div_num = divisor(num);
        num_k = num/1000;
        num_h = ((num/100)%10);
        num_t = ((num/10)%10);
        num_o = num%10;

        //printf("k:%d, h:%d, t:%d, o:%d\n", num_k, num_h, num_t, num_o);

        for (int i=0;i<10;i++) {
            new_num = (num - num_o) + i;
            if(new_num < 1000)
                continue;
            if(new_num == num)
                continue;
            if(visited[new_num] == 1)
                continue;
            div_new = divisor(new_num);
            if( abs(div_new-div_num) > 1)
                continue;
            
            queue[tail].data = new_num;
            queue[tail].stage = stage+1;
            tail ++;
            visited[new_num] = 1;
   //         printf("new o : %d(%d)\n", new_num, divisor(new_num));
        }
        
        for (int i=0;i<10;i++) {
            new_num = (num - num_t*10) + i*10;
            if(new_num < 1000)
                continue;
            if(new_num == num)
                continue;
            if(visited[new_num] == 1)
                continue;
            div_new = divisor(new_num);
            if( abs(div_new-div_num) > 1)
                continue;
            queue[tail].data = new_num;
            queue[tail].stage = stage+1;
            tail ++;
            visited[new_num] = 1;
  //          printf("new t : %d(%d)\n", new_num, divisor(new_num));

        }

        for (int i=0;i<10;i++) {
            new_num = (num - num_h*100) + i*100;
            if(new_num < 1000)
                continue;
            if(new_num == num)
                continue;
            if(visited[new_num] == 1)
                continue;
            div_new = divisor(new_num);
            if( abs(div_new-div_num) > 1)
                continue;
            queue[tail].data = new_num;
            queue[tail].stage = stage+1;
            tail ++;
            visited[new_num] = 1;
 //           printf("new h : %d(%d)\n", new_num, divisor(new_num));

        }

        for (int i=0;i<10;i++) {
            new_num = (num - num_k*1000) + i*1000;
            if(new_num < 1000)
                continue;
            if(new_num == num)
                continue;
            if(visited[new_num] == 1)
                continue;
            div_new = divisor(new_num);
            if( abs(div_new-div_num) > 1)
                continue;
            queue[tail].data = new_num;
            queue[tail].stage = stage+1;
            tail ++;
            visited[new_num] = 1;
//            printf("new k : %d(%d)\n", new_num, divisor(new_num));

        }

    }

    return 0;
}
int main(void)
{
	InputData();// 입력받는 부분 input

	// 여기서부터 작성 write code
    //printf("S:%d num:%d, E1:%d num:%d, E2:%d num:%d\n", S, divisor(S), E1, divisor(E1), E2, divisor(E2));

    ans1 = bfs(S,E1);
    ans2 = bfs(S,E2);
    
	printf("%d\n", ans1);// 출력하는 부분 output
	printf("%d\n", ans2);
	return 0;
}
