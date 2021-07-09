/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Breadth First Search
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
    int i, j;
};

const int N = 2e3 + 10;
const int M = 2e5 + 10;

int r, c;

char a[N][N];

queue <GRAPH> qu;

void bfs(int sti, int stj){
    while(!qu.empty())
        qu.pop();
    qu.push({sti, stj});
    while(!qu.empty()) {
        int i = qu.front().i;
        int j = qu.front().j;
        qu.pop();
        for(int k = 0; k < 8; k++) {
            int ii = i + d8i[k], jj = j + d8j[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj] != '1')
                continue;
            a[ii][jj] = '0';
            qu.push({ii, jj});
        }
    }
}

void solve() {
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(a[i][j] == '1'){
                a[i][j] = '0';
                bfs(i, j);
                ans++;
            }       
        }
    }
    cout << ans << '\n';
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
4 5 
10011 
00001 
01100 
10011

4 4 
0010 
1010 
0100 
1111
*/