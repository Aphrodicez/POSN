/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Knapsack
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define i first
#define j second
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

const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int MOD = 1e6 + 3;

void TESTCASE() {
    
}

int dp[N];

int coin[] = {1, 5, 10, 25, 50};

void solve() {
    dp[0] = 1;
    for(int val : coin) {
        for(int i = val; i <= 1e5; i++) {
            dp[i] += dp[i - val];
            dp[i] %= MOD;
        }
    }
    int q;
    cin >> q;
    while (q--){
        int val;
        cin >> val;
        cout << dp[val] << "\n";
    }
}

int main() {
    setIO();
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
2
1
11
*/