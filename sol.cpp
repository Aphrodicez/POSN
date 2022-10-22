/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Longest Increasing Subsequence
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

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

vector <int> lis[N];

int dp[N];

void solve() {
    int n;
    cin >> n;
    int sz = 0;
    int num;
    for(int i = 1; i <= n; i++) {
        cin >> num;
        int idx = lower_bound(dp, dp + sz, num) - dp;
        if(idx == sz)
            sz++;
        dp[idx] = num;
        lis[idx].push_back(num);
    }
    cout << sz << "\n";
    int last = 1e9;
    stack <int> ans;
    for(int i = sz - 1; i >= 0; i--) {
        for(int j = 0; j < lis[i].size(); j++) {
            if(lis[i][j] < last) {
                last = lis[i][j];
                break;
            }
        }
        ans.push(last);
    }
    while(!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << "\n";
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
8
-7 10 9 2 3 8 8 1 
10
6 3 4 8 10 5 7 1 9 2 
*/