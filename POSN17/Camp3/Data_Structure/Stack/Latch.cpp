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
    i64 h, cnt; 
};

const int N = 1e3 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int a[N][N];

i64 h[N][N];

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if(a[i][j] == a[i - 1][j])
                h[i][j] = h[i - 1][j];
            h[i][j]++;
        }
    }
    stack <GRAPH> st;
    i64 ans = 0;
    for(int i = 1; i <= n; i++) {
        i64 sum = 0;
        for(int j = 1; j <= m; j++) {
            i64 cnt = 1;
            while(!st.empty() && st.top().h > h[i][j]) {
                cnt += st.top().cnt;
                sum -= st.top().h * st.top().cnt;
                st.pop();
            }
            st.push({h[i][j], cnt});
            sum += h[i][j] * cnt;
            ans += sum;
            if(a[i][j] != a[i][j + 1]) {
                while(!st.empty())
                    st.pop();
                sum = 0;
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
2 3
1 1 2
1 1 2
*/