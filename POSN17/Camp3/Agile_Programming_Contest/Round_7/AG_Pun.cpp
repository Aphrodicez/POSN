/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dijkstra's Algorithm [ Multiple Source ]
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
    int i, j;
    long long w;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int MaxN = 1e3 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

long long a[MaxN][MaxN], dis[MaxN][MaxN];

priority_queue <GRAPH> pq;

void solve() {
    while(!pq.empty())
        pq.pop();
    int r, c;
    cin >> r >> c;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            dis[i][j] = 1e18;
            cin >> a[i][j];
        }
    }
    for(int j = 1; j <= c; j++) {
        dis[1][j] = a[1][j];
        pq.push({1, j, dis[1][j]});
    }
    while(!pq.empty()) {
        int i = pq.top().i;
        int j = pq.top().j;
        long long w = pq.top().w;
        pq.pop();
        if(i == r) {
            cout << w << "\n";
            return ;
        }
        for(int k = 0; k < 4; k++) {
            int ii = i + d4i[k];
            int jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            long long nextw = dis[i][j] + a[ii][jj];
            if(dis[ii][jj] <= nextw)
                continue;
            dis[ii][jj] = nextw;
            pq.push({ii, jj, nextw});
        }
    }
}

int main() {
    setIO();
    int q = 1;
    cin >> q;
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
1
6 5
14 23 6 11 3
18 28 4 13 29
10 25 9 5 18
13 17 20 3 19
5 19 11 1 21
15 2 26 7 30
*/