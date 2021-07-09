/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Breadth First Search Kth State
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

const int N = 3e2 + 10;
const int M = 2e5 + 10;
const int K = 4;

struct GRAPH {
    int i, j, state;
};

int di[] = {-1, -1, 0, 1}, dj[] = {0, 1, 1, 1};

char laser[] = {'|', '/', '-', '\\'};

map <char, int> mp;

char a[K][N][N];

int dis[K][N][N];

queue <GRAPH> bfs;

void solve() {
    while(!bfs.empty())
        bfs.pop();
    memset(dis, -1, sizeof dis);
    int r, c;
    int sti, stj, eni, enj;
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> a[0][i][j];
            if(a[0][i][j] == 'S')
                sti = i, stj = j;
            if(a[0][i][j] == 'E')
                eni = i, enj = j;
            if(mp.find(a[0][i][j]) != mp.end()){
                int nowstate = mp[a[0][i][j]];
                for(int k = 1; k < 4; k++){
                    a[k][i][j] = laser[(k + nowstate) % 4];
                }
            }
            else{
                for(int k = 1; k < 4; k++){
                    a[k][i][j] = a[0][i][j];
                }
            }
        }
    }
    for(int k = 0; k < 4; k++){
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                if(mp.find(a[k][i][j]) == mp.end())
                    continue;
                int state = mp[a[k][i][j]];
                int ii, jj;
                ii = i, jj = j;
                while(1){
                    ii += di[state], jj += dj[state];
                    if(ii < 1 || jj < 1 || ii > r || jj > c)
                        break;
                    if(a[k][ii][jj] != '.' && a[k][ii][jj] != '*')
                        break;
                    a[k][ii][jj] = '*';
                }
                ii = i, jj = j;
                while(1){
                    ii += di[state] * -1, jj += dj[state] * -1;
                    if(ii < 1 || jj < 1 || ii > r || jj > c)
                        break;
                    if(a[k][ii][jj] != '.' && a[k][ii][jj] != '*')
                        break;
                    a[k][ii][jj] = '*';
                }
            }
        }
    }
    bfs.push({sti, stj});
    dis[0][sti][stj] = 0;
    while(!bfs.empty()){
        int i = bfs.front().i;
        int j = bfs.front().j;
        int state = bfs.front().state;
        bfs.pop();
        if(i == eni && j == enj){
            cout << state << "\n";
            return ;
        }
        int nextstate = state + 1;
        for(int k = 0; k < 4; k++){
            int ii = i + d4i[k];
            int jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[nextstate%4][ii][jj] != '.' && a[nextstate%4][ii][jj] != 'S' && a[nextstate%4][ii][jj] != 'E')
                continue;
            if(dis[nextstate%4][ii][jj] != -1)
                continue;
            dis[nextstate%4][ii][jj] = dis[state%4][i][j] + 1;
            bfs.push({ii, jj, nextstate});
        }
    }
    cout << -1 << "\n";
}

int main() {
    setIO();
    mp['|'] = 0;
    mp['/'] = 1;
    mp['-'] = 2;
    mp['\\'] = 3;
    int q;
    cin >> q;
    while(q--){
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
2 3
S-#
.E.
1 5
S..E/
5 5
S....
.....
.-|..
.|-..
....E
*/