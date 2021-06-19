/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Permutation + Branch and Bound + Binary Search + Quicksum
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

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct GRAPH {
    
};

const int N = 1e1 + 10;
const int M = 1e7 + 10;

i64 n, m, q;

i64 lift[N], a[N], t[N], group[N], qs[M];

bool check(int tc, int i, int l, int r) {
    i64 sum = qs[l - 1];
    i64 cnt = 0;
    while(l < r) {
        int nextl = upper_bound(qs + l, qs + r, sum + lift[i] - a[i]) - qs;
        if(l == nextl)
            return false;
        l = nextl;
        sum = qs[nextl - 1];
        cnt++;
        if(cnt > t[tc])
            return false;
    }
    return true;
}

bool solve(int tc) {
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> group[i];
    }
    group[n + 1] = m;
    do{
        bool ch = true;
        for(int i = 1; i <= n; i++) {
            ch = check(tc, i, group[i], group[i + 1] - 1);
            if(!ch)
                break;
        }
        if(ch)
            return ch;
    }while (next_permutation(a + 1, a + n + 1));
    return false;
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &lift[i]);
    }
    sort(lift + 1, lift + n + 1);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i = 1; i <= m; i++) {
        scanf("%lld", &qs[i]);
        qs[i] += qs[i - 1];
    }
    for(int i = 1; i <= q; i++) {
        scanf("%lld", &t[i]);
    }
    for(int i = 1; i <= q; i++) {
        printf(solve(i) ? "P" : "F");
        printf("\n");
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
2 10 3
230 300
56 65
160 120 35 80 42 87 72 45 55 63
2 2 1
1 4
1 3
1 6

3 8 1
150 100 200
45 60 55
80 45 50 62 48 40 68 55
2
1 3 5
*/