#include <stdio.h>

char a[1010][90];

int cnt = 0;

int r, c;

void play(int i, int j) {
	if(i < 0 || j < 0 || i > r - 1 || j > c - 1)
        return ;
	if(a[i][j] != '*')
        return ;
	a[i][j] = '.';
	++cnt;
	play(i - 1, j);
    play(i, j + 1);
    play(i + 1, j);
    play(i, j - 1);
}

int main() {
	scanf("%d %d", &c, &r);
	int mx = 0;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			scanf(" %c", &a[i][j]);
        }
	}
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(a[i][j] == '*') {
				cnt = 0;
				play(i, j);
				if(mx < cnt) 
                    mx = cnt;
			}
		}
	}
	printf("%d\n", mx);
	return 0;
}

/*
10 5
..*.....**
.**..*****
.*...*....
..****.***
..****.***
*/