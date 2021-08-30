    /*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math [Prime Factorization + Cauchy Schwarz Inequality] + Binary Search + Observe
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

const int N = 6e4 + 10;
const int M = 2e5 + 10;

void TESTCASE() {

}

int a[N], b[N];
vector <int> row[N], col[N];

int Prime_Factorization(int n) {
    int ans = 1;
    for(int i = 2; n > 1; i++) {
        int deg = 0;
        while(n > 1 && n % i == 0) {
            n /= i;
            deg = (deg + 1) % 2;
        }
        if(deg)
            ans *= i;
    }
    return ans;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = Prime_Factorization(a[i]);
        row[a[i]].push_back(i);
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        b[i] = Prime_Factorization(b[i]);
        col[b[i]].push_back(i);
    }
    while(q--) {
        long long r1, c1, r2, c2;
        long long ans = 0;
        cin >> r1 >> c1 >> r2 >> c2;
        if(r2 - r1 <= c2 - c1) {
            for(int i = r1; i <= r2; i++) {
                int lb = lower_bound(col[a[i]].begin(), col[a[i]].end(), c1) - col[a[i]].begin();
                int ub = upper_bound(col[a[i]].begin(), col[a[i]].end(), c2) - col[a[i]].begin();
                ans += ub - lb;
            }
        }
        else {
            for(int j = c1; j <= c2; j++) {
                int lb = lower_bound(row[b[j]].begin(), row[b[j]].end(), r1) - row[b[j]].begin();
                int ub = upper_bound(row[b[j]].begin(), row[b[j]].end(), r2) - row[b[j]].begin();
                ans += ub - lb;
            }
        }
        cout << ans << "\n";
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
8 8 10
5 4 1 2 8 9 3 7
2 1 4 3 8 6 5 2
0 1 1 3
0 4 3 4
0 7 0 7
1 6 1 7
2 6 4 7
6 6 7 7
7 0 7 4
4 2 5 4
4 0 5 0
2 0 3 2
*/
