/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Breadth First Search + Brute Force
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

const int MaxN = 18;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int a[MaxN][MaxN];
bool visited[MaxN][MaxN];

queue <tuple <int, int>> qu;

unordered_set <int> dir;

int n;

int bfs(int sti, int stj) {
    dir.clear();
    visited[sti][stj] = true;
    qu.push(make_tuple(sti, stj));
    int cnt = 0;
    while(!qu.empty()) {
        int i, j;
        tie(i, j) = qu.front();
        qu.pop();
        cnt++;
        for(int k = 0; k < 4; k++) {
            int ii = i + d4i[k];
            int jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > n || jj > n)
                continue;
            if(!a[ii][jj])
                continue;
            if(visited[ii][jj])
                continue;
            if(a[ii][jj] != a[i][j])
                continue;
            visited[ii][jj] = true;
            qu.push(make_tuple(ii, jj));
            dir.insert(k);
        }
    }
    if(cnt == 3 && (int)dir.size() == 2)
        return 1;
    return 0;
}

void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!a[i][j])
                continue;
            if(visited[i][j])
                continue;
            ans += bfs(i, j);
        }
    }
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
3
1 1 0
1 2 2
3 2 2

4
2 2 9 0
2 3 9 9
1 3 3 2
1 1 2 2

5
3 3 6 6 0
3 5 5 6 8
2 2 5 8 8
2 1 4 4 7
1 1 4 7 7
*/