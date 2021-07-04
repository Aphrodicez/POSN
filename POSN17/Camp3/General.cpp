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

const int N = 1e5 + 10;
const int M = 2e5 + 10;

int pa[N];

int find_root(int u) {
    if(pa[u] == u)
        return u;
    return pa[u] = find_root(pa[u]);
}

int troops[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> troops[i];
        pa[i] = i;
    }
    int u, v;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        int ru = find_root(u);
        int rv = find_root(v);
        if(ru == rv) {
            cout << -1 << "\n";
            continue;
        }
        if(ru > rv)
            swap(ru, rv);
        if(troops[ru] >= troops[rv]) {
            troops[ru] += troops[rv] / 2;
            pa[rv] = ru;
            cout << ru << "\n";
        }
        else {
            troops[rv] += troops[ru] / 2;
            pa[ru] = rv;
            cout << rv << "\n";
        }
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
5 4
3
4
5
6
7
1 5
1 2
1 2
3 4
*/