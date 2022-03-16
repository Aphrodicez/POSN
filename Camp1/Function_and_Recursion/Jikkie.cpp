#include <stdio.h>

int ans[30];
int mark[30][30][30];

int A, B, C;

void play(int a, int b, int c) {
	if(a > A || b > B || c > C) 
		return ;
	if(a < 0 || b < 0 || c < 0)
		return ;
	if(mark[a][b][c]) 
		return ;
	mark[a][b][c] = 1;
	if(!a) 
		ans[c] = 1;

	// A->B
	play(a - (B - b), B, c), play(0, a + b, c);
	// B->A
	play(A, b - (A - a), c), play(a + b, 0, c);
	// A->C
	play(a - (C - c), b, C), play(0, b, a + c);
	//C->A
	play(A, b, c - (A - a)), play(a + c, b, 0);
	//B->C
	play(a, b - (C - c), C), play(a, 0, b + c);
	//C->B
	play(a, B, c - (B - b)), play(a, b + c, 0);
}

int main() {
	scanf("%d %d %d", &A, &B, &C);
	play(0, 0, C);
	for(int i = 0; i <= C; i++) {
		if(ans[i])
			printf("%d ", i);
	}
	printf("\n");
	return 0;
}

/*
8 9 10
*/
