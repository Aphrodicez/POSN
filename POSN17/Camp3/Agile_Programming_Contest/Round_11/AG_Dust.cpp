/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming
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

const int MaxN = 2e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct PAIR {
    int x, y, i;
    bool operator < (const PAIR &o) const {
        if(x != o.x)
            return x < o.x;
        return y < o.y;
    }
};

PAIR a[MaxN];
int l[MaxN], r[MaxN];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    sort(a + 1, a + 1 + n);
    l[1] = a[1].y;
    for(int i = 2; i <= n; i++) {
        l[i] = min(l[i - 1], a[i].y);
    }
    r[n] = a[n].y;
    for(int i = n - 1; i >= 1; i--) {
        r[i] = max(r[i + 1], a[i].y);
    }
    r[n + 1] = -INF;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(l[i] > r[i + 1])
            ans++;
    }
    printf("%d\n", ans);
}

int main() {
    int q = 1;
    scanf("%d", &q);
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
2
4
1 0
0 1
-1 0
0 -1
3
0 0
1 1
-1 3
*/