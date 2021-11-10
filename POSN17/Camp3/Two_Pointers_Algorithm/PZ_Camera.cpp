/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Two Pointers + Binary Search + Math
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
const int MaxM = 1e6;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int a[MaxN];
int pfac[MaxM + 10], cnt[MaxM + 10];
long long minr[MaxN], qs[MaxN];

void gen_prime_factor() {
    for(int i = 1; i <= MaxM; i++) {
        if(pfac[i])
            continue;
        for(int j = 1; i * j * j <= MaxM; j++) {
            pfac[i * j * j] = i;
        }
    }
}

void solve() {
    int n, q, k;
    cin >> n >> q >> k;
    gen_prime_factor();
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = pfac[a[i]];
    }
    int l = 1;
    int cnt_group = 0;
    for(int r = 1; r <= n; r++) {
        if(cnt[a[r]]++==0)
            cnt_group++;
        while(cnt_group == k) {
            minr[l] = r;
            if(--cnt[a[l]]==0)
                --cnt_group;
            l++;
        }
    }
    for(int i = 1; minr[i]; n = i, i++) {
        qs[i] = qs[i - 1] + minr[i];
    }
    
    while(q--) {
        int l, r;
        cin >> l >> r;
        if(!minr[l] || minr[l] > r) {
            cout << 0 << "\n";
            continue;
        }
        int ub = upper_bound(minr + l, minr + n + 1, r) - (minr + 1);
        int sz = ub - l + 1;
        cout << (1ll * sz * (r + 1)) - (qs[ub] - qs[l - 1]) << "\n";
    }
}

int main() {
    setIO();
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
10 3 3
1 1 2 3 2 4 1 4 1 3
2 4
3 7
2 2
*/