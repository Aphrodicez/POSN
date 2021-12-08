/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Binary Search + Greedy
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

const int MaxN = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int a[MaxN], last[MaxN], cost[MaxN];

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    a[n + 1] = 0;
    for(int i = 1; i <= k; i++) {
        scanf("%d", &cost[i]);
    }
    int lb = 1, rb = n + 1;
    while(lb < rb) {
        memset(last, 0, sizeof (last));
        int mid = lb + (rb - lb) / 2;
        for(int i = 1; i <= mid; i++) {
            last[a[i]] = i;
        }
        int cnt = 0;
        int sum = 0;
        for(int i = 1; i <= mid; i++) {
            if(a[i] && last[a[i]] == i) {
                if(sum - cost[a[i]] < 0)
                    break;
                sum -= cost[a[i]];
                cnt++;
                continue;
            }
            sum++;
        }
        if(cnt == k)
            rb = mid;
        else
            lb = mid + 1;
    }
    printf("%d\n", lb > n ? -1 : lb);
}

int main() {
    int q = 1;
    scanf("%d", &q);
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
2
7 2
0 1 0 2 1 0 2
2 1
5 1
1 1 1 1 1
5
*/