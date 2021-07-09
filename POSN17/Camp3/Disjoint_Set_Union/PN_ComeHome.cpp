/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Disjoint Set Union
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

const int N = 3e5 + 10;
const int M = 2e5 + 10;

int pa[N];

int find_root(int u) {
    if(pa[u] == u)
        return u;
    return pa[u] = find_root(pa[u]);
}

bool visited[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        pa[i] = i;
    }
    int u, v;
    for(int i = 1; i <= n; i++) {
        cin >> u >> v;
        int ru = find_root(u);
        int rv = find_root(v);
        if(!visited[ru]) {
            visited[ru] = true;
            pa[ru] = rv;
            cout << "Yes" << "\n";
            continue;
        }
        if(!visited[rv]) {
            visited[rv] = true;
            pa[rv] = ru;
            cout << "Yes" << "\n";
            continue;
        }
        cout << "No\n";
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
6 4
1 2
1 3
1 2
1 2
1 3
2 4

9 10
1 2
3 4
5 6
7 8
9 10
2 3
1 5
8 2
7 9
*/