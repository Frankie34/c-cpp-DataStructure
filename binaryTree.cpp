#include <cstdio>
#include <stdlib.h>

#define MAXIMUM 14 /*结点的最大编号*/

typedef char ElemType; /* 数据类型*/

typedef struct btnode {
    ElemType data; /* 数据域*/
    struct btnode *lchild, *rchild; /* 左、右孩子指针域*/
} BTNode;

typedef struct tnode {
    ElemType data;
    struct tnode *lchild, *rchild;
}*bintree;


BTNode *p[MAXIMUM + 1]; /* 辅助向量*/
int count = 0; /*计数器count统计二叉树bt中叶子结点的个数*/


BTNode *Creat_Bt() { /* 建立二叉链表 */
    int i,j;
    char ch;
    BTNode *t;

    printf("\nenter (i,ch) until enter(0,#):\n"); /*输入数对(0,#)时结束*/
    scanf("%d,%c", &i, &ch);
    while (i != 0 && ch != '#') {
        BTNode *s = (BTNode*)malloc(sizeof(BTNode));
        s->data = ch;
        s->lchild = NULL;
        s->rchild = NULL;
        p[i] = s;

        if (i == 1) t = s;
        else {
            j = i / 2;
            if (i % 2 == 0) p[j]->lchild = s;
            else p[j]->rchild = s;
        }
        printf("\n enter i,ch:");
        scanf("%d,%c", &i, &ch);
    }
    return t;
} /* Creat_Bt */


void Leafs(BTNode *bt) { /*计数器count统计二叉树bt中叶子结点的个数*/
    if (bt) {
        if (bt->lchild == NULL && bt->rchild == NULL) { /*输出叶子结点并计数*/
            printf("%3c", bt->data);
            count++;
        }
        Leafs(bt->lchild); /*输出左子树中的叶子结点并计数*/
        Leafs(bt->rchild); /*输出右子树中的叶子结点并计数*/
    }
} /*Leafs*/

void levelTree(bintree t) {
    bintree p0, q0[MAXIMUM];
    int front , rear;
    front = 0;
    rear = 0;
    rear = (rear+1)% MAXIMUM;
    q0[rear] = t;
    while (front!=rear) {
        front=(front+1)%MAXIMUM;
        p0 = q0[front];
        printf("%c", p0->data);
        if (p0->lchild) {
            rear=(rear+1)%MAXIMUM;
            q0[rear]=p0->lchild;
        }
        if (p0->rchild) {
            rear=(rear+1)%MAXIMUM;
            q0[rear]=p0->rchild;
        }
    }
}//用队列按层次遍历二叉树的算法

void PrintTree(BTNode *bt, int level)                   /*按凹入法打印二叉树 level == 1 时输出完整树，其他情况输出第level 层的 bt 子树*/
{   int i;
    if (bt) {
        PrintTree(bt->rchild, level + 1);               /*右子树第level+1层结点横向显示 */
        if (level != 1) {
            for (i = 1; i < 6 *(level - 1); i++)
                printf(" ");                            /*输出空格*/
            printf("----%c\n", bt->data);
        }else printf(" %c\n", bt->data);
        PrintTree(bt->lchild, level + 1);               /*左子树第level+1层结点横向显示 */
    }
}                                                       /*PrintTree*/


void Preorder(BTNode *bt) {                                         /* 先根遍历以bt为根的二叉树 */
    if (bt) {
        printf("%c\t",bt->data);                                            /*访问根结点*/
        Preorder(bt->lchild);                                       /*先根遍历左子树*/
        Preorder(bt->rchild);                                       /*先根遍历右子树*/
    }
}                                                                   /* Preorder */

/*

void Preorder2(BTNode *bt) {                            // 先序遍历二叉树bt非递归算法 ，S是BTNode *类型的栈
    p = bt;
    InitStact(S);                                       //置栈空
    while (p || !StactEmpty(S)) {
        if(p) {                                         // 二叉树非空
            printf(p->data);                            //访问根结点
            Push(S, p);                                 //根指针进栈
            p = p->lchild;                              //p移向左孩子
        }else {                                         //栈非空
            Pop(S, p);                                  //双亲结点出栈
            p=p->rchild;                                //p移向右孩子
        }
    }                                                   // 二叉树空且栈空

}
                                                        //Preorder2
*/


void Inorder(BTNode *bt) {                              /*中序遍历算法以bt为根的二叉树 */
    if (bt) {
        Inorder(bt->lchild);                            /*中根遍历左子树*/
        printf("%c\t",bt->data);                                /* 访问根结点 */
        Inorder(bt->rchild);                            /* 中根遍历右子树*/
    }
} /*Inorder*/

/*
void Inorder2(BTNode *bt) {                             //中序遍历二叉树bt的非递归算法，S是BTNode *类型的栈
    p = bt;
    InitStact(S);                                       //置栈空
    while (p || !StactEmpty(S)) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        }else {
            Pop(S, p);
            printf(p->data);                            // 访问根结点
            p = p->rchild;
        }
    }
}  //Inorder2
*/


void Postorder(BTNode *bt) { /* 后序遍历二叉树bt的递归算法 */
    if (bt) {
        Postorder(bt->lchild);
        Postorder(bt->rchild);
        printf("%c\t",bt->data);
    }
} /*Postorder*/


void DestroyTree(BTNode *bt) { /*销毁二叉树bt*/
    if (bt && bt->lchild) DestroyTree(bt->lchild); /*销毁左子树*/
    if (bt && bt->rchild) DestroyTree(bt->rchild); /*销毁右子树*/
    printf("%3c", bt->data); /* 测试语句*/
    free(bt); /*释放根结点的存储空间 */
} /*DestroyTree*/

int main() {
    BTNode *BT = Creat_Bt();
    PrintTree(BT, 1);
    printf("\n先序\t");
    Preorder(BT);
    printf("\n中序\t");
    Inorder(BT);
    printf("\n后序\t");
    Postorder(BT);
    return 0;
}