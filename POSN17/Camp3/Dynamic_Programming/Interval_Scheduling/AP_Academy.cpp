/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [ Interval Scheduling ]
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

struct PAIR {
    int st, en;
    bool operator < (const PAIR &o) const {
        if(en != o.en)
            return en < o.en;
        return st < o.st;
    }
};

const int N = 1e6 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

//vector <PAIR> eventPoint;

void solve() {
    int n;
    cin >> n;
    vector <int> st, en;
    int l, r;
    for(int i = 1; i <= n; i++) {
        cin >> l >> r;
        st.push_back(l);
        en.push_back(r);
    }
    sort(st.begin(), st.end());
    sort(en.begin(), en.end());
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        int rb = upper_bound(st.begin(), st.end(), r) - st.begin();
        int lb = upper_bound(en.begin(), en.end(), l - 1) - en.begin();
        cout << rb - lb << "\n";
    }
}

int main() {
    setIO();
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
4
1 4
3 5
4 8
7 10
4
4 4
1 10
5 8
1 3
*/  