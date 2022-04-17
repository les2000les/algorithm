/*mergesort.c
  32193392
  이은송*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 10000
int list[MAX_SIZE];


void merge(int h, int m, int* U, int* V, int *list)
{
    int i, j, k;
    i = j = k = 0;

    while (i < h && j < m) //합칠 때 더 작은 값이 앞으로 들어간다.
    {
        if (U[i] < V[j])
        {
            list[k] = U[i];
            i++;
        }
        else
        {
            list[k] = V[j];
            j++;
        }
        k++;
    }

    if (i >= h) //남은 길이만큼 list에 붙여준다.
    {
        while (j < m)
            list[k++] = V[j++];

    }

    else
    {
        while (i < h)
            list[k++] = U[i++];
    }
}

void mergesort(int num, int *list)
{
    int h = num / 2;  //h는 num의 중간 위치를 찾아서 리스트를 반으로 나눈다. 왼쪽 부분
    int m = num - h;   //h이후의 값으로 오른쪽 부분
    int* U = (int*)malloc(h * sizeof(int));
    int* V = (int*)malloc(m * sizeof(int));

    if (num > 1)
    {
        int i;
        for (i = 0; i < h; i++)
            U[i] = list[i];  //왼쪽
        for (i = 0; i < m; i++)
            V[i] = list[h + i];  //오른쪽

        mergesort(h, U); //왼쪽의 리스트 정렬
        mergesort(m, V); //오른쪽의 리스트 정렬
        merge(h, m, U, V, list); //왼쪽, 오른쪽의 sort 결과를 합친다.
    }
}

int main(void)
{
    int i;
    int num;
    int testcase;
    double start, finish;

    printf("enter the number of random generated elements: "); //난수 개수 입력받기
    scanf_s("%d", &num);
    for (testcase = 1; testcase < 6; testcase++) {
        srand(time(NULL)); // 난수 초기화

        for (int i = 0; i < num; i++) // num회 반복
        {
            list[i] = rand() % 10000; // 0 ~ 9999 사이가 난수 발생 범위
        }

        start = clock();  //실행 시간 측정 시작
        mergesort(num, list);
        finish = clock();  //실행 시간 측정 끝

       printf("\n----------Merge sort result----------\n ");
        for (i = 0; i < num; i++)
        {
            printf(" %4d ", list[i]); //sort 결과 출력
        }
        printf("\n%drun time: %f", testcase, (double)(finish - start) / CLOCKS_PER_SEC); //실행 시간 측정 결과 출력
    }
    printf("\n");
    return 0;
}
