/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Minimum Spanning Tree [Prim] + Dynamic Programming + Greedy Algorithm
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

struct GRAPH {

};

const int N = 15e3 + 10; 
const int M = 1e3 + 10;

int x[N], y[N], minEdge[N];

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
        minEdge[i] = 1e9;
    }
    for(int u = 1; u <= n - 1; u++) {
        int nextu = u + 1;
        int w = 1e9;
        for(int v = u + 1; v <= n; v++) {
            minEdge[v] = min(minEdge[v], abs(x[u] - x[v]) + abs(y[u] - y[v]));
            if(w <= minEdge[v])
                continue;
            w = minEdge[v];
            nextu = v;
        }
        swap(x[u + 1], x[nextu]);
        swap(y[u + 1], y[nextu]);
        swap(minEdge[u + 1], minEdge[nextu]);
    }
    k = n - k;
    sort(minEdge + 1, minEdge + n + 1);
    int ans = 0;
    for(int i = 1; i <= k; i++) {
        ans += minEdge[i];
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
5 2
2 9
9 7
14 2
12 9
16 4
*/