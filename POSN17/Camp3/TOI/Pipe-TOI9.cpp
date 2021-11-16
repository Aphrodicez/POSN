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

const int MaxN = 3e2 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    int i, j, last;
};

int a[MaxN][MaxN];

int r, c;

queue <GRAPH> qu;

unordered_map <int, unordered_map<int, int>> mp;

void gen_map() {
    int id = 11;
    for(int k = 3; k <= 4; k++) {
        mp[id][k % 4] = (k + 1) % 4;
        mp[id][(k + 1) % 4] = k % 4;
        id++;
    }
    id = 14;
    for(int k = 1; k <= 2; k++) {
        mp[id][k % 4] = (k + 1) % 4;
        mp[id][(k + 1) % 4] = k % 4;
        id--;
    }
    id = 21;
    for(int k = 0; k <= 1; k++) {
        mp[id][k % 4] = (k + 2) % 4;
        mp[id][(k + 2) % 4] = k % 4;
        mp[31][k % 4] = (k + 2) % 4;
        mp[31][(k + 2) % 4] = k % 4;
        id++;
    }
}

vector <int> ans;

void bfs(int sti, int stj, int last) {
    while(!qu.empty())
        qu.pop();
    qu.push({sti, stj, last});
    int sum = 0;
    while(!qu.empty()) {
        int i = qu.front().i;
        int j = qu.front().j;
        int last = qu.front().last;
        qu.pop();
        sum += 1;
        int k = mp[a[i][j]][last];
        int ii = i + d4i[k];
        int jj = j + d4j[k];
        if(a[i][j] == 31) {
            a[i][j] = 22;
            if(last % 2)
                a[i][j]--;
        }
        else
            a[i][j] = 0;
        if(ii < 1 || jj < 1 || ii > r || jj > c)
            continue;
        if(!a[ii][jj])
            continue;
        qu.push({ii, jj, (k + 2) % 4});
    }
    ans.emplace_back(sum);
}

void solve() {
    gen_map();
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1; i <= r; i++) {
        if(a[i][1]) {
            for(auto x : mp[a[i][1]]) {
                if(x.first == 3)
                    bfs(i, 1, 3);
            }
        }
        if(a[i][c]) {
            for(auto x : mp[a[i][c]]) {
                if(x.first == 1)
                    bfs(i, c, 1);
            }
        }
    }
    for(int j = 1; j <= c; j++) {
        if(a[1][j]) {
            for(auto x : mp[a[1][j]]) {
                if(x.first == 0)
                    bfs(1, j, 0);
            }
        }
        if(a[r][j]) {
            for(auto x : mp[a[r][j]]) {
                if(x.first == 2)
                    bfs(r, j, 2);
            }
        }
    }    
    printf("%d\n", int(ans.size()));
    sort(ans.begin(), ans.end());
    for(int x : ans) {
        printf("%d ", x);
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
5 6
0 21 14 11 0 21
0 12 31 13 0 21
14 22 31 11 14 31
21 0 12 22 11 21
31 22 22 22 22 11

3 5
0 21 0 0 0
22 31 13 0 0
0 12 11 0 0

5 6
31 22 22 13 0 21
21 0 0 21 0 21
21 0 0 21 0 21
21 0 0 12 22 31
12 22 22 22 22 11

2 3
31 31 31
31 31 31
*/