/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Depth First Search
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

const int MaxN = 1e1 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct XYZ {
    long long x, y, z;
    int m, k, c;
    XYZ operator+ (const XYZ &o) const {
        return {o.x, o.y, o.z, m + o.m, k + o.k, c + o.c};
    }

};

long long dis(const XYZ &a, const XYZ &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
}

int n, m;
long long ans = 2e18;

bitset <MaxN> visited;
XYZ shop[MaxN];

void dfs(XYZ now, long long sum) {
    if(sum > ans) {
        return ;
    }
    if(now.m >= n && now.k >= n && now.c >= n) {
        ans = min(ans, sum);
        return ;
    }
    for(int i = 1; i <= m; i++) {
        if(visited[i])
            continue;
        visited[i] = true;
        dfs(now + shop[i], sum + dis(now, shop[i]));
        visited[i] = false;
    }
}

void solve() {
    scanf("%d", &n);
    XYZ st = {0, 0, 0, 0, 0, 0};
    scanf("%lld %lld %lld", &st.x, &st.y, &st.z);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) {
        scanf("%lld %lld %lld", &shop[i].x, &shop[i].y, &shop[i].z);
        scanf("%d %d %d", &shop[i].m, &shop[i].k, &shop[i].c);
    }
    dfs(st, 0);
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
1
0 0 0
2
10 0 0
2 5 7 
0 10 0
0 3 9

5
0 0 0
5
60 34 56 
0 5 7 
90 41 92 
1 7 8 
24 61 81 
6 8 8 
41 86 70 
5 6 7 
46 97 85 
9 2 4
*/