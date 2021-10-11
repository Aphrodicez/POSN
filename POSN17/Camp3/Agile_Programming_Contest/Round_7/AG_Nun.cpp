/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Two Pointers
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

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

long long qs[MaxN];

int ans[MaxN];

void solve() {
    long long n, m, q;
    cin >> n >> m >> q;
    int j = 1;
    for(int i = 1; i <= n; i++) {
        cin >> qs[i];
        qs[i] += qs[i - 1];
        while(j <= i && qs[i] - qs[j - 1] > m)
            j++;
        while(j <= i && qs[i] - qs[j] == m)
            j++;
        if(qs[i] - qs[j - 1] == m)
            ans[i] = j;
        else
            ans[i] = ans[i - 1];
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << (ans[r] >= l ? "Yes" : "No") << "\n";
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
7 10 5
9 3 4 2 1 3 7
2 6
3 7
1 4
3 6
5 6
*/