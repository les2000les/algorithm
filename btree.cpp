#include <iostream>
#include <stdlib.h>
using namespace std;

struct BtreeNode // Btree의 노드 구조체
{
    int* data;
    int t;
    int n;
    BtreeNode** Child;
    bool leaf;
};

class Btree {
    BtreeNode *root;
    int t;
};

void search(int k) {
    int index = 0;
}
void traverse(BtreeNode* p)
{
    int i;
    for (i = 0; i < p->n; i++)
    {
        if (p->leaf == false)
        {
            (p->Child[i])->traverse();
        }
        cout << " " << p->data[i];
    }
    if (p->leaf == false)
    {
        traverse(p->Child[i]);
    }
}

void insert(int k)
{
    if (root == NULL)
    {
    }
    else
    {
    }
}

void delete(int k) {

}

int main(void)
{
    int i;
    int start, finish;
    srand(time(NULL)); // 난수 초기화

    for (i = 0; i < 1000; i++)
    {
        int num = rand() % 10000;
        insert(num);
    }
    cout << "b-tree insert" << endl; 
    start = clock();  //실행 시간 측정 시작
    traverse(root);
    finish = clock();  //실행 시간 측정 끝
    return 0;
}
