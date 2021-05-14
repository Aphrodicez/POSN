/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Longest Increasing Subsequence
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
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const int N = 1e5 + 10;
const int M = 2e5 + 10;

bool cmp(p(int, int) a, p(int, int) b){
    if(a.i != b.i)
        return a.i > b.i;
    return a.j < b.j;
}

p(int, int) a[N];

int lis[N];

void solve() {
    memset(lis, 0, sizeof lis);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &a[i].i, &a[i].j);
    }
    sort(a + 1, a + 1 + n, cmp);
    int len = 0;
    for(int i = 1; i <= n; i++){
        int ub = upper_bound(lis, lis + len, a[i].j) - lis;
        if(ub == len)
            len++;
        lis[ub] = a[i].j;
    }
    printf("%d\n", len);
}
int main() {
    int q;
    scanf("%d", &q);
    while(q--){
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
3
1 3
3 4
2 2
6
3 4
4 6
11 3
75 2
7 5
1 8
*/