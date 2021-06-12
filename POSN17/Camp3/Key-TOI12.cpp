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
const int N = 1e3 + 10;
const int M = 2e5 + 10;

string a, b;

int dp[N][N];

bool question() {
    memset(dp, 0, sizeof dp);
    string s;
    cin >> s;
    dp[0][0] = 1;
    for(int i = 0; i <= a.size(); i++){
        for(int j = 0; j <= b.size(); j++) {
            if(!dp[i][j])
                continue;
            if(i < a.size() && s[i + j] == a[i])
                dp[i + 1][j] = 1;
            if(j < b.size() && s[i + j] == b[j])
                dp[i][j + 1] = 1;
        }
    }
    if(dp[a.size()][b.size()])
        return true;
    return false;
}

void solve() {
    i64 m;
    cin >> a >> b;
    cin >> m;
    while(m--) {
        if(question())
            cout << "Yes";
        else
            cout << "No";
        cout << '\n';
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
BAB 
AB 
4
BAABB 
BABAB
ABBAB 
BBABA
*/