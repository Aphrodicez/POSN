/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: 
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

struct A{
    int idx, val;
    bool operator < (const A &o) const{
        return idx < o.idx;
    }
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

v(i64) ep;
v(i64) vec;

void solve() {
    i64 n, m, q, l, r;
    scanf("%lld %lld %lld", &n, &m, &q);
    for(i64 i = 0; i < m; i++){
        scanf("%lld %lld", &l, &r);
        ep.pb(l);
        ep.pb(l+r);
    }
    sort(all(ep));
    vec.pb(1);
    for(i64 i = 0; i < ep.size(); i++){
        if(ep[i] == ep[i+1]){
            i++;
            continue;
        }
        vec.pb(ep[i]);
    }
    vec.pb(n + 1);
    while (q--){
        i64 ask;
        scanf("%lld", &ask);
        i64 idx = upper_bound(all(vec), ask) - vec.begin();
        printf("%lld\n", vec[idx] - vec[idx - 1]);
    }
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
10 3 2
2 4
4 5
3 7
7 
5
*/