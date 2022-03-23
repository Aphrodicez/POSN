#include<stdio.h>

int mx = -100, n;
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};
int a[30][30];

int max(int a, int b) {
	if(a >= b) 
        return a;
	return b;
}

void play(int i, int j) {
	mx = max(a[i][j], mx);
	for(int k = 0; k < 4; k++) {
		int ii = i + di[k], jj = j + dj[k];
    	if(ii > n || jj > n || ii < 1 || jj < 1)
            continue;
		if(a[ii][jj] <= a[i][j] || a[ii][jj] == 100) 
            continue;
		play(ii, jj);
	}
}
int main() {
	int sj, si;
	scanf("%d %d %d", &n, &sj, &si);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			scanf("%d", &a[i][j]);
	play(si, sj);
	printf("%d\n", mx);
	return 0;
}
