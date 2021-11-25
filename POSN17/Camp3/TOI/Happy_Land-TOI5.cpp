/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Recursion [ Permutation ]
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

const int MaxN = 3 + 1;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

double a[MaxN][MaxN];
bool mark[MaxN][MaxN];

int r, c;

double ans = 1e18;

void permu(int state, double sum) {
    if(state == r * c) {
        ans = min(ans, sum);
        return ;
    }
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(mark[i][j])
                continue;
            mark[i][j] = true;
            for(int k = 0; k < 8; k++) {
                int ii = i + d8i[k];
                int jj = j + d8j[k];
                if(ii < 1 || jj < 1 || ii > r || jj > c)
                    continue;
                if(mark[ii][jj])
                    continue;
                a[ii][jj] += a[i][j] * 0.1;
            }
            permu(state + 1, sum + a[i][j]);
            mark[i][j] = false;
            for(int k = 0; k < 8; k++) {
                int ii = i + d8i[k];
                int jj = j + d8j[k];
                if(ii < 1 || jj < 1 || ii > r || jj > c)
                    continue;
                if(mark[ii][jj])
                    continue;
                a[ii][jj] -= a[i][j] * 0.1;
            }
        }
    }
}

void solve() {
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    permu(0, 0);
    printf("%.2lf\n", ans);
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
1 2
500 750

2 2
500 750
1000 800

3 3
500000 750000 1000000
500000 1200000 1000000
1000000 800000 750000
*/