/*quicksort.c
  32193392
  이은송 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 10000
int list[MAX_SIZE];


int partition(int *list, int low, int high) {
	int i, j = low;
	int temp;
	int pivotitem;
	
	pivotitem = list[low]; //list의 가장 왼쪽 값이 pivotitem

	for (int i = low + 1; i <= high; i++) {
		if (list[i] < pivotitem) { //i번째 값이 pivotitem보다 작으면
			j++;   //j를 1만큼 증가시킨다.
			temp = list[i]; //temp에 i번째 값을 저장한다.
			list[i] = list[j]; //i번째에 j번째 값을 저장한다.
			list[j] = temp; //j번째에 temp값을 넣어준다. 
		} //i번째와 j번째의 위치가 바뀐다.
	}

	int pivotpoint = j;
	temp = list[low];   //temp에 list의 가장 왼쪽 값을 저장한다.
	list[low] = list[j]; //가장 왼쪽 위치에 j번째 값을 넣어준다.
	list[j] = temp;  //j번째에 temp값을 넣어준다.
	//j번째와 가장 왼쪽 위치의 값의 위치가 바뀐다.

	return j;
}


void quicksort(int* list, int low, int high) {
	int pivotpoint;  


	if (high > low) {
		pivotpoint = partition(list, low, high);  //pivotpoint는 pivot의 위치이다. 
		quicksort(list, low, pivotpoint - 1); //low부터 pivot 바로 왼쪽 부분 sort
		quicksort(list, pivotpoint + 1, high); //pivot 바로 뒤쪽 부분부터 high까지 sort 
	}
}

int main(void)
{
	int i;
	int num;
	int testcase;
	double start, finish;

	printf("enter your number of random generated elements: ");  //난수 개수 입력받기
	scanf_s("%d", &num);

	for (testcase = 1; testcase < 6; testcase++) {
		srand(time(NULL)); // 난수 초기화

		for (int i = 0; i < num; i++) // num회 반복
		{
			list[i] = rand() % 10000; // 0 ~ 9999 사이가 난수 발생 범위
		}

		start = clock();  //실행 시간 측정 시작'

		quicksort(list, 0, num - 1);

		finish = clock();  //실행 시간 측정 끝

		printf("\n----------Quick sort result----------\n ");
		for (i = 0; i < num; i++)
		{
			printf(" %4d ", list[i]);  //quicksort 결과 출력
		}
		printf("\nrun time: %f", (double)(finish - start) / CLOCKS_PER_SEC);  //실행시간 결과 출력
	}
	return 0;
}
