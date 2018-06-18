#include<cstdio>
#include<stdlib.h>

#define VEX_NUM 5
#define ARC_NUM 6
#define MAXSIZE 100

typedef int ElemType;
typedef struct {
    ElemType elem[MAXSIZE];
    int front;
    int rear; //队头、队尾指针
}SqQueue;

typedef int Vextype;
typedef struct {
    Vextype vexs[VEX_NUM];
    int arcs[VEX_NUM][VEX_NUM];
}Mgraph;


int visited[VEX_NUM] = {0,0,0,0,0};


void InitQueue(SqQueue *Sq) { //将循环队列Sq初始化
    Sq->front=0;
    Sq->rear=0;
} //InitQueue


int EnQueue(SqQueue *Sq,ElemType x) { // 在循环队列Sq的尾部插入一个新的元素x
    if( (Sq->rear+1) % MAXSIZE == Sq->front) return 0;
    Sq->elem[Sq->rear]=x;
    Sq->rear=(Sq->rear+1) % MAXSIZE; return 1;
} // EnQueue


int DelQueue(SqQueue *Sq,ElemType *y) { //删除循环队列Sq的队头元素，并存人*y中
    if(Sq->front==Sq->rear) return 0;
    *y=Sq->elem[Sq->front];
    Sq->front=(Sq->front+1) % MAXSIZE ;
    return 1;
} // DelQueue

int QueueEmpty(SqQueue *Sq) {
    if(Sq->front==Sq->rear) {
        return 1;
    }else return 0;
}

void creat_Mgraph(Mgraph *G) {
    int i, j, k;

    for(i=0;i<VEX_NUM;i++) {
        scanf("%d",&G->vexs[i]);
    }

    for(i=0;i<VEX_NUM;i++) {
        for(j=0;j<VEX_NUM;j++) {
            G->arcs[i][j] = 0;
        }
    }

    for(k=0;k<ARC_NUM;k++) {
        printf("arc%d:\n",k);
        scanf("%d,%d", &i, &j);
        G->arcs[i][j] = 1;
        G->arcs[j][i] = 1;
    }
}


void Dfs_m(Mgraph *G, int i) {
    int  j;
    printf("%3c\n",G->vexs[i]);
    visited[i] = 1;
    for(j=0; j<VEX_NUM; j++) {
        if((G->arcs[i][j] == 1)&&(!visited[j])) {
            //printf("%3c\n",G->vexs[j]);
            Dfs_m(G, j);
        }
    }
}


void Bfs_m(Mgraph G, int k) {
    int i, j;
    SqQueue *Q;
    InitQueue(Q);
    printf("%3c", G.vexs[k]);
    visited[k] = 1;
    EnQueue(Q,k);
    while(!QueueEmpty(Q)) {
        DelQueue(Q, &i);
        for(j=0;j<VEX_NUM;j++) {
            if(G.arcs[i][j] == 1 && visited[j] == 0) {
                printf("%3c\n", G.vexs[j]);
                visited[j]=1;
                EnQueue(Q,j);
            }
        }
    }
}


int main() {
    Mgraph Gragh;
    int i;
    printf("%d",'A');
    creat_Mgraph(&Gragh);
    Dfs_m(&Gragh, 0);
    for(i = 0;i<VEX_NUM;i++) {
        visited[i] = 0;
    }
    Bfs_m(Gragh, 0);
    return 0;
}



