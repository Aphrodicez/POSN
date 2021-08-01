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

const int N = 1e3 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int a[N];

void solve() {
    i64 n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    i64 l = 0, r = 1e9;
    while(l < r) {
        i64 mid = l + (r - l) / 2;
        i64 sum = 0;
        i64 dis;
        for(int i = 1; i <= n; i++) {
            dis = a[i + 1] - a[i] - 1;
            if(i < n) {
                if(dis < 0)
                    continue;
                i64 overlap;
                if(dis % 2) {
                    overlap = max(0ll, mid - (dis - 1) / 2);
                    sum -= (overlap) * (overlap);
                }
                else {
                    overlap = max(0ll, mid - dis / 2);
                    sum -= overlap * (overlap + 1);
                }
            }
            sum += (mid + 1) * (mid + 1);
            if(sum >= k)
                break;
        }
        if(sum >= k)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << "\n";
}

int main() {
    setIO();
    int q;
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
3
3 10
0 5 6
3 30
0 6 5
2 10
0 0
*/