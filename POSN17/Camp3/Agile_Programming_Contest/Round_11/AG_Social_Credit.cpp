/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Disjoint Set Union
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

struct BOMB {
    int x, y, idx;
};

bool cmpx(const BOMB &a, const BOMB &b) {
    if(a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

bool cmpy(const BOMB &a, const BOMB &b) {
    if(a.y != b.y)
        return a.y < b.y;
    return a.x < b.x;
}

vector <BOMB> vec;
int p[MaxN];
bitset <MaxN> mark;

int find_root (int u) {
    if(p[u] == u)
        return u;
    return p[u] = find_root(p[u]);
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    int k, l;
    scanf("%d %d", &k, &l);
    iota(p + 1, p + 1 + k, 1);
    int x, y;
    for(int i = 1; i <= k; i++) {
        scanf("%d %d", &x, &y);
        vec.push_back({x, y, i});
    }
    sort(vec.begin(), vec.end(), cmpx);
    for(int i = 1; i < vec.size(); i++) {
        if(vec[i].x != vec[i - 1].x)
            continue;
        if(vec[i].y - vec[i - 1].y > l)
            continue;
        int ru = find_root(vec[i - 1].idx);
        int rv = find_root(vec[i].idx);
        p[ru] = rv;
    }
    sort(vec.begin(), vec.end(), cmpy);
    for(int i = 1; i < vec.size(); i++) {
        if(vec[i].y != vec[i - 1].y)
            continue;
        if(vec[i].x - vec[i - 1].x > l)
            continue;
        int ru = find_root(vec[i - 1].idx);
        int rv = find_root(vec[i].idx);
        p[ru] = rv;
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        mark = 0;
        int o;
        scanf("%d", &o);
        int ans = 0;
        int u;
        for(int i = 1; i <= o; i++) {
            scanf("%d", &u);
            int ru = find_root(u);
            if(mark[ru])
                continue;
            mark[ru] = true;
            ans++;
        }
        printf("%d\n", ans);
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
20 5
10 3
1 1
1 3
1 5
3 2
5 2
7 2
10 2
11 3
15 5
20 5
2
3 1 5 6
2 2 3

20 10
10 3
1 5
3 5
5 5
7 5
9 5
9 4
9 2
9 1
9 7
10 5
3
3 1 5 9
2 3 7
4 1 3 5 10
*/