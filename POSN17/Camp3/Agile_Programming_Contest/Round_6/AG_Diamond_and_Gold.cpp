/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dijkstra's Algorithm + Dynamic Programming
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

struct GRAPH {
    int i, j, w, state;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int MaxN = 5e2 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

int r, c;

int a[MaxN][MaxN];
int dis[4][MaxN][MaxN];
int dp[4][MaxN][MaxN];

pair <int, int> start[4];

priority_queue <GRAPH> pq;

void dijkstra(int state) {
    int sti = start[state].first, stj = start[state].second;
    dis[state][sti][stj] = a[sti][stj];
    pq.push({sti, stj, dis[state][sti][stj]});
    while(!pq.empty()) {
        int i = pq.top().i;
        int j = pq.top().j;
        pq.pop();
        for(int k = 0; k < 4; k++) {
            int ii = i + d4i[k];
            int jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(dis[state][ii][jj] <= dis[state][i][j] + a[ii][jj])
                continue;
            dis[state][ii][jj] = dis[state][i][j] + a[ii][jj];
            pq.push({ii, jj, dis[state][ii][jj]});
        }
    }
}

void walkAlongDistance() {
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            for(int state = 0; state < 4; state++) {
                dp[state][i][j] = dis[state][i][j] + dis[(state + 3) % 4][i][j] - a[i][j];
                pq.push({i, j, dp[state][i][j], state});
            }
        }
    }
    while(!pq.empty()) {
        int i = pq.top().i;
        int j = pq.top().j;
        int state = pq.top().state;
        pq.pop();
        for(int k = 0; k < 4; k++) {
            int ii = i + d4i[k];
            int jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(dp[state][ii][jj] <= dp[state][i][j] + a[ii][jj])
                continue;
            dp[state][ii][jj] = dp[state][i][j] + a[ii][jj];
            pq.push({ii, jj, dp[state][ii][jj], state});
        }
    }
}

void solve() {
    cin >> r >> c;
    start[0] = make_pair(1, 1);
    start[1] = make_pair(1, c);
    start[2] = make_pair(r, c);
    start[3] = make_pair(r, 1);
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> a[i][j];
            for(int state = 0; state < 4; state++)
                dis[state][i][j] = 1e9;
        }
    }
    for(int state = 0; state < 4; state++)
        dijkstra(state);
    walkAlongDistance();
    int ans = 1e9;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            for(int state = 0; state < 2; state++) {
                ans = min(ans, dp[state][i][j] + dp[state + 2][i][j] - a[i][j]);
            }
        }
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
3 3
1 1 1
1 1 1
1 1 1

5 10
1 1 1 1 1 99 99 99 99 1
99 99 99 99 1 1 1 1 99 1
99 99 1 1 1 99 99 1 1 1
99 99 1 99 1 1 99 99 99 99
1 1 1 99 99 1 1 1 1 1
*/