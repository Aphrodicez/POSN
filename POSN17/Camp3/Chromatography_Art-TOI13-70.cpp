/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Sweep Line Algorithm + Binary Search
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

const int MaxN = 1e3 + 10;
const int MaxM = 1e6 + 10;

void TESTCASE() {
    
}

vector <POINT> eventPoint;

vector <pair <long long, long long>> dp, tmp;

void solve() {
    long long n, target, ans = 0;
    cin >> n >> target;
    long long l, h, sz, val, r;
    for(long long i = 1; i <= n; i++) {
        cin >> l >> h >> sz >> val;
        r = l + sz - 1;
        eventPoint.push_back({l, val, h});
        eventPoint.push_back({r + 1, -val, h});
    }
    sort(eventPoint.begin(), eventPoint.end());
    dp.push_back(make_pair(1, 0));
    for(long long i = 0; i < (long long)eventPoint.size() - 1; i++) {
        l = 0, r = dp.size();
        bool ch = false;
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if(dp[mid].first == eventPoint[i].h + 1) {
                dp[mid].second -= eventPoint[i].val;
                ch = true;
                break;
            }
            else if(dp[mid].first < eventPoint[i].h + 1) {
                l = mid + 1;
            }
            else
                r = mid;
        }
        if(!ch) {
            tmp.push_back({eventPoint[i].h + 1, -eventPoint[i].val});
        }
        dp[0].second += eventPoint[i].val;
        if(eventPoint[i].idx == eventPoint[i + 1].idx)
            continue;
        for(auto x : tmp) {
            dp.push_back(x);
        }
        sort(dp.begin(), dp.end());
        long long sum = 0;
        for(int it = 0; it < (long long)dp.size() - 1; it++) {
            sum += dp[it].second;
            if(sum == target) {
                ans += (dp[it + 1].first - dp[it].first) * (eventPoint[i + 1].idx - eventPoint[i].idx);
            }
        }
        tmp.clear();
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