/*
 * 输入输出规范
 * 输入：元素1， 插入位置（元素2），元素2
 * 输出：顺序表1，顺序表1，顺序表3
 *
 *
 *
 *
 * 2018.6.18
 *
 * */

#include <cstdio>
#include <cstdlib>
# define LIST_INIT_SIZE 100
# define LISTINCREMENT 10

typedef int ElemType;


typedef struct {
    int *elem;
    int length;
    int listsize;
}SqList;





char InitList_Sq(SqList &L) {
    L.elem = (int *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem) return ('V');
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return 'K';
}

char ListInsert_Sq(SqList &L, int i, int e) {
    if(i < 1 || i > L.length+1) return 'E';
    if(L.length + 1 >= L.listsize) {
        int* newbase;
        newbase = (int *)realloc(L.elem, (L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)return 'V';
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }

    int *q,  *p;
    q = &(L.elem[i - 1]);
    for(p = &(L.elem[L.length-1]);p >= q; --p)
        *(p+1) = *p;
    *q = e;
    ++L.length;
    return 'K';
}

char ListDelete_Sq(SqList &L, int i, int e) {
    if((i < 1)||(i > L.length)) return 'E';
    int *q,  *p;
    p = &(L.elem[i - 1]);
    e = *p;
    q = L.elem + L.length - 1;
    for(++p;p <= q;++p)
        *(p-1) = *p;
    --L.length;
    return 'K';
}




int main() {
    int j;
    int position;
    ElemType e, e1, e2;
    SqList List;
    printf("元素1：\t");
    scanf("%d", &e1);
    printf("插入位置：\t");
    scanf("%d", &position);
    printf("元素2：\t");
    scanf("%d", &e2);

    InitList_Sq(List);
    ListInsert_Sq(List, 1, e1);
    for(j=0;j<List.length;j++) {
        printf("%d",List.elem[j]);
    }
    printf("\n");
    ListInsert_Sq(List, position, e2);
    for(j=0;j<List.length;j++) {
        printf("%d",List.elem[j]);
    }
    printf("\n");
    ListDelete_Sq(List, position, e);
    for(j=0;j<List.length;j++) {
        printf("%d",List.elem[j]);
    }
    printf("\n");
    printf("Hello, 顺序表!\n");
    return 0;
}