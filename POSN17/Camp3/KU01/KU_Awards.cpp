/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [ Quicksum 1D ] + Greedy Algorithm
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

const int MaxN = 3e2 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int qsl[MaxN], qsr[MaxN], qs0l[MaxN], qs0r[MaxN], dp0[2 * MaxN];
bool mark[2 * MaxN];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> qsl[i];
        if(!qsl[i]) {
            qs0l[i]++;
        }
        else {
            mark[qsl[i]] = true;
        }
        qsl[i] += qsl[i - 1];
        qs0l[i] += qs0l[i - 1];
    }
    for(int i = 1; i <= n; i++) {
        cin >> qsr[i];
    }
    for(int i = n; i >= 1; i--) {
        if(!qsr[i]) {
            qs0r[i]++;
        }
        else {
            mark[qsr[i]] = true;
        }
        qsr[i] += qsr[i + 1];
        qs0r[i] += qs0r[i + 1];
    }
    int cnt = 0;
    for(int i = 2 * n; i >= 1; i--) {
        if(!mark[i]) {
            dp0[++cnt] = dp0[cnt - 1] + i;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, qsl[i] + qsr[i] + dp0[qs0l[i] + qs0r[i]]);
    }
    cout << ans << "\n";
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
5
10 1 9 2 4 3 5 8 6 7

5
0 3 0 0 0 10 0 1 2 0
*/