/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Breadth First Search
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

const int MaxN = 5e1 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

char a[MaxN][MaxN];
int kingdomName[MaxN][MaxN];
int visitedBy[MaxN][MaxN];

int r, c;

queue <tuple <int, int, int>> qu;

void gen_kingdom(int sti, int stj, int name) {
    while(!qu.empty())
        qu.pop();
    kingdomName[sti][stj] = name;
    qu.push(make_tuple(sti, stj, name));
    while(!qu.empty()) {
        int i, j, name;
        tie(i, j, name) = qu.front();
        qu.pop();
        for(int k = 0; k < 4; k++) {
            int ii = i + d4i[k];
            int jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj] != 'X')
                continue;
            if(kingdomName[ii][jj])
                continue;
            kingdomName[ii][jj] = name;
            qu.push(make_tuple(ii, jj, name));
        }
    }
}

int from_ocean(int sti, int stj, int name) {
    while(!qu.empty())
        qu.pop();
    visitedBy[sti][stj] = name;
    qu.push(make_tuple(sti, stj, 0));
    while(!qu.empty()) {
        int i, j, w;
        tie(i, j, w) = qu.front();
        qu.pop();
        if(kingdomName[i][j] == name)
            return w;
        for(int k = 0; k < 4; k++) {
            int ii = i + d4i[k];
            int jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(visitedBy[ii][jj] == name)
                continue;
            if(kingdomName[ii][jj] == name)
                return w;
            visitedBy[ii][jj] = name;
            qu.push(make_tuple(ii, jj, w + 1));
        }
    }
}

int from_kingdom(int name) {
    while (!qu.empty())
        qu.pop();
    int dis[] = {0, 0, 0, 0};
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(kingdomName[i][j] == name) {
                qu.push(make_tuple(i, j, 0));
                visitedBy[i][j] = name;
            }
        }
    }
    while(!qu.empty()) {
        int i, j, w;
        tie(i, j, w) = qu.front();
        qu.pop();
        for(int k = 0; k < 4; k++) {
            int ii = i + d4i[k];
            int jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(visitedBy[ii][jj] == name)
                continue;
            if(kingdomName[ii][jj]) {
                if(dis[kingdomName[ii][jj]])
                    continue;
                dis[kingdomName[ii][jj]] = w;
            }
            visitedBy[ii][jj] = name;
            qu.push(make_tuple(ii, jj, w + 1));
        }
    }
    int sum = 0;
    for(int i = 1; i <= 3; i++) {
        if(i != name && !dis[i])
            return INF;
        sum += dis[i];
    }
    return sum;
}

void solve() {
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) {
        scanf(" %s", a[i] + 1);
    }
    int name = 0;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(a[i][j] == 'X' && !kingdomName[i][j]) {
                gen_kingdom(i, j, ++name);
            }
        }
    }
    int ans = 1e9;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            ans = min(ans, 1 + from_ocean(i, j, 1) + from_ocean(i, j, 2) + from_ocean(i, j, 3));
            memset(visitedBy, 0, sizeof (visitedBy));
        }
    }
    for(int i = 1; i <= 3; i++) {
        ans = min(ans, from_kingdom(i));
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
6 16
................
..XXXX....XXX...
...XXXX....XX...
.XXXX......XXX..
........XXXXX...
..XXX....XXX....
*/