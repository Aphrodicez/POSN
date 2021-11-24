/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [ Ad - Hoc ]
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

unordered_map <long long, int> dp;

void solve() {
    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    int ans = 0;
    long long r = 0, o = 0;
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        char val;
        scanf(" %c", &val);
        r += (val == 'R') * k;
        o += (val == 'O');
        if(dp.find(r - o) != dp.end())
            ans = max(ans, i - dp[r - o]);
        else
            dp[r - o] = i;
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
15 3
RORROOROOROOORO

17 3
OROOOOOROOOOORRRR
*/