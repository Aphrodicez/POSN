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

struct BOTTLE {
    int idx, h;
    bool operator < (const BOTTLE &o) const {
        return h < o.h;
    }
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int mark[N];

BOTTLE a[N];

void solve() {
    int n, m;
    cin >> n >> m;
    int h;
    for(int i = 0; i < n; i++) {
        cin >> h;
        a[i] = {i, h};
    }
    sort(a, a + n);
    int lastPos = n;
    for(int j = 1; j <= m; j++) {
        cin >> h;
        int cnt = 0;
        for(int i = lastPos - 1; i >= 0 && a[i].h > h; i--) {
            lastPos = i;
            if(mark[a[i].idx] && mark[a[i].idx] < j)
                continue;
            for(int k = -1; k <= 1; k++) {
                int ii = a[i].idx + k;
                if(ii < 0 || ii >= n)
                    continue;
                if(mark[ii])
                    continue;
                mark[ii] = j;
                cnt++;
            }
        }
        cout << cnt << "\n";
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
7 4
3
1
4
6
7
3
5
5
4
6
2
*/