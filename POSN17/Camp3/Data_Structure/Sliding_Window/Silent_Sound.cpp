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

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

deque <DEQUE> maxDeq, minDeq;

void solve() {
    int n, m, c;
    cin >> n >> m >> c;
    int val;
    bool ch = false;
    for(int i = 1; i <= n; i++) {
        cin >> val;
        while(!maxDeq.empty() && maxDeq.front().idx < i - m + 1)
            maxDeq.pop_front();
        while(!maxDeq.empty() && maxDeq.back().val <= val)
            maxDeq.pop_back();
        while(!minDeq.empty() && minDeq.front().idx < i - m + 1)
            minDeq.pop_front();
        while(!minDeq.empty() && minDeq.back().val >= val)
            minDeq.pop_back();
        maxDeq.push_back({i, val});
        minDeq.push_back({i, val});
        if(i - m + 1 < 1)
            continue;
        if(maxDeq.front().val - minDeq.front().val <= c) {
            ch = true;
            cout << i - m + 1 << "\n";
        }
    }
    if(!ch) {
        cout << "NONE" << "\n";
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
7 2 0
0 1 1 2 3 2 2
*/