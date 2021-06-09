/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Breadth First Search + Sorting
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
    int u, di, dj;
};

struct BFS {
    int u, i, j;
};

const int N = 2e2 + 10;
const int M = 2e5 + 10;

vector <GRAPH> g[N*N];

int mark[N*N];

map <pair<int, int>, int> mp;

queue <BFS> bfs;

void solve() {
    int r, c;
    int u, v;
    char path;
    cin >> r >> c;
    for(int i = 1; i < r * c; i++){
        cin >> u >> path >> v;
        if(path == 'U'){
            g[u].push_back({v, 1, 0});
            g[v].push_back({u, -1, 0});
        }
        if(path == 'L'){
            g[u].push_back({v, 0, 1});
            g[v].push_back({u, 0, -1});
        }
    }
    bfs.push({0, 0, 0});
    while(!bfs.empty()){
        int u = bfs.front().u;
        int i = bfs.front().i;
        int j = bfs.front().j;
        bfs.pop();
        mark[u] = 1;
        mp[make_pair(i, j)] = u;
        for(auto x: g[u]){
            if(mark[x.u])
                continue;
            bfs.push({x.u, i + x.di, j + x.dj});
        }
    }
    int it = 1;
    for(auto x: mp) {
        cout << x.second << " ";        
        if(it % c == 0)
            cout << '\n';
        it++;
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
3 2 
1 U 5 
0 U 3 
4 L 2 
0 L 1 
5 U 2 

1 5 
4 L 3 
2 L 0 
1 L 2 
0 L 4 
*/