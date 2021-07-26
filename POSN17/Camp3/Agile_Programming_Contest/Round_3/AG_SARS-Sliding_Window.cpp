/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming + Sliding Window + Binary Search
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

struct RANGE {
    int r, val;
};

const int N = 2e3 + 10;
const int M = 2e5 + 10;
const int J = 1e7 + 10;

vector <int> dp[N];

int a[N];

int dis[N][N];


void TESTCASE() {

}

deque <RANGE> deq;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    for(int i = 1; i <= n; i++) {
        dp[i].push_back(0);
        dp[i].push_back(0);
        cin >> a[i];
    } 
    for(int l = 1; l <= n; l++) {
        for(int r = l + 1; r <= n; r++) {
            dis[l][r] = dis[l][r - 1] + (a[r] - a[r - 1] - 1) / k;
        }
    }
    for(int sz = 2; sz <= n; sz++) {
        while(!deq.empty())
            deq.pop_front();
        for(int i = 1; i <= n; i++) {
            int r = i + sz - 1;
            if(r <= n) {
                while(!deq.empty() && deq.back().val >= dis[i][r])
                    deq.pop_back();
                deq.push_back({r, dis[i][r]});
            }
            while(!deq.empty() && deq.front().r < i)
                deq.pop_front();
            dp[i].push_back(deq.front().val);
        }
    }
    while(q--) {
        int idx, val;
        cin >> idx >> val;
        idx++;
        cout << upper_bound(dp[idx].begin(), dp[idx].end(), val) - dp[idx].begin() - 1 << "\n";
    }
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
5 2 4
4 7 12 13 19
0 1
3 0
4 2
2 4
*/