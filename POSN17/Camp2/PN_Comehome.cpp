/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Disjoint Set Union
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

const int N = 3e5 + 10;
const int M = 3e5 + 10;

int p[N], mark[N];

int fr(int u){
    if(p[u] == u)
        return u;
    return p[u] = fr(p[u]);
}

void solve() {
    int m, n, u, v;
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; i++)
        p[i] = i;
    for(int i = 1; i <= m; i++){
        scanf("%d %d", &u, &v);
        int ru = fr(u);
        int rv = fr(v);
        if(!mark[u]){
            mark[u] = 1;
            p[u] = rv;
            printf("Yes\n");
            continue;
        }
        if(!mark[v]){
            mark[v] = 1;
            p[v] = ru;
            printf("Yes\n");
            continue;
        }
        if(!mark[ru]){
            mark[ru] = 1;
            p[ru] = rv;
            printf("Yes\n");
            continue;
        }
        if(!mark[rv]){
            mark[rv] = 1;
            p[rv] = ru;
            printf("Yes\n");
            continue;
        }
        printf("No\n");
    }
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
6 4
1 2
1 3
1 2
1 2
1 3
2 4
*/