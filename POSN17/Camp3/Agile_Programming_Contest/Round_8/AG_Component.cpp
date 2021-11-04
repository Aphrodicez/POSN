/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math + Disjoint Set Union
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
    
};

const int MaxN = 1e6;
const int MaxK = 75000;

bitset <MaxN + 10> notPrime;
bitset <MaxN + 10> visited;
int prime[MaxK + 10];
int prime_cnt = 0;

bool not_overflow(int i) {
    return 1ll * i * i <= MaxN;
}

void gen_prime() {
    prime[++prime_cnt] = 2;
    for(int i = 3; prime_cnt < MaxK && i <= MaxN; i += 2) {
        if(notPrime[i])
            continue;
        for(int j = i * i; not_overflow(i) && j <= MaxN; j += i) {
            notPrime[j] = true;
        }
        prime[++prime_cnt] = i;
    }
}

int p[MaxN + 10];

int find_root(int u) {
    if(p[u] == u)
        return u;
    return p[u] = find_root(p[u]);
}

void TESTCASE() {
    
}

void solve() {
    visited = 0;
    int n;
    cin >> n;
    n = prime[n];
    iota(p + 1, p + n + 1, 1);
    for(int u = 1; u <= n; u++) {
        int v = ((1ll * u * u * u) + 1) % n;
        if(!v)
            v = n;
        int ru = find_root(u);
        int rv = find_root(v);
        p[ru] = rv;
    }
    int ans = 0;
    for(int u = 1; u <= n; u++) {
        int ru = find_root(u);
        if(visited[ru])
            continue;
        ans++;
        visited[ru] = true;
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    gen_prime();
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
3
3
4
5
*/