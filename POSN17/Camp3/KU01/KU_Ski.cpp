/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Brute Force Algorithm
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

void solve() {
    int n, m, l;
    scanf("%d %d %d", &l, &m, &n);
    for(int i = 1; i <= n; i++) {
        int ans = 1;
        int now = 0;
        for(int j = 1; j <= m; j++) {
            int opr;
            scanf("%d", &opr);
            if(!opr) {
                now--;
            }
            else {
                now++;
            }
            if(now < -l || now > l)
                ans = 0;
        }
        printf("%d\n", ans);
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
3 6 4
0 0 1 0 1 1 
1 0 1 1 1 1
1 0 1 1 1 0
0 0 0 0 1 1
*/