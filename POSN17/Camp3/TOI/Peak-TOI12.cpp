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

const int MaxN = 5e6 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int a[MaxN];
int ans[MaxN];

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i - 1] < a[i] && a[i] > a[i + 1]) {
            ans[++cnt] = a[i];
        }
    }
    if(!cnt) {
        printf("-1\n");
        return ;
    }
    sort(ans + 1, ans + 1 + cnt, greater <int>());
    int m = 0;
    int last = -1;
    for(int i = 1; i <= cnt; i++) {
        if(ans[i] == last)
            continue;
        ans[++m] = ans[i];
        last = ans[i];
    }
    int st = 1, tmp = 1;
    if(m < k)
        st = m, tmp = -1;
    k = min(m, k);
    last = -1;
    for(int i = st; k; i += tmp) {
        if(ans[i] == last)
            continue;
        printf("%d\n", ans[i]);
        last = ans[i];
        k--;
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
10
2
40
10
90
5
45
50
65
90
35
45

10
3
45
20
20
5
45
50
65
90
35
45

7
3
4
6
6
6
8
9
9
*/