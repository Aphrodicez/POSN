/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Sorting
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

struct PAIR {
    int x, y;
};

bool cmp1(const PAIR &a, const PAIR &b) {
    if(a.x != b.x)
        return a.x > b.x;
    return a.y < b.y;
}

bool cmp2(const PAIR &a, const PAIR &b) {
    if(a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

PAIR a[MaxN];
vector <PAIR> ans;

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    sort(a + 1, a + 1 + n, cmp1);
    int maxx = 0, maxy = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i].x >= maxx || a[i].y >= maxy)
            ans.push_back({a[i].x, a[i].y});
        maxx = max(maxx, a[i].x);
        maxy = max(maxy, a[i].y);
    }
    sort(ans.begin(), ans.end(), cmp2);
    for(auto x : ans) {
        printf("%d %d\n", x.x, x.y);
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
5 
9 1 
8 2 
7 3 
6 4 
5 5

7 
1 2 
2 4 
4 1 
7 3 
5 5 
6 6 
3 7
*/