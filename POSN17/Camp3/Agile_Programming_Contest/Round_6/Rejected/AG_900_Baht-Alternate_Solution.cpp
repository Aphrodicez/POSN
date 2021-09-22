/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming + Binary Search
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

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

long long mnDis[MaxN], mxDis[MaxN];

pair <long long, long long> arr[MaxN];

long long manhattanDistance(const pair <long long, long long> &a, const pair <long long, long long> &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve() {
    int n, q;
    cin >> n >> q;
    long long mnIdx = 1, mxIdx = 1;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr + 1, arr + n + 1);
    for(int i = 1; i <= n; i++) {
        pair <long long, long long> yzero, now;
        yzero = make_pair(arr[i].first, 0);
        if(manhattanDistance(yzero, arr[i]) > manhattanDistance(yzero, arr[mxIdx])) {
            mxIdx = i;
        }
        if(manhattanDistance(yzero, arr[i]) < manhattanDistance(yzero, arr[mnIdx])) {
            mnIdx = i;
        }
        mnDis[i] = mnIdx;
        mxDis[i] = mxIdx;
    }
    mxIdx = mnIdx = n;
    for(int i = n; i >= 1; i--) {
        pair <long long, long long> yzero, now;
        yzero = make_pair(arr[i].first, 0);
        if(manhattanDistance(yzero, arr[i]) > manhattanDistance(yzero, arr[mxIdx])) {
            mxIdx = i;
        }
        if(manhattanDistance(yzero, arr[i]) < manhattanDistance(yzero, arr[mnIdx])) {
            mnIdx = i;
        }
        if(manhattanDistance(yzero, arr[mxIdx]) > manhattanDistance(yzero, arr[mxDis[i]])) {
            mxDis[i] = mxIdx;
        }
        if(manhattanDistance(yzero, arr[mnIdx]) < manhattanDistance(yzero, arr[mnDis[i]])) {
            mnDis[i] = mnIdx;
        }
    }
    mnDis[0] = mnDis[1];
    mxDis[0] = mxDis[1];
    mnDis[n + 1] = mnDis[n];
    mxDis[n + 1] = mxDis[n];
    long long x;
    while(q--) {
        cin >> x;
        long long mn = 1e18, mx = 0;
        pair <long long, long long> yzero = make_pair(x, 0);
        int idx = upper_bound(arr + 1, arr + n + 1, yzero) - arr - 1;
        for(int i = idx; i <= idx + 1; i++) {
            if(i < 1 || i > n)
                continue;
            mn = min(mn, manhattanDistance(yzero, arr[mnDis[i]]));
            mx = max(mx, manhattanDistance(yzero, arr[mxDis[i]]));
        }
        cout << mn << " " << mx << "\n";
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
3 5
5 5
7 6
9 5
5
6
7
8
9
*/