/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Kadane's Algorithm
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

const int MaxN = 25e2 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int a[MaxN];

void solve() {
    int n;
    scanf("%d", &n);
    int ans = 0, sum = 0;
    int st = n + 1, en = n + 1;
    int nextst = 1;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        if(sum > ans) {
            ans = sum;
            st = nextst;
            en = i;
        }
        if(sum < 0) {
            sum = 0;
            nextst = i + 1;
        }
    }
    if(st == n + 1) {
        printf("Empty sequence\n");
        return ;
    }
    for(int i = st; i <= en; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("%d\n", ans);
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
8
4 -6 3 -2 6 -4 -6 6

3
-2 -3 -1
*/