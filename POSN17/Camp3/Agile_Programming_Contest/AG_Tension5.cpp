/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming
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

const int N = 262144 + 1;
const int M = 2e5 + 10;
const int K = 41 + 19; /// K + log(k)

int dp[K][N];

void solve() {
    memset(dp, 0, sizeof dp);
    int n, num;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> num;
        dp[num][i] = i;
        ans = max(ans, num);
        int j = i - 1;
        while(j > 0) {
            if(!dp[num][j])
                break;
            dp[num + 1][i] = dp[num][j];
            j = dp[num][j] - 1; 
            num++;
            ans = max(ans, num);
        }
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    int q;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
2
4
1 1 1 2
4
0 1 2 3
*/