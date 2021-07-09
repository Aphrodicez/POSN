/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Greedy Algorithm
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

const int N = 5e5 + 10;
const int M = 2e5 + 10;

int t[N], h[N];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }
    sort(t + 1, t + n + 1);
    sort(h + 1, h + n + 1, greater <int>());
    for(int i = 1; i <= n; i++) {
        t[i] += h[i];
    }
    sort(t + 1, t + n + 1);
    int ans = 0;
    for(int i = 2; i <= n; i++) {
        ans += t[i] - t[i - 1];
    }
    printf("%d\n", ans);
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
3
158 168 139
132 104 140

2
11 28
68 38

3
9 1 7
6 4 4
*/