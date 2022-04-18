/*radixsort.c
  32193392
  이은송*/

#include<stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 10000
int list[MAX_SIZE];
int newlist[MAX_SIZE];


void radixsort(int list[], int num) {
    int max = list[0];
    int i, j;
    int count = 0;
    int temp;

    for (i = 1; i < num; i++) {
        if (list[i] > max)
            max = list[i];   //가장 큰 숫자를 찾는다.
    }

    while (max != 0)
    {
        max = max / 10;
        ++count;
    } //max값의 자릿수를 구한다.

    for (i = 0; i < count; i++) {

        newlist[i] = (list[i] / 10 ^ (count - 1)) % 10;  //자릿수의 값 구하기

        for (i = 0; i < (num - 1); i++)
        {
            for (j = (i + 1); j < num; j++)
            {
                if (newlist[i] > newlist[j]) //i번째와 j번째  비교
                {
                    temp = list[i]; //i번째가 더 클 경우 temp에 저장한다.
                    list[i] = list[j];//j번째를 i번째에 저장한다.
                    list[j] = temp; //temp를 j번째에 저장한다. 
                } //i번째가 j번째 보다 값이 클 경우 둘의 위치를 바꿔준다.
            }
        }
    }

};

int main(void)
{
    int i;
    int num;
    clock_t start, finish;

    printf("enter your number of random generated elements: ");
    scanf_s("%d", &num);

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
        printf(" %4d ", list[i]);
    }
    printf("\nrun time: %f", (double)(finish - start) / CLOCKS_PER_SEC);
    return 0;
};
