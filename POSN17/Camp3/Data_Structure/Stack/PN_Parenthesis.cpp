/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: 
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

stack <pair <char, int>> st;

int dp[N];

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mx = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == ')') {
            int lvl = 0;
            while(st.top().first == ')') {
                lvl = max(lvl, st.top().second);
                st.pop();
            }
            st.pop();
            st.push(make_pair(')', lvl + 1));
            dp[lvl + 1]++;
            mx = max(mx, lvl + 1);
            cnt++;
        }
        else
            st.push(make_pair('(', 0));
    }
    cout << cnt << "\n";
    cout << mx << "\n";
    for(int i = 1; i <= mx; i++) {
        cout << dp[i] << " ";
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
16
((())(()((()))))
*/