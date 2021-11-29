/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: String + Modulo
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

const int MaxN = 8e1 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

string ans;
string button[4][4];

void solve() {
    button[1][2] = "ABC", button[1][3] = "DEF";
    button[2][1] = "GHI", button[2][2] = "JKL", button[2][3] = "MNO";
    button[3][1] = "PQRS", button[3][2] = "TUV", button[3][3] = "WXYZ";
    int n;
    cin >> n;
    int st, cnt;
    cin >> st >> cnt;
    n--, st--, cnt--;
    int i = st / 3 + 1, j = st % 3 + 1;
    if(st)
        ans += button[i][j][cnt % (int)button[i][j].size()];
    for(int it = 1; it <= n; it++) {
        int dj, di, cnt;
        cin >> dj >> di >> cnt;
        cnt--;
        i += di;
        j += dj;
        i = max(i, 1), i = min(i, 3);
        j = max(j, 1), j = min(j, 3);
        if(i == 1 && j == 1) {
            while((int)ans.size() && cnt-- >= 0) {
                ans.pop_back();
            }
            continue;
        }
        ans += button[i][j][cnt % (int)button[i][j].size()];
    }
    cout << (int(ans.size()) ? ans : "null") << "\n";
}

int main() {
    setIO();
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
4
5 3
1 0 3
-1 1 3
1 -2 2

2
9 6
-2 -2 5

5
3 3
0 0 2
-2 0 1
2 1 3
0 1 2
*/