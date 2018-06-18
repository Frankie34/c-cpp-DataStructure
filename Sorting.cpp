#include<cstdio>
#include<stdlib.h>

#define MAXSIZE 30                                                  /* 顺序表的最大长度*/
typedef struct {
    int key;                                                        /* 排序关键字域 */
    //int data;                                                       /*其它数据域，根据需要自己设定*/
}RcdType ;                                                          /*记录类型*/

void InsertSort ( RcdType *r, int n) {                              /*对表r中的n个记录进行排序，r[0]为监视哨*/
    int i,j;
    for(i=2;i<=n;i++) {
        r[0] = r[i];                                                /* 设置监视哨*/
        j = i-1;
        while( r[0].key < r[j].key) {
            r[j+1] = r[j];
            j--;                                                    /*记录后移*/
        }
        r[j+1] = r[0];                                              /*插入存放在r[0]中的原记录r[i]*/
    }
}/* InsertSort*/

void SelectSort(RcdType *r,int n) {                               /*对表r中的n个记录进行选择排序*/
    int i, j, k;
    RcdType t;
    for(i=1;i<n;i++) {
        k=i;
        for(j=i+1;j<=n;j++) {                                     //每个元素（除了最后一个）与后面的元素比较
            if(r[j].key<r[k].key) k=j;                            //取出key值最小的元素的序号赋值给k
        }
        if(i!=k){                                                 //把序号为k的元素（最小的元素）与未排序队列的第一个元素交换
            t=r[i];
            r[i]=r[k];
            r[k]=t;
        }
    }
}                                                                   /*SelectSort*/

void Heap(RcdType *r,int i, int m) {                        /* i是根结点编号，m是以i结点为根的子树的最后一个结点编号*/
    int j;
    RcdType x;
    x = r[i], j = 2*i;                                      /* x保存根记录的内容，j 为左孩子编号 */
    while(j<=m) {
        if (j<m)
            if ( r[j].key>r[j+1].key ) 
                j++;                                        /* 当结点i有左、右两个孩子时，j取关键字较小的 孩子结点编号 */
        if( r[j].key<x.key) { 
            r[i] = r[j];
            i=j; 
            j=2*i;
        }                                                   /*向下一层探测*/
        else
            j=m+1;                                          /* x.key小于左右孩子的关键字，强制j>m, 以便 结束循环*/
    }
    r[i]=x; 
}

void Heapsort (RcdType *r , int n) {                                /* n为文件的实际记录数， r [0]没有使用 */
    int i, v;
    RcdType x;
    for (i=n/2 ;i>=1; i--)
        Heap(r,i,n);                                                /* 初建堆 */

    for(v=n; v>=2; v--){
        x = r[1];
        r[1] =r[v];
        r[v]=x ;                                                    /* 堆顶堆尾元素对换 */
        Heapsort(r,n-1);                                            /*本次比上次少处理一个记录*/
    }
}


/*
void Quick_Sort(RcdType r[],int low,int high) { // 在表r中从下标low 到下标high的存诸单元中递归形式的快速排序 算法
    i=low;
    j=high;
    t=r[low]; //对r[low]至r[high] 以r[low]为基准作划分
    while(i<j) {
        while ( i<j && r[j].key>t.key )
            j--;
        if(i<j) r[i++]=r[j];
        while ( i<j && r[i].key<=t.key)
            i++;
        if(i<j) r[j--]=r[i];
    }
    r[i]=t;
    if (low<i-1) Quick_Sort(r,low,i-1); //递归，对左子序列作划分
    if (high>i+1) Quick_Sort(r,i+1,high); //递归，对右子序列作划分
}//Quick_Sort

*/

int main() {
    RcdType r[MAXSIZE+1];
    int i, j ,k;
    int num;
    printf("please input a num\n");
    scanf("%d", &num);
    for (i = 1; i <= num; ++i) {
        scanf("%d", &r[i].key);
    }

    //InsertSort (r, num);
    SelectSort(r, num);

    for(i = 1;i <= num; i++) {
        printf("%d\t",r[i].key);
    }

    return 0；
}

