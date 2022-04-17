/*radixsort.c
  32193392
  이은송*/

#include<stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 10000
int list[MAX_SIZE];

/////////////////////////////

int main(void)
{
    int i;
    int num;
    int testcase;
    clock_t start, finish;

    printf("enter your number of random generated elements: ");
    scanf_s("%d", &num);
    for (testcase = 1; testcase < 6; testcase++) {

        srand(time(NULL)); // 난수 초기화
        for (int i = 0; i < num; i++) // num회 반복
        {
            list[i] = rand() % 10000; // 0 ~ 9999 사이가 난수 발생 범위
        }

        start = clock();  //시간 측정 시작
        radixsort(list, num);
        finish = clock();  //시간 측정 끝

        printf("\n----------Heap sort result----------\n ");
        for (i = 0; i < num; i++)
        {
            printf(" %4d ", list[i]); //heapsort 결과 출력
        }
        printf("\nrun time: %f", (double)(finish - start) / CLOCKS_PER_SEC); //실행 시간 측정 결과 출력
    }
    return 0;
};
