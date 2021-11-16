/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Sweep Line Algorithm
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

const int MaxN = 5e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct PAIR {
    int idx, val, i;
    bool operator < (const PAIR &o) const {
        if(idx != o.idx) 
            return idx < o.idx;
        return val < o.val;
    }
};

vector <PAIR> ep;
bool visited[MaxN];

int dp[MaxN];

void solve() {
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    int l, r;
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &l, &r);
        ep.push_back({l, 1, i});
        ep.push_back({r + 1, -1, i});
    }
    sort(ep.begin(), ep.end());
    int sum = 0;
    for(auto x : ep) {
        if(x.val == 1 && sum < k) {
            visited[x.i] = true;
            sum += x.val;
            continue;
        }
        if(x.val == -1 && visited[x.i]) {
            sum += x.val;
        }
    }
    while(m--) {
        int idx;
        scanf("%d", &idx);
        printf(visited[idx] ? "Y\n":"N\n");
    }
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
6 1 4
3 7 2 4 1 3 7 8 8 10 9 15
3 5 4 1

6 2 4
3 7 2 4 1 3 7 8 8 10 9 15
3 5 4 1
*/