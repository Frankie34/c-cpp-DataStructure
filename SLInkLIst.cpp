#include <cstdio>
#include <cstdlib>

typedef struct LNode{
    int data ;
    struct LNode *next ;
}LNode;



char ListInsert_L(LNode &L0, int i, LNode &L1) {
    LNode* P0 = &L0;
    int j = 0;
    while(P0->data && j < i - 1) {
        P0 = P0->next;
        j++;
    }

    if(P0->data == 0||j > i - 1) return 'O';//O stands outOfrange
    L1.next = P0->next;
    P0->next = &L1;



    return 'K';
}

char ListDelete_L(LNode &L0, int i) {
    LNode* P0 = &L0;
    int j = 0;
    while(P0->data && j < i - 1) {
        P0 = P0->next;
        j++;
    }

    if(P0->data == 0||j > i - 1) return 'O';//O stands outOfrange
    P0->next = (*P0->next).next;



    return 'K';
}


int main() {

    LNode L_END = {0, NULL};
    LNode L_STA = {999, &L_END};



    char ans = 'H';//H stands hello world!


    int i0 ,e0;
    scanf("%d%d", &i0, &e0);
    LNode L_Insert = {e0, &L_END};

    LNode L_P0 = L_STA;
    ans = ListInsert_L (L_P0, i0, L_Insert);
    //printf("%c", ans);

    LNode L_P1 = L_P0;

    while(L_P0.data) {
        printf("%d\n", L_P0.data);
        L_P0 = *L_P0.next;
    }

    scanf("%d", &i0);

    ans = ListDelete_L(L_P1, i0);
    //printf("%c", ans);

    while(L_P1.data) {
        printf("%d\n", L_P1.data);
        L_P1 = *L_P1.next;
    }

    return 0;
}







