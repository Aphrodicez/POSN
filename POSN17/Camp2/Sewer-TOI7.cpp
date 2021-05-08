/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Breadth First Search
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

struct A{
    int i, j;  
};

const int R = 1e2 + 10;
const int C = 1e2 + 10;

int dis[R][C];

vector <A> g[R][C];

queue <A> qu;

void solve(){
    int r, c;
    char tmp;
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            dis[i][j] = 2e9;
            cin >> tmp;
            if(tmp == 'R' || tmp == 'B'){
                g[i][j].push_back({i, j + 1});
                g[i][j + 1].push_back({i, j});
            }
            if(tmp == 'D' || tmp == 'B'){
                g[i][j].push_back({i + 1, j});
                g[i + 1][j].push_back({i, j});
            }
        }
    }
    qu.push({1, 1});
    dis[1][1] = 1;
    while(!qu.empty()){
        int i = qu.front().i;
        int j = qu.front().j;
        qu.pop();
        for(auto &x : g[i][j]){
            if(x.i < 1 || x.j < 1 || x.i > r || x.j > c)
                continue;
            if(dis[x.i][x.j] < dis[i][j] + 1)
                continue;
            if(dis[x.i][x.j] == dis[i][j] + 1){
                cout << dis[x.i][x.j] << "\n";
                cout << x.i << " " << x.j << "\n";
                exit(0);
            }
            dis[x.i][x.j] = dis[i][j] + 1;
            qu.push({x.i, x.j});
        }
    }
}

int main() {
    setIO();
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
4 4
B R D N
D R B D
R R R D
N N N N
*/