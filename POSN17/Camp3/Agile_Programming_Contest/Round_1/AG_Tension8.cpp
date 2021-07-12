/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math
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

const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    i64 ans = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == s[i - 1])
            continue;
        ans += n * 25;
        ans %= MOD;
    }
    i64 cnt = 1;
    for(int i = 2; i <= n; i++) {
        if(cnt == 1) {
            if(s[i] == s[i - 1])
                continue;
            cnt++;
        }
        else {
            if(s[i] == s[i - 2]) {
                cnt++;
                continue;
            }
            ans -= cnt * (cnt - 1) / 2;
            ans %= MOD;
            ans += MOD;
            ans %= MOD;
            cnt = (s[i] == s[i - 1] ? 1 : 2);
        }
    }
    ans -= cnt * (cnt - 1) / 2;
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
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
3
auv
q
by
*/