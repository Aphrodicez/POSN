/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Brute Force
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 1e6 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

bitset <MaxN> mark;

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    int q = n;
    int i = -1;
    while(q--) {
        int k = m;
        while (k) {
            i = (i + 1) % n;
            if(mark[i])
                continue;
            k--;
        }
        mark[i] = true;
        printf("%d ", i + 1);
    }
}

int main() {
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
8 4

5 4
*/