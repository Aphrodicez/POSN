/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math
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
const int MaxK = 1e6 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct STICK {
    int idx, h;
    bool operator < (const STICK &o) const {
        if(h != o.h)
            return h < o.h;
        return idx < o.idx;
    }
};

STICK stick[MaxK];
int a[MaxN];

void solve() {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= k; i++) {
        scanf("%d %d", &stick[i].idx, &stick[i].h);
    }
    sort(stick + 1, stick + 1 + k);
    for(int i = k; i >= 1; i--) {
        swap(a[stick[i].idx], a[stick[i].idx + 1]);
    }
    int now;
    scanf("%d", &now);
    int ans = a[now];
    int mx = -INF;
    for(int i = 1; i <= k; i++) {
        int l = stick[i].idx, r = stick[i].idx + 1;
        if(i >= 2 && now - 2 >= 0 && (stick[i].h == stick[i - 1].h) && (now - 2 == stick[i - 1].idx))
            mx = max(mx, a[now - 2]);
        else
            mx = max(mx, a[now - 1]);
        mx = max(mx, a[now + 1]);
        swap(a[l], a[r]);
        if(now == l)
            now = r;
        else if(now == r)
            now = l;
    }
    if(ans >= mx)
        printf("%d\nNO\n", ans);
    else
        printf("%d\nUSE\n", mx);
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
20 5 6 
7 5 3 9 4 
1 5 
1 6 
2 10 
1 12 
3 6 
3 13 
1 

40 5 4 
100 150 115 130 90 
1 10 
2 15 
4 20 
3 25 
3
*/