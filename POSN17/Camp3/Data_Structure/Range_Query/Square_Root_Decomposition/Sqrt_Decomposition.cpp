/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Sqrt Decomposition
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

const int MaxN = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

int n;

int a[MaxN];

int sq;

struct SQRT_DECOMPOSITION {
    int cluster[400];
    void update(int idx, int val) {
        int st = idx / sq * sq;
        a[idx] = val;
        cluster[st / sq] = -INF;
        for(int i = st; i <= min(n - 1, st + sq - 1); i++) {
            cluster[i / sq] = max(cluster[i / sq], a[i]);
        }
    }
    int query(int l, int r, int mx = -INF) {
        for(int i = l; i <= r; ) {
            if(i % sq == 0 && i + sq - 1 <= r) {
                mx = max(mx, cluster[i / sq]);
                i += sq;
                continue;
            }
            mx = max(mx, a[i]);
            i++;
        }
        return mx;
    }
};

SQRT_DECOMPOSITION sqd;

void solve() {
    int q;
    scanf("%d %d", &n, &q);
    sq = sqrt(n);
    while(q--) {
        char opr;
        scanf(" %c", &opr);
        if(opr == 'U') {
            int idx, val;   
            scanf("%d %d", &idx, &val);
            idx--;
            sqd.update(idx, val);
            continue;
        }
        if(opr == 'P') {
            int l, r;
            scanf("%d %d", &l, &r);
            l--, r--;
            printf("%d\n", sqd.query(l, r));
        }
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
5 4
U 1 -14
U 1 -1
P 2 2
P 3 5

6 7
U 5 280
U 1 7
P 1 2
P 3 5
U 4 -873760809
U 2 -392
P 1 1
*/