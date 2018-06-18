#include<cstdio>
#include<stdlib.h>

#define MAXSIZE 100

typedef int Keytype;
typedef struct redtype {
	Keytype key;				/*关键字域 */
	int data;
}SeqTable[MAXSIZE];


int Seq_search(SeqTable r, int n, Keytype K) { 													//返回关键字等于K的元素在表r中的位置，n为表 中元素的个数*,从后往前
	int i = 1;
	r[0].key = K; 				/*监视哨*/
	while (r[i].key != K && i <= n)
		i++;
	if(r[i].key == K) {
		return i;
	}else {
		return 0;
	}
} 								/* Seq_search */

int Bin_search(SeqTable r, int n, Keytype K) {
	int low=1;
	int high=n;
	int mid;
	r[0].key = K; 				/*监视哨*/

	while(low<=high) {
		mid=(low+high)/2;
		if(r[mid].key == r[0].key) {
			return mid;
		}else if(K<r[mid].key) {
			high=mid-1;
		}else {
			low=mid+1;
		}
	}
	return 0;
}                              //Bin_search

int main() {
	SeqTable R;
	int i, j, k;
	int ans;

	R[0].key = NULL;
	R[0].data = 404;
	scanf("%d", &j);
	for(i = 1;i <= j;i++) {
		scanf("%d,%d", &R[i].key, &R[i].data);
		printf("key:%d data:%d\n", R[i].key, R[i].data);
	}
								//init
	printf("\n");
	printf("Seq_search\n");
	scanf("%d", &k);
	ans = Seq_search(R, j, k);
	if(ans == 0) {
		printf("404 no found");
	}else {
		printf("key:%d data:%d", R[ans].key, R[ans].data);
	}

	printf("\n");
	printf("Bin_search\n");
	scanf("%d", &k);
	ans = Bin_search(R, j, k);
	if(ans == 0) {
		printf("404 no found");
	}else {
		printf("key:%d data:%d", R[ans].key, R[ans].data);
	}

	return 0;
}




