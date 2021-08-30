/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Quicksum 1D] + Binary Search
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

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {

}

long long qsa[N], qsb[N];

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        cin >> qsa[i];
        qsa[i] += qsa[i - 1];
    }
    for(int i = 1; i <= m; i++) {
        cin >> qsb[i];
        qsb[i] += qsb[i - 1];
    }
    while(q--) {
        long long A, B, C, D, k;
        cin >> A >> B >> C >> D >> k;
        long long lb = 0, rb = 1e10;
        while(lb < rb) {
            long long midb = lb + (rb - lb) / 2;
            long long cnt = 0;
            cnt += upper_bound(qsa + A, qsa + C + 1, qsa[A - 1] + midb) - qsa - A;
            cnt += upper_bound(qsb + B, qsb + D + 1, qsb[B - 1] + midb) - qsb - B;
            if(cnt < k)
                lb = midb  + 1;
            else
                rb = midb;
        }
        cout << lb << "\n";
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
5 6 2
1 5 3 7 2
4 7 2 5 9 2
1 1 3 3 4
1 3 4 5 7
*/
