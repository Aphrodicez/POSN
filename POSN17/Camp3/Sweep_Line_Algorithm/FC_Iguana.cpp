/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Sweep Line Algorithm
    Status	: Accepted
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

struct GRAPH {
    
};

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

unordered_map <char, int> color;
map <int, long long> mp;

void solve() {
    color['R'] = 0;
    color['G'] = 1;
    color['B'] = 2;
    int n, m;
    cin >> n >> m;
    int l, r;
    for(int i = 1; i <= m; i++) {
        cin >> l >> r;
        mp[l]++;
        mp[r + 1]--; 
    }
    mp[1] += 0;
    mp[n + 1] += 0;
    char c;
    cin >> c;
    int target = color[c];
    long long last = 1;
    long long sum = 0;
    long long ans = 0;
    for(auto x : mp) {
        ans += ((target - sum + 3) % 3) * (x.first - last);
        x.second = (x.second % 3) + 3;
        sum = (sum + x.second) % 3;
        last = x.first;
    }
    cout << ans << "\n";
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
3 2
1 2
2 3
R
*/