/*heapsort.c
  32193392
  이은송*/

#include<stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 10000
int list[MAX_SIZE];

void heap(int list[], int num, int i) {
    // Find largest among root, left child and right child
    int max = i;  //부모
    int left = 2 * i + 1;    //왼쪽 자식
    int right = 2 * i + 2;   //오른쪽 자식
    int temp;

    if (left < num && list[left] > list[max])  //왼쪽 자식이 더 큰 경우
        max = left;

    if (right < num && list[right] > list[max]) //오른쪽 자식이 더 큰 경우
        max = right;

    if (max != i) {  //루트가 가장 크지 않을 경우
        temp = list[i];  //temp에 i번째 값을 저장한다.
        list[i] = list[max]; //max번째 값을 i에 저장한다.
        list[max] = temp;  //temp를 max번째 값에 저장한다. i와 max번째 값의 위치가 바뀐다.

        heap(list, num, max);   //max heap을 만든다.
    }
}


void heapsort(int list[], int num) {
    int i = num / 2 - 1;
    int j = num - 1;
    int temp;

    while (i >= 0) { // num/2 -1부터 0까지 
        heap(list, num, i); //heap 만들기
        i--;
    }
    while(j>=0) { 
        j--;
        temp = list[0];  //0번째 값을 temp에 저장한다.
        list[0] = list[j]; //j번째 값을 temp에 넣는다.
        list[j] = temp; //temp를  j번째에 넣는다.
       
        heap(list, j, 0);  //heap만든다.
       
    }
}

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
        heapsort(list, num);
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
