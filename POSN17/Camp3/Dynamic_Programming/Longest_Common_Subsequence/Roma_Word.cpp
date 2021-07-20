/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Longest Common Subsequence
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

struct GRAPH {
    
};

const int N = 2e3 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

char a[N], b[N];

int dp[N][N];

int path[N][N];

void solve() {
    cin >> (a + 1);
    cin >> (b + 1);
    int lena = strlen(a + 1);
    int lenb = strlen(b + 1);
    int mx = 0;
    int eni, enj;
    for(int i = 1; i <= lena; i++) {
        for(int j = 1; j <= lenb; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                path[i][j] = 3;
                continue;
            }
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            path[i][j] = 1;
            if(dp[i - 1][j] < dp[i][j - 1])
                path[i][j] = 2;
        }
    }
    mx = dp[lena][lenb];
    cout << mx << "\n";
    if(!mx) {
        cout << "No Roma word" << "\n";
        return ;
    }
    stack <char> ans;
    int i = lena, j = lenb;
    while(i > 0 && j > 0) {
        if(path[i][j] == 1) {
            i--;
            continue;
        }
        if(path[i][j] == 2) {
            j--;
            continue;
        }
        ans.push(a[i]);
        i--, j--;
        mx--;
    }
    while(!ans.empty()) {
        cout << ans.top();
        ans.pop();
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
abcbdab
bdcaba
*/