/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Binary Search
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

int a[MaxN], sorted[MaxN];

void solve() {
    int n, k, p;
    scanf("%d %d %d", &n, &k, &p);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sorted[i] = a[i];
    }    
    if(n == 1) {
        printf("%d\n", a[1]);
        return ;
    }
    sort(sorted + 1, sorted + 1 + n);
    int lb = 1, rb = n;
    while(lb < rb) {
        int mid = lb + (rb - lb) / 2;
        int last = -1e9;
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] <= sorted[mid])
                continue;
            if(i - p + 1 <= last)
                continue;
            cnt++;
            if(cnt > k)
                break;
            last = i;
        }
        if(cnt > k)
            lb = mid + 1;
        else
            rb = mid;
    }
    printf("%d\n", sorted[lb]);
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
10 2 2
51
42
54
31
12
57
11
51
85
36
*/