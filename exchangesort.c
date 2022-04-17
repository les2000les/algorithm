/*exchangesort.c
  32193392 
  이은송 */

#include<stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 10000
int list[MAX_SIZE];

int num;

void exchangesort(int list[], int num) {
    int i;
    int j;
    int temp;

    for (i = 0; i < (num - 1); i++)
    {
        for (j = (i + 1); j < num; j++)
        {
            if (list[i] > list[j]) //i번째와 j번째 비교
            {
                temp = list[i]; //i번째가 더 클 경우 temp에 저장한다.
                list[i] = list[j];//j번째를 i번째에 저장한다.
                list[j] = temp; //temp를 j번째에 저장한다. 
            } //i번째가 j번째 보다 값이 클 경우 둘의 위치를 바꿔준다.
        }
    }

};

int main(void)
{
    int i;
    int testcase;
    clock_t start, finish;

    printf("enter the number of random generated elements: ");
    scanf_s("%d", &num);
    for (testcase = 1; testcase < 6; testcase++) {

        srand(time(NULL)); // 난수 초기화
        for (int i = 0; i < num; i++) // num회 반복
        {
            list[i] = rand() % 10000; // 0 ~ 9999 사이가 난수 발생 범위
        }

        start = clock();  //시간 측정 시작
        exchangesort(list, num);
        finish = clock();  //시간 측정 끝

        printf("\n----------Exchange sort result----------\n ");
        for (i = 0; i < num; i++)
        {
            printf(" %2d ", list[i]);
        }
      printf("\n%drun time: %f", testcase, (double)(finish - start) / CLOCKS_PER_SEC);
    }
    printf("\n");
    return 0;
};
