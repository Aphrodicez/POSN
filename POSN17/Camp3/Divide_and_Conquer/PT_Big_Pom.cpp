/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Divide and Conquer + Binary Search
    Status	: Accepted
    Created	: 21 August 2021 [12:01]
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

i64 n, C, R, S;

vector <int> clockPos;

i64 ans = 0;

i64 divide(int l, int r) {
    i64 amtDestroy = upper_bound(clockPos.begin(), clockPos.end(), r) - lower_bound(clockPos.begin(), clockPos.end(), l);
    if(!amtDestroy)
        return R;
    i64 costDestroy = S * amtDestroy * (r - l + 1);
    if(l >= r)
        return costDestroy;
    int mid = l + (r - l) / 2;
    return min(costDestroy, divide(l, mid) + divide(mid + 1, r));
}

void solve() {
    clockPos.clear();
    cin >> n >> C >> R >> S;
    n = (1ll << n);
    int idx;
    for(int i = 1; i <= C; i++) {
        cin >> idx;
        clockPos.push_back(idx);
    }
    sort(clockPos.begin(), clockPos.end());
    cout << divide(1, n) << "\n";
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
3
2 2 1 2
1 3
3 2 1 2
1 7
2 1 10 1
1
*/