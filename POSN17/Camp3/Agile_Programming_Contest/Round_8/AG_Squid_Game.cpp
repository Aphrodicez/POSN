/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Stack + Math
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

struct STONE {
    int idx, sz;
    double t;
};

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

deque <STONE> deq;
int sz[MaxN];

void solve() {
    int n;
    double m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> sz[i];
    }
    double v;
    for(int i = 1; i <= n; i++) {
        cin >> v;
        double t = double(i) + m / v;
        while(!deq.empty() && t < deq.back().t) {
            if(sz[i] <= deq.back().sz) {
                t = deq.back().t;
                break;
            }
            deq.pop_back();
        }
        deq.push_back({i, sz[i], t});
    }
    cout << deq.size() << "\n";
    while (!deq.empty()) {
        cout << deq.front().idx << " ";
        deq.pop_front();
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
5 10
2 10 6 4 5
3 5 1 2 2

6 50
2 10 6 4 5 20
3 5 1 2 2 10

3 15
5 2 7
3 5 5
*/