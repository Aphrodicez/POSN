/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Sweep Line Algorithm + Binary Search + Fenwick Tree
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

struct POINT {
    long long idx, val, h;
    bool operator < (const POINT &o) const {
        if(idx != o.idx)
            return idx < o.idx;
        return val < o.val;
    }
};

const int MaxN = 4e6 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

vector <POINT> eventPoint;

long long tree[MaxN];

void upd(long long idx, long long val) {
    long long rb = 4e6;
    while(idx <= rb) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

long long query(long long idx) {
    long long sum = 0;
    while(idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void solve() {
    long long n, target;
    cin >> n >> target;
    long long l, h, sz, color, r, mxh = 0;
    for(int i = 1; i <= n; i++) {
        cin >> l >> h >> sz >> color;
        mxh = max(mxh, h);
        r = l + sz - 1;
        eventPoint.push_back({l, color, h});
        eventPoint.push_back({r + 1, -color, h});
    }
    sort(eventPoint.begin(), eventPoint.end());
    long long ans = 0;
    for(int i = 0; i < (int)eventPoint.size() - 1; i++) {
        upd(1, eventPoint[i].val);
        upd(eventPoint[i].h + 1, -eventPoint[i].val);
        if(eventPoint[i].idx == eventPoint[i + 1].idx)
            continue;
        long long l = 1, r = mxh + 1;
        while(l < r) {
            long long mid = l + (r - l) / 2;
            if(query(mid) <= target)
                r = mid;
            else
                l = mid + 1;
        }
        long long lb = l;
        l = 1, r = mxh + 1;
        while(l < r) {
            long long mid = l + (r - l) / 2;
            if(query(mid) < target)
                r = mid;
            else
                l = mid + 1;
        }
        long long ub = l;
        long long w = eventPoint[i + 1].idx - eventPoint[i].idx;
        long long h = ub - lb;
        ans += w * h;
    }
    cout << ans << "\n";
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
3 3
1 1 4 1
2 2 2 2
3 3 1 3

2 2
3 2 2 2
1 2 2 2
*/