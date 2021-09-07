/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [ Largest Square in Grid ] + Math
    Status	: Accepted
    Created	: 26 August 2021 [21:41]
*/

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define pc(x) putchar(x)
#define MP make_pair
#define dec(x) fixed << setprecision(x)
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct ANS {
    int i, j, sz;
    bool operator < (const ANS &o) const {
        if(i != o.i)
            return i < o.i;
        if(j != o.j)
            return j < o.j;
        return sz < o.sz;
    }
};

const int N = 1e2 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int dp[N][N];

bool b[N][N];

void solve() {
    int r, c;
    cin >> r >> c;
    int mxsz = 0;
    int ansi, ansj;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            char tmp;
            cin >> tmp;
            if(tmp == 'x') {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                b[i][j] = true; 
                if(dp[i][j] > mxsz) {
                    mxsz = dp[i][j];
                    ansi = i - dp[i][j] + 1;
                    ansj = j - dp[i][j] + 1;
                    }
                }
            }
        }
        for(int i = ansi; i <= ansi + mxsz - 1; i++) {
            for(int j = ansj; j <= ansj + mxsz - 1; j++) {
                b[i][j] = false;
            }
        }
        vector <ANS> ans;
        ans.push_back({ansi, ansj, mxsz});
        bool ch = true;
        
        int mini = N, minj = N;
        int maxi = 0, maxj = 0;
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                if(b[i][j]) {
                    if(ch) {
                        ansi = i, ansj = j;
                        ch = false;
                    }
                    mini = min(mini, i), minj = min(minj, j);
                    maxi = max(maxi, i), maxj = max(maxj, j);
                }
            }
        }
    int sz = (maxj - minj + 1 > maxi - mini + 1 ? maxj - minj + 1 : maxi - mini + 1);
    if(ch) {
        cout << ansi << " " << ansj << " " << 1 << "\n";
        cout << ansi << " " << ansj << " " << mxsz << "\n";
        return ;
    }
    if(maxi - sz + 1 < ansi && maxi - sz + 1 >= 1)
        ansi = maxi - sz + 1;
    if(maxj - sz + 1 < ansj && maxj - sz + 1 >= 1)
        ansj = maxj - sz + 1;
    ans.push_back({ansi, ansj, sz});
    sort(ans.begin(), ans.end());
    for(auto x : ans) {
        cout << x.i << " " << x.j << " " << x.sz << "\n";
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
3 3
xx.
xxx
...

4 6
xx....
xx.xxx
...xxx
...xxx

5 5
.....
xxx..
xxxx.
xxxx.
.xxx.
*/