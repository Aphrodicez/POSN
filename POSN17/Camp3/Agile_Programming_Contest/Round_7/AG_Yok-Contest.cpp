/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Fenwick Tree + Sweep Line Algorithm
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

struct EVENT {
    int i, jl, jr, val;
    bool operator < (const EVENT &o) const {
        return i < o.i;
    }
};

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

vector <EVENT> eventPoint;
vector <EVENT> qvec;

int tree[MaxN];

int rb = 1e5;

void upd(int idx, int val) {
    while(idx <= rb) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int query(int idx) {
    int sum = 0;
    while(idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int ans[MaxN];

void solve() {
    int n, q, k;
    cin >> n >> q >> k;
    int a, b, c, d;
    for(int it = 1; it <= n; it++) {
        cin >> a >> b >> c >> d;
        a++, b++, c++, d++;
        eventPoint.push_back({a, b, d, 1});
        eventPoint.push_back({c + 1, b, d, -1});
    }
    sort(eventPoint.begin(), eventPoint.end());
    eventPoint.push_back({(int)1e9});
    int i, j;
    for(int it = 1; it <= q; it++) {
        cin >> i >> j;
        i++, j++;
        qvec.push_back({i, j, it});
    }
    sort(qvec.begin(), qvec.end());
    int cnt = 0;
    while(cnt < q && qvec[cnt].i < eventPoint[0].i)
        cnt++;
    for(int it = 0; it < (int)eventPoint.size() - 1; it++) {
        int jl = eventPoint[it].jl;
        int jr = eventPoint[it].jr;
        upd(jl, 1 * eventPoint[it].val);
        upd(jr + 1, -1 * eventPoint[it].val);
        if(eventPoint[it].i == eventPoint[it + 1].i)
            continue;
        while(cnt < q && qvec[cnt].i < eventPoint[it + 1].i) {
            ans[qvec[cnt].jr] = query(qvec[cnt].jl);
            cnt++;
        }
    }
    for(int i = 1; i <= q; i++) {
        cout << ans[i] << "\n";
    }
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
10 3 3
3 0 8 2
1 7 8 9
1 0 8 2
5 2 6 4
5 1 5 4
7 3 7 9
0 0 0 3
6 2 6 4
8 3 9 8
4 4 8 6
7 9
8 5
6 4
*/