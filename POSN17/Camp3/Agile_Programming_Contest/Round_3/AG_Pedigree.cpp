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

const int N = 2e1 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

i64 a[N];

i64 ans = 0;

void recur(i64 k, i64 w) {
    if(ans == -1)
        return ;
    if(k == 1) {
        ans += w;
        return ;
    }
    i64 nextw = 2 * w + 1 - a[k - 1];
    if(nextw < 2) {
        ans = -1;
        return ;
    }
    recur(k - 1, nextw / 2 + nextw % 2);
    if(ans == -1)
        return ;
    recur(k - 1, nextw / 2);
    if(ans == -1)
        return ;
}

void solve() {
    ans = 0;
    i64 k, w;
    cin >> k >> w;
    for(int i = 1; i < k; i++) {
        cin >> a[i];
    }
    recur(k, w);
    cout << ans << "\n";
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
2 1
1
3 10
10 10
3 10
9 9
*/