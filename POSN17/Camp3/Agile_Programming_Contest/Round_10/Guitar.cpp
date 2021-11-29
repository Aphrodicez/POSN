/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Djikstra's Algorithm Kth State
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
    int cnt, state;
    long long w;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

int a[MaxN];

long long dis[MaxN][MaxN];

long long adj[MaxN][MaxN];

priority_queue <GRAPH> pq;

void solve() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%lld", &adj[i][j]);
        }
    }
    for(int j = 0; j <= m + 1; j++) {
        for(int state = 0; state <= k; state++) {
            dis[j][state] = 1e18;
        }
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
    }
    dis[0][0] = 0;
    pq.push({0, 0, 0});
    while(!pq.empty()) {
        int cnt = pq.top().cnt;
        int state = pq.top().state;
        long long w = pq.top().w;
        pq.pop();
        if(cnt == m + 1) {
            printf("%lld\n", dis[cnt][state]);
            return ;
        }
        for(int nextcnt = cnt + 1; nextcnt <= m + 1; nextcnt++) {
            int nextstate = state + (nextcnt - cnt - 1);
            if(nextstate > k)
                break;
            long long nextw = dis[cnt][state] + adj[a[cnt]][a[nextcnt]];
            if(dis[nextcnt][nextstate] <= nextw)
                continue;
            dis[nextcnt][nextstate] = nextw;
            pq.push({nextcnt, nextstate, nextw});
        }
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
5 7 0
0 4 8 6 2
4 0 3 7 9
8 3 0 1 1
6 7 1 0 5
2 9 1 5 0
2 5 3 4 1 3 1

5 7 2
0 4 8 6 2
4 0 3 7 9
8 3 0 1 1
6 7 1 0 5
2 9 1 5 0
2 5 3 4 1 3 1
*/