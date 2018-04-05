#include <cstdio>
#include <cstdlib>

typedef struct LNode{
    int data ;
    struct LNode *next ;
}LNode;



char ListInsert_L(LNode &L0, int i, LNode &L1) {
    LNode L_P3 = L0;
    int j = 0;
    while(L_P3.data && j < i - 1) {
        L_P3 = *L_P3.next;
        j++;
    }
    if(L_P3.data == 0||j > i - 1) return 'O';//O stands outOfrange
    *L1.next = *L_P3.next;
    *L_P3.next = L1;

    while(L0.data) {
        printf("%d\n", L0.data);
        L0 = *L0.next;
    }

    return 'K';
}


int main() {

    LNode L_END = {0, NULL};
    LNode L_STA = {999, &L_END};

    LNode L_P1 = L_STA;
/*
    while(L_P1.data) {
        printf("%d", L_P1.data);
        L_P1 = *L_P1.next;
    }
*/
    char ans = 'H';//H stands hello world!


    int i0 ,e0;
    scanf("%d%d", &i0, &e0);
    LNode L_Insert = {e0, &L_END};

    LNode* P0 = &L_STA;
    int j = 0;
    while(P0->data && j < i0 - 1) {
        *P0 = *P0->next;
        j++;
    }
    if(P0->data == 0||j > i0 - 1) return 'O';//O stands outOfrange
    *P0->next = L_Insert;
    *L_Insert.next = L_END;

    //ans = ListInsert_L (L_P0, i0, L_Insert);


    while(L_STA.data) {
        printf("%d\n", L_STA.data);
        L_STA = *L_STA.next;
    }

    return 0;
}







