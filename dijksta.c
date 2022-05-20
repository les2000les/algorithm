#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define INF 100000000
#define number 6

/*최단거리에 있는 정점 찾기*/
int vertex(int arr[number][number], int d[number], bool f[number]) {
    int min = INF;
    int index = 0;
    int i;

    for(i=0; i<number;i++){
        if (d[i] < min){ //거리가 min보다 작을 경우
            if (f[i] != 1) {//방문하지 않은 정점일 경우
                min = d[i];
                index = i;
            }
        }
    }
    return index;
}

int showstep(int step, int d[number], bool f[number]) {
    int i;

    printf("\n%d step:\t", step+1);
    printf("\tvertex:  ");
    for (i = 0; i < number; i++) {
        if (f[i] == 0)
            printf("%3c", i + 65);
        else
            printf("%2c*", i + 65);
    }
    printf("\n");

    printf("\t\tdistance:");
    for (i = 0; i < number; i++) {
        if (d[i] == INF) printf(" INF");
        else printf("%3d", d[i]);
    }
    printf("\n");

    printf("\t\tfound:\t  ");
    for (i = 0; i < number; i++) {
        if (f[i] == 1)
            printf(" * ");
        else
            printf(" - ");
    }
    printf("\n");
    step++;

    return step;
}

/*dijkstra 알고리즘 (shortest_path)*/
void dijkstra(int arr[number][number], int start)
{
    bool f[number]; //방문 여부
    int d[number];  //최소 거리
    int i, j;
    int step;
    for (i = 0; i < number; i++) {  //초기화
        d[i] = arr[start][i];
        f[i] = false;  
    }
    f[start] = true; 
    
    for (i = 0; i < number-1; i++) {
        step = showstep(i,d,f);  //step 출력
        int min = vertex(arr,d,f);
        f[min] = true;

        for (j = 0; j < number; j++) {
            if (f[j]!=1) { //방문하지 않은 정점일 경우
                if (d[min] + arr[min][j] < d[j]) {
                    d[j] = d[min] + arr[min][j];
                }
            }
        }
    } 
    printf("\n===============result===============");
    step = showstep(step,d,f);
}

int main() {
    //case1
       int arr[6][6] = {
        {0,7,3,5,INF,INF},
        {7,0,3,INF,4,INF},
        {3,3,0,4,8,INF},
        {5,INF,4,0,7,9},
        {INF,4,8,7,0,2},
        {INF,INF,INF,9,2,0}
    };
    /*
    //case2
    int arr[6][6] = {
        {0,7,9,INF,INF,14},
        {7,0,10,15,INF,INF},
        {8,10,0,11,INF,2},
        {INF,15,11,0,6,INF},
        {INF,INF,INF,6,0,9},
        {14,INF,2,INF,9,0}

    };
    
    //case3
        int arr[6][6] = {
        {0,6,3,INF,INF,INF},
        {6,0,2,5,INF,INF},
        {3,2,0,3,4,INF},
        {INF,5,3,0,2,3},
        {INF,INF,4,2,0,5},
        {INF,INF,INF,3,5,0}
    };
    */
    int start;
    printf(" enter start vertex: ");
    scanf_s("%d", &start);

    dijkstra(arr, start);
}
