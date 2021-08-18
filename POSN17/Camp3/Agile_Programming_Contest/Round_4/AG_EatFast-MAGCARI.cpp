/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Binary Search
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

void TESTCASE() {
    
}

i64 a[N];

void solve() {
    int n, m;
    cin >> n >> m;
    int mxn = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i])
            mxn = i;
    }
    n = mxn;
    i64 lb = 0, rb = 1e18;
    while(lb < rb) {
        i64 midb = lb + (rb - lb) / 2;
        int cnt = m;
        i64 sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += a[i];
            while(sum >= midb - i) {
                sum -= midb - i;
                cnt--;
                if(cnt < 0)
                    break;
            }
        }
        if(cnt > 0 || (cnt == 0 && sum <= 0))
            rb = midb;
        else
            lb = midb + 1;
    }
    cout << lb << "\n";
}

int main() {
    setIO();
    int q = 1;
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
2 1
1 1

1
3 2
1 0 2

1
4 2
0 5 2 0
*/