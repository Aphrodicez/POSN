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

struct GRAPH {
    
};

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

map <int, int> mp;

vector <int> eventPoint;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;    
    int l, sz;
    while(m--) {
        cin >> l >> sz;
        mp[l]++;
        mp[l + sz]++;
    }
    eventPoint.push_back(1);
    for(auto x : mp) {
        if(x.second % 2)
            eventPoint.push_back(x.first);
    }
    eventPoint.push_back(n + 1);
    while(q--) {
        int idx;
        cin >> idx;
        int ub = upper_bound(eventPoint.begin(), eventPoint.end(), idx) - eventPoint.begin();
        cout << eventPoint[ub] - eventPoint[ub - 1] << "\n";
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
10 3 2
2 4
4 5
3 7
7
5
*/