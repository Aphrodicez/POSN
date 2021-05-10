/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Binary Search
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

const int N = 1e5 + 10;
const int M = 2e5 + 10;

int dp[N];

int n;

void solve() {
    int num;
    cin >> num;
    cout << upper_bound(dp + 1, dp + n + 1, num) - dp - 1 << "\n";
}

int main() {
    setIO();
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> dp[i];
        dp[i] += dp[i - 1];
    }
    for(int i = n - 1; i >= 1; i--)
        dp[i] = min(dp[i], dp[i + 1]);
    while(q--){
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
3
3
2
5
5
2
*/