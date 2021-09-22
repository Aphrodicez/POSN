/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming
    Status	: Time Limit Exceeded
*/

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define pc(x) putchar(x)
#define MP make_pair
#define dec(x) fixed << setprecision(x)
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct RUBBER {
    long long k, l;
};

const int MaxN = 2e3 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE   () {
    
}

long long dp[MaxN];

RUBBER qs[MaxN];

void solve() {
    int n;
    long long k, l;
    cin >> n >> k >> l;
    for(int i = 1; i <= n; i++) {
        cin >> qs[i].k >> qs[i].l;
        qs[i].k += qs[i - 1].k;
        qs[i].l += qs[i - 1].l;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            if(qs[i].k - qs[j].k > k || qs[i].l - qs[j].l > l)
                continue;
            dp[i] = max(dp[i], dp[max(0, j - 1)] + (qs[i].k - qs[j].k) + (qs[i].l - qs[j].l));
        }
    }
    cout << dp[n] << "\n";
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
5 3 5
1 1
2 1
3 1
1 1
2 1
*/