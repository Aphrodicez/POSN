/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Depth First Search + Greedy Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;

bitset <MaxN> visited;

int a[MaxN];

int dfs(int u) {
    visited[u] = true;
    if(visited[a[u]])
        return 1;
    return 1 + dfs(a[u]);
}

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        visited = 0;
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(visited[i])
                continue;
            int cnt = dfs(i);
            if(cnt > 3) {
                if(cnt & 1)
                    cnt = 3;
                else
                    cnt = 2;
            }
            ans = max(ans, cnt);
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
3
2
1 2
3
2 3 1
6
2 3 1 6 4 5
*/