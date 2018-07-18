#include <cstdio>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int StackData;							//设置栈中元素类型为 字符型

typedef struct { 								//顺序栈定义
    StackData *base; 							//栈底指针
    StackData *top; 							//栈顶指针
    int stacksize;								//当前已分配的存储空间
} SeqStack;



int StackEmpty (SeqStack *S) {					//判栈空,空则返回1  否则返回0
    if( S->top == S->base ) {
        return 1;
    }else return 0;
}

int StackFull (SeqStack *S) {					//判栈满,满则返回1
    if( S->top- S->base >= S-> stacksize ) {
        return 1;
    }else {
        return 0; 								//否则返回0
    }
}

int InitStack (SeqStack *S) { 				//栈初始化
    S->base =(StackData *)malloc(STACK_INIT_SIZE*sizeof(StackData));
    if (!S->base) {
        return 0;
    }
    S->top = S->base ;
    S->stacksize= STACK_INIT_SIZE ;
    return 1;
}

int Push (SeqStack *S, StackData x) {			//插入元素x为新的栈顶元素
    if ( StackFull (S) ){ 						//如果栈非空
        S->base =( StackData *)realloc(S->base , (S->stacksize+ STACKINCREMENT)*sizeof(StackData));

        ////////////////////////////////////////////////
        ////////////////////////////////////////////////

        if(! S->base) {							////////////////////////
            return 0; 					//存储分配失败
        }

        S->top= S->base + S->stacksize;			//更新栈顶位置
        S->stacksize+= STACKINCREMENT; 		    //更新存储空间
    }
    *(S->top)=x;								//插入元素
    (S->top)++;									//更新栈顶位置
    return 1;

    ////////////////////////////////////////////////
    ////////////////////////////////////////////////
}

int Gettop (SeqStack *S, StackData &x) {		//若栈空返回0, 否则栈顶元素读到x并返回1
    if ( StackEmpty(S) ) {
        return 0;
    }
    x = *(S->top-1);
    return 1;
}

int Pop (SeqStack *S, StackData x) {           //若栈空返回0, 否则栈顶元素退出到x并返回1
    if ( StackEmpty(S) ) {
        return 0;
    }
    --(S->top);
    x = *(S->top);
    printf("%d",x);
    return 1;
}

int main() {
    SeqStack* S1;
    StackData e1;
    StackData e2;
    int i;
    int res = 0;
    InitStack(S1);
    printf("输入 1:判栈是否为空 2:入栈 3:出栈\n");
    scanf("%d",&i);
    while(i) {
        if(i==1) {
            printf("判栈是否为空\t");
            res = StackEmpty(S1);
            printf("%d",res);
            scanf("%d",&i);
        }else if(i==2) {
            printf("入栈元素:\t");
            scanf("%d",&e1); //how to get an input in style of elemtype
            res = Push(S1,e1);
            printf("%d",res);
            scanf("%d",&i);
        }else if(i==3) {
            printf("出栈元素:\t");
            res = Pop(S1,e2);
            printf("%d\n%d",e2,res);
            scanf("%d",&i);
        }else {
            printf("ERROR");
            scanf("%d",&i);
        }
    }

    return 0;

}



/*
#include <cstdio>
#define MAXSIZE 100

typedef int ElemType;

typedef struct {
    ElemType elem[MAXSIZE];
    int top;
}SqStack;

void InitStack_Sq(SqStack *S)
{  								//建立一个空栈S
    S->top = 0;
}  								//InitStack_Sq

int Empty_Sq(SqStack *S)
{ 								// 判栈S是否为空 , 空则返回1
    return (S->top == 0);
} 								//Empty_Sq

int Push_Sq(SqStack *S, ElemType x)
{ 									// 若栈S未满，将元素x进栈
    if (S->top == MAXSIZE) {
        return 0; 					// 栈满
    }
    S->elem[S->top] = x;
    S->top++;
    return 1;
} 									//Push_Sq

int Pop_Sq(SqStack *S, ElemType *y)
{ 									//若栈S非空，删除栈顶元素并保存在*y中
    if (S->top == 0) {
        return 0;
    } 								// 栈空
    --S->top;
    *y = S->elem[S->top];
    return 1;
} 									//Pop_Sq

*/

