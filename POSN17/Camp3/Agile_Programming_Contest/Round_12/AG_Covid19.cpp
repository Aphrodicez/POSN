/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Heap
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

const int MaxN = 1e3 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

int dp[MaxN][MaxN];

vector <int> vec[2 * MaxN];

priority_queue <int> pq;

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i <= n + 1; i++) {
        for(int j = 0; j <= n + 1; j++) {
            dp[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int val;
            scanf("%d", &val);
            if(i == 1 && j == 1) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            vec[dp[i][j]].emplace_back(val);
        }
    }
    int ans = 0;
    for(int i = 2 * n - 2; i >= 1; i--) {
        for(int x : vec[i]) {
            pq.push(x);
        }
        ans += pq.top();
        pq.pop();
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
3
1 2 3
4 5 6
7 8 9
*/