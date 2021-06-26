/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dijkstra's Algorithm [All Pair Shortest Path]
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
    int i, j, w;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int N = 3e1 + 10;
const int M = 2e5 + 10;

char a[N][N];

int dis[N][N][N][N];

priority_queue <GRAPH> dijk;

void solve() {
    int n, sameType, differentType;
    cin >> n >> sameType >> differentType;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                for(int l = 1; l <= n; l++) {
                    dis[i][j][k][l] = 1e9;
                }
            }
        }
    }
    int ans = 0;
    for(int sti = 1; sti <= n; sti++) {
        for(int stj = 1; stj <= n; stj++) {
            dis[sti][stj][sti][stj] = 0;
            dijk.push({sti, stj, 0});
            while(!dijk.empty()) {
                int i = dijk.top().i;
                int j = dijk.top().j;
                int w = dijk.top().w;
                dijk.pop();
                ans = max(ans, dis[sti][stj][i][j]);
                for(int k = 0; k < 4; k++) {
                    int ii = i + d4i[k];
                    int jj = j + d4j[k];
                    if(ii < 1 || jj < 1 || ii > n || jj > n)
                        continue;
                    int nextw = dis[sti][stj][i][j];
                    if(a[i][j] == a[ii][jj])
                        nextw += sameType;
                    else
                        nextw += differentType;
                    if(dis[sti][stj][ii][jj] <= nextw)
                        continue;
                    dis[sti][stj][ii][jj] = nextw;
                    dijk.push({ii, jj, dis[sti][stj][ii][jj]});
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    int q;
    cin >> q;
    while(q--) {
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
3 1 2
AAA
ABA
AAB
*/