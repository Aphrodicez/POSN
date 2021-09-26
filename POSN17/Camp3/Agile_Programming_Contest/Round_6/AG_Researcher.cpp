/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Sliding Window + Dynamic Programming + Quicksum 1D
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

struct RUBBER {
    long long k, l;
};

struct DEQUE {
    int idx;
    long long val;
};

const int MaxN = 1e6 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE () {
    
}

long long dp[MaxN];

RUBBER qs[MaxN];

deque <DEQUE> deq;

void solve() {
    int n;
    long long k, l;
    cin >> n >> k >> l;
    deq.push_back({0, 0});
    for(int i = 1; i <= n; i++) {
        cin >> qs[i].k >> qs[i].l;
        qs[i].k += qs[i - 1].k;
        qs[i].l += qs[i - 1].l;
        while(!deq.empty()) {
            int idx = deq.front().idx;
            if((qs[i].k - qs[idx].k) <= k && (qs[i].l - qs[idx].l <= l))
                break;
            deq.pop_front();
        }
        while(!deq.empty() && deq.back().val <= dp[i - 1] - (qs[i].k + qs[i].l))
            deq.pop_back();
        deq.push_back({i, dp[i - 1] - (qs[i].k + qs[i].l)});
        dp[i] = (qs[i].k + qs[i].l) + deq.front().val;
    }
    cout << dp[n] << "\n";
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
5 3 5
1 1
2 1
3 1
1 1
2 1
*/