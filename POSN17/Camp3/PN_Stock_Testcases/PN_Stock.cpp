/*
TASK: PN_Stock
LANG: CPP
AUTHOR: PeaTT~
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000 + 10 ;
int a[MAXN],l[MAXN],r[MAXN],n;

int main(){
	int n,q;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i ++)
			scanf("%d",&a[i]);
		int MIN = a[1];
		for(int i = 2 ; i <= n ; i++){
			l[i] = max(l[i-1] , a[i] - MIN);
			MIN = min(a[i],MIN);
		}
		int MAX= a[n];
		for(int i = n-1 ; i >= 1 ; i --){
			r[i] = max(r[i+1] , MAX - a[i]);
			MAX = max(a[i],MAX);
		}
		int sol = 0;
		for(int i = 1 ; i <= n ; i ++)
			sol = max(l[i] + r[i+1],sol);
		printf("%d\n",sol);
		memset(l,0,sizeof l);
		memset(r,0,sizeof r);
	}
	return 0;
}
