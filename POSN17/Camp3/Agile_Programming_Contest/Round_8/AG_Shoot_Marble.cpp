/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Greedy Algorithm + Math
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

int bit[30];

void solve() {
    int n;
    cin >> n;
    long long val;
    for(int i = 1; i <= n; i++) {
        cin >> val;
        int cnt = 0;
        while(val > 0) {
            bit[cnt++] += val & 1;
            val >>= 1;
        }
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        long long sum = 0;
        for(int j = 0; j <= 20; j++) {
            if(!bit[j])
                continue;
            sum += (1 << j);
            bit[j]--;
        }
        ans += sum * sum;
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    int q = 1;
    cin >> q;
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
2
3
2 4 8
1
4
*/