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

const int R = 2e3 + 10;
const int C = 2e3 + 10;

int di[] = {1, -1, 0, 0, -1, -1, 1, 1}, dj[] = {0, 0, 1, -1, -1, 1, -1, 1};

queue <A> qu;

string a[R];

void solve(){
    int r, c, ans = 0;
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        cin >> a[i];
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(a[i][j] == '1'){
                ans++;
                a[i][j] = '0';
                qu.push({i, j});
                while(!qu.empty()){
                    A now = qu.front();
                    qu.pop();
                    for(int k = 0; k < 8; k++){
                        int ii = now.i + di[k], jj = now.j + dj[k];
                        if(ii < 0 || jj < 0 || ii > r - 1 || jj > c - 1)
                            continue;
                        if(a[ii][jj] != '1')
                            continue;
                        a[ii][jj] = '0';
                        qu.push({ii, jj});
                    }
                }
            }
        }
    }
    cout << ans << "\n";
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