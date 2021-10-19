/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming
    Status	: Accepted
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

struct GRAPH {
    
};

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

int a[100010];
int dp[100010];
int qs[2][100010];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if(i == 1)
            continue;
        int l = min(a[i], a[i - 1]), r = max(a[i], a[i - 1]);
        dp[l + 1]++;
        dp[(r - 1) + 1]--;
    }
    for(int i = 1; i <= 100000; i++) {
        dp[i] += dp[i - 1];
        qs[i % 2][i] = qs[i % 2][i - 1] + dp[i];
        qs[(i + 1) % 2][i] = qs[(i + 1) % 2][i - 1];
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        if(!l)
            l++;
        printf("%d %d\n", qs[0][r] - qs[0][l - 1], qs[1][r] - qs[1][l - 1]);
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
6
0 4 1 5 0 1
5
3 5
1 4
0 10
5 6
4 6
*/