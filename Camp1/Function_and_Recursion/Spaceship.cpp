/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Recursion + Backtracking
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

int X[20], Y[20], Z[20];
int M[20], K[20], C[20];
bool visited[20];

int cost(int x, int y, int z, int i) {
    return (x - X[i]) * (x - X[i]) + (y - Y[i]) * (y - Y[i]) + (z - Z[i]) * (z - Z[i]);
}

int n, shops;
int ans = 2e9;

void permu(int x, int y, int z, int m, int k, int c, int sum) {
    if(min({m, k, c}) >= n) {
        ans = min(ans, sum);
        return;
    }
    if(sum > ans) {
        return ;
    }
    for(int i = 1; i <= shops; i++) {
        if(visited[i])
            continue;
        visited[i] = true;
        permu(X[i], Y[i], Z[i], m + M[i], k + K[i], c + C[i], sum + cost(x, y, z, i));
        visited[i] = false;
    }
}

int main() {
    scanf("%d", &n);
    int stx, sty, stz;
    scanf("%d %d %d", &stx, &sty, &stz);
    scanf("%d", &shops);
    for(int i = 1; i <= shops; i++) {
        scanf("%d %d %d", &X[i], &Y[i], &Z[i]);
        scanf("%d %d %d", &M[i], &K[i], &C[i]);
    }
    permu(stx, sty, stz, 0, 0, 0, 0);
    printf("%d\n", ans);
    return 0;
}

/*
1
0 0 0
2
10 0 0
2 5 7
0 10 0
0 3 9

5
0 0 0
5
60 34 56
0 5 7
90 41 92
1 7 8
24 61 81
6 8 8
41 86 70
5 6 7
46 97 85
9 2 4
*/