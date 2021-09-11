/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Sliding Window
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

struct DEQUE {
    int idx, val;
};

const int MaxN = 1e6 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

int a[MaxN];

deque <DEQUE> MaxDeq, MinDeq;

int n;

long long range_Special(int lim) {
    while(!MaxDeq.empty())
        MaxDeq.pop_front();
    while(!MinDeq.empty())
        MinDeq.pop_front();
    int lb = 0;
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        while(!MaxDeq.empty() && MaxDeq.back().val <= a[i])
            MaxDeq.pop_back();
        while(!MinDeq.empty() && MinDeq.back().val >= a[i])
            MinDeq.pop_back();
        MaxDeq.push_back({i, a[i]});
        MinDeq.push_back({i, a[i]});
        while(!MaxDeq.empty() && !MinDeq.empty() && MaxDeq.front().val - MinDeq.front().val > lim) {
            if(MaxDeq.front().idx < MinDeq.front().idx) {
                lb = MaxDeq.front().idx;
                MaxDeq.pop_front();
            }
            else {
                lb = MinDeq.front().idx;
                MinDeq.pop_front();
            }
        }
        ans += i - lb;
    }
    return ans;
}

void solve() {
    int l, r;
    cin >> n >> l >> r;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << range_Special(r) - range_Special(l - 1) << "\n";
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
7 4 6
1
7
4
3
9
6
8
*/