/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Constructive Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 5e2 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

char a[MaxN][MaxN];
int up[MaxN][MaxN], down[MaxN][MaxN];


int euclideanDistance(int ai, int aj, int bi, int bj) {
    return (ai - bi) * (ai - bi) + (aj - bj) * (aj - bj);
}

int r, c;

void update(int j) {
    int last;
    last = 0;
    for(int i = 1; i <= r; i++) {
        if(a[i][j] == 'x')
            last = i;
        up[i][j] = last;
    }
    last = 0;
    for(int i = r; i >= 1; i--) {
        if(a[i][j] == 'x')
            last = i;
        down[i][j] = last;
    }
}

void solve() {
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) {
        scanf(" %s", a[i] + 1);
    }
    for(int j = 1; j <= c; j++) {
        update(j);
    }
    int t;
    scanf("%d", &t);
    while(t--) {
        int sti, stj;
        scanf("%d %d", &sti, &stj);
        int ans = 1e9;
        for(int j = 1; j <= c; j++) {
            if(up[sti][j])
                ans = min(ans, euclideanDistance(sti, stj, up[sti][j], j));
            if(down[sti][j])
                ans = min(ans, euclideanDistance(sti, stj, down[sti][j], j));
        }
        printf("%d\n", ans);
        a[sti][stj] = 'x';
        update(stj);
    }
}

int main() {
    int q = 1;
    
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

/*
5 5
..x..
....x
.....
.....
.....
4
3 1
5 3
2 5
4 5
*/