#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N (8)

typedef struct{
	int x, y;
}POS;

int N;
POS base[2];
POS pos[MAX_N + 10];
POS a[MAX_N];
POS b[MAX_N];
int a_length =0,b_length = 0;
int visited[MAX_N] = {0,};
int total_fuel = 0;

void Input_Data(void) {
	int i;
	scanf("%d", &N);	// 택배 수거 지점 수 Parcels office location 
	for (i = 0; i < 2; i++) {		// 택배 영업소 위치 입력 Parcels collection point location
		scanf("%d %d", &base[i].x, &base[i].y);
	}
	for (i = 0; i < N; i++) {		// 택배 수거지점 위치 입력 Parcels collection point location
		scanf("%d %d", &pos[i].x, &pos[i].y);
	}
}

void distribute(int mask)
{
    a_length = 0;
    b_length = 0;
    for (int i = 0; i < N; i++)
    {

        if (mask & (1 << i))
        {
            a[a_length++] = pos[i];
        }
        else
        {
            b[b_length++] = pos[i];
        }
    }
    //    printf("mask : 0x%x\n", mask);
    /*
    printf("a :");
    for (int i = 0; i < a_length; i++)
    {
        printf("(%d,%d) ", a[i].x, a[i].y);
    }
    printf("\n");
    printf("b :");
    for (int i = 0; i < b_length; i++)
    {
        printf("(%d,%d) ", b[i].x, b[i].y);
    }
    printf("\n");
    */
}

int calculate_fuel(int start_x, int start_y, int end_x, int end_y, int load) {
    int dist;
    dist = (abs(end_y-start_y) + abs(end_x-start_x));
    return (dist * (1+load));
}

int dfs(int num, int fuel, POS *base, POS *pos, int length,int load, int *min_fuel) {
    //num 이 -1이면 base부터 시작
    int next_fuel;  //가는데 필요한 연료
    int t_fuel;

    /*
    printf("num:%d, fuel:%d, base_x:%d, base_y:%d, pos.x:%d, pos.y:%d, length:%d, load:%d\n", num, fuel, base->x, base->y, pos[num].x, pos[num].y, length, load);
    */

    if(length == 0) {
        *min_fuel = 0;
        return 0;
    }
    if(num >=0) {
        visited[num] = 1;
        load ++;
        if (load==(length)) {
            t_fuel = fuel + calculate_fuel(base->x, base->y, pos[num].x, pos[num].y, load);
            if(t_fuel < *min_fuel)
                *min_fuel = t_fuel;
     //       printf("num:%d fuel:%d t_fuel:%d min_fuel:%d\n", num, fuel, t_fuel, *min_fuel);
            visited[num] = 0;
            /*
            printf("ret0 visited :");
            for(int k=0;k<length;k++) {
                printf("[%d]", visited[k]);
                }
            printf("\n");
            */
            return 0;
        }
    }
    else {
        for(int i =0;i<length;i++)
            visited[i] = 0;
    }

    /*
    printf("visited :");
    for(int k=0;k<length;k++) {
        printf("[%d]", visited[k]);
        }
    printf("\n");
    */

    for(int k=0;k<length;k++) {
        if (visited[k] == 0) {
            if (num < 0) {// base
                next_fuel = fuel + calculate_fuel(base->x, base->y, pos[k].x, pos[k].y, 0);
     //           printf("base to first : next_fuel:%d\n", next_fuel);
            }
            else {
      //          printf("num:%d to k:%d : next_fuel:%d\n", num, k, next_fuel);
                next_fuel = fuel + calculate_fuel(pos[num].x, pos[num].y, pos[k].x, pos[k].y, load);
            }
            dfs(k,next_fuel,base, pos, length, load, min_fuel);
        }
    }

    if(num >=0)
        visited[num] = 0;

        /*
    printf("return : num:%d, fuel:%d, base_x:%d, base_y:%d, pos.x:%d, pos.y:%d, length:%d, load:%d\n", num, fuel, base->x, base->y, pos[num].x, pos[num].y, length, load);
    printf("ret1 visited :");
    for(int k=0;k<length;k++) {
        printf("[%d]", visited[k]);
        }
    printf("\n");
    */
    return 0;
}

int main(void) {
	int ans = -1;
    int a_fuel, b_fuel;
    int min_fuel = INT_MAX;
    int a_min_fuel = INT_MAX;
    int b_min_fuel = INT_MAX;
    int fuel;

	// 입력 받는 부분 Input
	Input_Data();

	// 여기서부터 작성 Write the code
    // 2^N 종류의 mask
    for(int i=0;i<(1<<N);i++) {
        distribute(i);

        total_fuel = 0;
        a_min_fuel = INT_MAX;
        b_min_fuel = INT_MAX;
        dfs(-1,0,&base[0], a, a_length, 0, &a_min_fuel);
        dfs(-1,0,&base[1], b, b_length, 0, &b_min_fuel);
        fuel = a_min_fuel + b_min_fuel;
        if(fuel<min_fuel)
            min_fuel = fuel;
     //   printf("i:%d a_min:%d b_min:%d fuel:%d min_fuel:%d\n", i, a_min_fuel, b_min_fuel, fuel, min_fuel);
    }

    ans = min_fuel;

	// 출력하는 부분 Output
	printf("%d\n", ans);

	return 0;
}