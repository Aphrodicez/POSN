/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Sorting
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

const int MaxN = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

vector <pair <int, int>> g[2];

void solve() {
    int n;
    scanf("%d", &n);
    for(int k = 0; k < 2; k++) {
        g[k].clear();
        for(int i = 1; i <= n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            g[k].push_back(minmax(u, v));
        }
        sort(g[k].begin(), g[k].end());
    }
    printf(g[0] == g[1] ? "Y" : "N");
}

int main() {
    int q = 1;
    q = 5;
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
9
2 4 9 4 6 4 1 4 1 5 3 5 7 5 7 8
1 4 4 9 1 5 6 4 3 5 7 5 7 8 2 4
9 
2 4 9 4 6 4 1 4 1 5 3 5 7 5 7 8
1 4 9 4 1 5 2 4 6 4 3 5 7 5 7 8
9 
2 4 6 4 1 4 1 5 9 4 3 5 7 5 7 8
1 4 9 4 1 5 2 4 6 4 3 5 7 5 7 8
9 
9 4 3 5 7 5 7 8 2 4 6 4 1 4 1 5
1 4 9 4 1 5 2 4 6 4 3 5 7 5 7 8
4 
1 2 2 3 3 4
1 2 1 3 1 4
*/