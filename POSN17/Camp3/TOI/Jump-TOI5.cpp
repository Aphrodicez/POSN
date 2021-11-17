/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Binary Search
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

const int MaxN = 3e4 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int a[MaxN];

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int cnt = upper_bound(a + i, a + 1 + n, a[i] + k) - (a + i + 1);
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
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
11 6
3
6
7
9
10
11
13
16
18
19
20

3 30000
2000
35000
55000
*/