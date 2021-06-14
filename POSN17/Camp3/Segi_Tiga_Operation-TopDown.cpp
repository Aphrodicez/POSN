/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Matrix Chain Multiplication [Top Down]
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
    
};

const int N = 255 + 10;
const int M = 2e5 + 10;

int dp[3][N][N];

vector <pair <int, int>> vec[3];

string s;

int divide(int l, int r, int target) {
    if(dp[target][l][r] != -1)
        return dp[target][l][r];
    dp[target][l][r] = 0;
    if(l == r) {
        dp[s[l - 1] - '0'][l][r] = 1;
        return dp[target][l][r];
    }
    for(int mid = l; mid <= r - 1; mid++) {
        for(auto x: vec[target]) {
            if(divide(l, mid, x.first) && divide(mid + 1, r, x.second)) {
                return dp[target][l][r] = 1;
            }
        }
    }
    return dp[target][l][r];
}

void solve() {
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n >> s;
    divide(1, n, 0);
    cout << (dp[0][1][n] ? "yes" : "no") << '\n';
}

int main() {
    setIO();
    vec[0] = {{0, 2}};
    vec[1] = {{0, 1}, {1, 1}, {1, 2}, {2, 0}, {2, 2}};
    vec[2] = {{0, 0}, {1, 0}, {2, 1}};
    int q = 20;
    while(q--) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
4 0201 
5 10212 
6 002000 
5 01010 
5 02112 
5 11020 
5 10112 
5 02000 
5 12122 
5 12201 
5 02200 
5 01200 
5 10102 
5 10210 
5 12110 
5 12112 
5 20122 
5 01022 
2 00 
2 02
*/