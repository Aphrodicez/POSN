/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Greedy Algorithm
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

const int MaxN = 1e6 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

long long a[MaxN];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    int ans = 0;
    int l = 1, r = n;
    while(l < r) {
        if(a[l] == a[r]) {
            ++l, --r;
            continue;
        }
        ans++;
        if(a[l] < a[r]) {
            a[l + 1] += a[l];
            ++l;
            continue;
        }
        if(a[r] < a[l]) {
            a[r - 1] += a[r];
            --r;
            continue;
        }
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
1
3
1 2 3
*/