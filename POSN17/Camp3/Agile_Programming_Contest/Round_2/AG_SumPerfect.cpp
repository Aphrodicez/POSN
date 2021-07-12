/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math
    Status	: Accepted
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

map <i64, int> mapp;

void solve() {
    mapp.clear();
    int n;
    cin >> n;
    i64 sum = 0;
    i64 num;
    i64 cnt = 0;
    for(int i = 1; i <= n; i++) {
        cin >> num;
        mapp[num]++;
    }
    i64 mx = 0;
    for(auto x : mapp) {
        if(x.second > 1) {
            mapp[x.first + 1] += x.second / 2;
            x.second %= 2;
        }
        mx = max(mx, x.first);
        if(x.second)
            cnt++;
    }
    cout << (mx + 1) - cnt << "\n";
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
3
5 3 3
4
3 5 4 2
4
0 0 0 0
*/