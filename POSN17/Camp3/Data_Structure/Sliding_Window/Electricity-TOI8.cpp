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

deque <DEQUE> deq;

void solve() {
    int n, k;
    cin >> n >> k;
    int val;
    cin >> val;
    deq.push_back({1, val});
    for(int i = 2; i <= n; i++) {
        cin >> val;
        while(!deq.empty() && deq.front().idx < i - k)
            deq.pop_front();
        while(!deq.empty() && deq.back().val >= deq.front().val + val)
            deq.pop_back();
        deq.push_back({i, deq.front().val + val});
    }
    cout << deq.back().val << "\n";
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
7 
3 
1 4 2 6 2 4 2

10
4
2 1 4 3 2 1 5 1 2 3
*/