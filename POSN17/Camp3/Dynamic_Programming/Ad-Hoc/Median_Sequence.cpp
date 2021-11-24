/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math + Dynamic Programming [ Ad - Hoc ]
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

struct GRAPH {
    
};

const int offset = 1e5;
long long dp[2 * MaxN];

void solve() {
    dp[0 + offset] = 1;
    int n, z;
    scanf("%d %d", &n, &z);
    int less = 0, more = 0;
    long long ans = 0;
    bool found = false;
    for(int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        less += (val < z);
        more += (val > z);
        found |= (val == z);
        if(found) {
            ans += dp[more - less + 100000];
            continue;
        }
        dp[more - less + 100000]++;
    }
    printf("%lld\n", ans);
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
7 4
5 7 2 4 3 1 6
*/