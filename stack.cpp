
#include <cstdio>
#define MAXSIZE 100
#define ElemType int

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

int main() {
    SqStack* S1;
    ElemType e1;
    ElemType e2;
    int i;
    int res = 0;
    InitStack_Sq(S1);
    while(scanf("%d",&i)!=EOF) {
        if(i==0) {
            res = Empty_Sq(S1);
            printf("%d",res);
        }else if(i==1) {
            scanf("%d",&e1); //how to get an input in style of element type
            res = Push_Sq(S1,e1);
            printf("%d",res);
        }else if(i==2) {
            res = Pop_Sq(S1,&e2);
            printf("%d\n%d",e2,res);
        }else return 404;
    }

    return 0;

}

/*
#define STACK_INIT_SIZE 100;
#define STACKINCREMENT 10;


typedef char StackData;							//设置栈中元素类型为 字符型

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
void InitStack ( SeqStack *S) { 				//栈初始化
	S->base =( StackData *)malloc(STACK_INIT_SIZE * sizeof(StackData));
	if (!S->base) { 
		exit(OVERFLOW);
	}
	S->top = S->base ;
	S->stacksize= STACK_INIT_SIZE ; 
	//return ok;
}

void Push (SeqStack *S, StackData x) {			//插入元素x为新的栈顶元素 
	if ( StackFull (S) ){ 						//如果栈非空 												
		S->base =( StackData *)realloc(S->base , (S->stacksize+ STACKINCREMENT) *sizeof(StackData));
		
		////////////////////////////////////////////////
		////////////////////////////////////////////////

		if(! S->base) {							////////////////////////
			exit(overflow); 					//存储分配失败
		}
		
		S->top= S->base + S->stacksize;			//更新栈顶位置 
		S->stacksize+= STACKINCREMENT; 		    //更新存储空间 
	}
	*(S->top)=x;								//插入元素
	(S->top)++;									//更新栈顶位置
	//return ok;
	
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

int pop (SeqStack *S, StackData &x) {           //若栈空返回0, 否则栈顶元素退出到x并返回1 
	if ( StackEmpty(S) ) {
		return 0;
	}
	--(S->top);
	x = *(S->top);
	return 1; 
}
*/










