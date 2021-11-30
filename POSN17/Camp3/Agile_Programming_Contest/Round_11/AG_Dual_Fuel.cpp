/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Sliding Window
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

const int MaxN = 2e6 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct DEQUE {
    int idx;
    long long val;
};

long long a[MaxN], b[MaxN];
deque <DEQUE> deqa, deqb;

void solve() {
    int n, v;
    scanf("%d %d", &n, &v);
    for(int i = 0; i <= n - 1; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i = 0; i <= n - 1; i++) {
        scanf("%lld", &b[i]);
    }
    deqa.push_back({0, a[0]});
    deqb.push_back({0, b[0]});
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        while(!deqa.empty() && i - deqa.front().idx > v)
            deqa.pop_front();
        while(!deqb.empty() && i - deqb.front().idx > v)
            deqb.pop_front();
        ans += deqa.front().val + deqb.front().val;
        while(!deqa.empty() && deqa.back().val >= a[i])
            deqa.pop_back();
        while(!deqb.empty() && deqb.back().val >= b[i])
            deqb.pop_back();
        deqa.push_back({i, a[i]});
        deqb.push_back({i, b[i]});
    }
    printf("%lld\n", ans);
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
4 2
3 1 1 4
1 5 1 6
*/