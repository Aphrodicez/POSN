/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Ad - Hoc]
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

const int N = 5e6 + 10;
const int M = 2e5 + 10;


int expo[10];

int dp[N];

int Foithong_Faith (int last) {
    if(dp[last] != -1)
        return dp[last];
    dp[last] = 0;
    int tmp = last;
    int now = 0;
    while(tmp > 0) {
        now += expo[tmp % 10];
        tmp /= 10;
    }
    if(last == now)
        return dp[last] = 1;
    else
        return dp[last] = Foithong_Faith(now);
}

void TESTCASE() {
    string s;
    cin >> s;
    int last = 0;
    for(char x : s) {
        last += expo[x - '0'];
    }
    int tmp = last;
    int now = 0;
    while(tmp > 0) {
        now += expo[tmp % 10];
        tmp /= 10;
    }
    dp[now] = Foithong_Faith(now);
    cout << (dp[now] ? "Yes" : "No") << "\n";
}

void solve() {
    memset(dp, -1, sizeof dp);
    int q = 1, k;
    cin >> q >> k;
    for(int i = 1; i <= 9; i++) {
        expo[i] = i;
        for(int j = 2; j <= k; j++) {
            expo[i] *= i;
        }
    }
    while(q--) {
        TESTCASE();
    }
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
4 2
1
2
31
44
*/