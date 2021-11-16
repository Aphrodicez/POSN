/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: 
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

const int MaxN = 6e6 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct DEQUE {
    int idx;
    long long val;
};

long long qs[MaxN];

deque <DEQUE> mndeq;

void solve() {
    int n, w;
    scanf("%d %d", &n, &w);
    long long ans = 0;
    int sz = 0;
    mndeq.push_back({0, 0});
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &qs[i]);
        qs[i] += qs[i - 1];
        while(!mndeq.empty() && mndeq.front().idx < i - w)
            mndeq.pop_front();
        while(!mndeq.empty() && mndeq.back().val >= qs[i])
            mndeq.pop_back();
        mndeq.push_back({i, qs[i]});
        if(qs[i] - mndeq.front().val == ans) {
            sz = min(sz, i - mndeq.front().idx);
        }
        if(qs[i] - mndeq.front().val > ans) {
            ans = qs[i] - mndeq.front().val;
            sz = i - mndeq.front().idx;
        }
    }
    printf("%lld\n", ans);
    printf("%d\n", sz);
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
7 4
3
2
5
1
4
-7
10

7 3
3
2
5
1
4
-7
10

6 4
-8
-4
-1
-5
-11
-4
*/