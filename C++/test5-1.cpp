#include<cstdio>
#include<algorithm>
using namespace std;
//const int maxn == 10000;

int main() {
	//int n, q, x, a[maxn], kase = 0;
	int count0, count1;
	int i, j, k;
	int key;



	scanf("%d%d", &count0, &count1);
	int s[count0];
	for(i = 0;i < count0;i++) {
		scanf("%d", &s[i]);
	}
	sort(s, s+count0);
	for(k = 0;k < count1;k++) {
		scanf("%d", &key);
		printf("CASE# %d:\n",k+1 );
		int p = lower_bound(s, s+count0, key) - s;
		if(s[p] == key) printf("%d found at %d\n",key ,p+1);
		else printf("%d not found\n",key);

	}
	return 0;
}