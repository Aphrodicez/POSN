/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Fenwick Tree + Queue
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

const int MaxN = 3e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

char a[MaxN], s[MaxN];
queue <int> qu[30];

int n;

struct FENWICK_TREE {
    long long tree[MaxN];
    void update(int idx, long long val) {
        for(; idx <= n; idx += idx & -idx) {
            tree[idx] += val;
        }
    }
    long long query(int idx, long long sum = 0) {
        for(; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }
};

FENWICK_TREE fenwick;

void solve() {
    int opr;
    scanf("%d", &opr);
    scanf(" %s", a + 1);
    n = strlen(a + 1);
    for(int i = 1; i <= n; i++) {
        fenwick.update(i, 1);
        qu[a[i] - 'a'].push(i);
    }
    scanf(" %s", s + 1);
    int len = strlen(s + 1);
    long long ans = 0;
    for(int i = 1; i <= len; i++) {
        int idx = s[i] - 'a';
        if(qu[idx].empty()) {
            printf("-1\n");
            return;
        }
        ans += fenwick.query(qu[idx].front());
        if(opr) {
            fenwick.update(qu[idx].front(), -1);
        }
        qu[idx].pop();
    }
    printf("%lld\n", ans);
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
0
aabceddectfghaat
catbat

1
aabceddectfghaat
catbat
*/