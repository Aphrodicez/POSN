/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Matrix Chain Multiplication
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

struct PLANE {
    int l, r;
    long long val;
};

const int MaxN = 2e2 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

PLANE a[MaxN];

vector <int> sortedVec;
unordered_map <int, int> mp;

long long dp[2 * MaxN][2 * MaxN];

void solve() {
    mp.clear();
    sortedVec.clear();
    memset(dp, 0, sizeof dp);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].val;
        sortedVec.push_back(a[i].l);
        sortedVec.push_back(a[i].r);
    }
    sort(sortedVec.begin(), sortedVec.end());
    sortedVec.push_back(-1);
    int cnt = 0;
    for(int i = 0; i < (int)sortedVec.size() - 1; i++) {
        if(sortedVec[i] != sortedVec[i + 1])
            mp[sortedVec[i]] = ++cnt;
    }
    for(int i = 1; i <= n; i++) {
        a[i].l = mp[a[i].l];
        a[i].r = mp[a[i].r];
        dp[a[i].l][a[i].r] = max(dp[a[i].l][a[i].r], a[i].val);
    }
    n = cnt;
    for(int sz = 2; sz <= n; sz++) {
        for(int l = 1; l + sz - 1 <= n; l++) {
            int r = l + sz - 1;
            long long mx = 0;
            for(int mid = l + 1; mid <= r - 1; mid++) {
                mx = max(mx, dp[l][mid] + dp[mid][r]);
            }
            dp[l][r] += mx;
        }
    }
    cout << dp[1][n] << "\n";
}

int main() {
    setIO();
    int q = 1;
    cin >> q;
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
4
1 10 1000
2 5 200
3 7 2000
5 9 500
*/