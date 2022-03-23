#include<stdio.h>

int n;
int ans[105];
void play(int w, int l, int st=0) {
	if(w==n || l==n) {
		for(int i=0; i<st;  i++)
			printf("%c ", ans[i]?'W':'L');
		printf("\n");
		return;
	}
	ans[st] = 1;
	play(w+1, l, st+1);
	ans[st] = 0;
	play(w, l+1, st+1);
}
int main() {
	int w, l;
	scanf("%d %d %d", &n, &w, &l);
	play(w, l, 0);
	return 0;
}
