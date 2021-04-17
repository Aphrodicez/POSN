/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Recursive
	Status	: 
*/

#include <bits/stdc++.h>
using namespace std;

int r, c;

int mark[5][5], neighborSell[5][5];

int di[] = {1, 1, 1, 0, 0, -1, -1, -1}, dj[] = {1, 0, -1, -1, 1, 1, 0, -1};

double a[10][5][5]; /// Up Times, i, j

double mn = 1e12;

void play(int state, double sum, int i, int j){
	printf("%d %d %d\n", state, i, j);
	int ii, jj, k;
	if(state == r * c){
		printf("%.2lf\n", sum);
		mn = min(mn, sum);
		return ;
	}
	for(int k = 0; k < 8; k++){
		int ii = i + di[k], jj = j + dj[k];
		if(ii < 1 || jj < 1 || ii > r || jj > c)
			continue;
		if(mark[ii][jj])
			continue;
		neighborSell[ii][jj]++;
	}
	for(int k = 0; k < 8; k++){
		int ii = i + di[k], jj = j + dj[k];
		if(ii < 1 || jj < 1 || ii > r || jj > c)
			continue;
		if(mark[ii][jj])
			continue;
		mark[ii][jj] = 1;
		play(state + 1, sum + a[neighborSell[ii][jj]][ii][jj], ii, jj);
		mark[ii][jj] = 0;
	}
	for(int k = 0; k < 8; k++){
		int ii = i + di[k], jj = j + dj[k];
		if(ii < 1 || jj < 1 || ii > r || jj > c)
			continue;
		if(mark[ii][jj])
			continue;
		neighborSell[ii][jj]--;
	}
}



int main(){
    scanf("%d %d", &r, &c);
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			scanf("%lf", &a[0][i][j]);
			for(int k = 1; k <= r*c; k++){
				a[k][i][j] = (a[k-1][i][j] * 11) / 10;
			}
		}
	}
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			for(int k = 0; k < 8; k++){
				int ii = i + di[k], jj = j + dj[k];
				if(ii < 1 || jj < 1 || ii > r || jj > c)
					continue;
				if(mark[ii][jj])
					continue;
				neighborSell[ii][jj]++;
			}
			mark[i][j] = 1;
			play(0 + 1, 0 + a[neighborSell[i][j]][i][j], i, j);
			mark[i][j] = 0;
			for(int k = 0; k < 8; k++){
				int ii = i + di[k], jj = j + dj[k];
				if(ii < 1 || jj < 1 || ii > r || jj > c)
					continue;
				if(mark[ii][jj])
					continue;
				neighborSell[ii][jj]--;
			}
		}
	}
	printf("%.2lf\n", mn);
    return 0;
}
/*
Test Cases :
Input : 

2 2
500 750
1000 800

1 2
500 750

3 3
500000 750000 1000000
500000 1200000 1000000
1000000 800000 750000

Output :

*/