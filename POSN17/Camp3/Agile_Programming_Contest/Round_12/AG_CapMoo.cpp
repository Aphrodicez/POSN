/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Factorization
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

const int MaxN = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

string s;
int cnt[30];

vector <int> factor;

void solve() {
    factor.clear();
    cin >> s;
    int n = s.size();
    int sq = sqrt(n);
    factor.emplace_back(1);
    for(int i = 2; i <= sq; i++) {
        if(n % i)
            continue;
        factor.emplace_back(i);
        if(i * i == n)
            continue;
        factor.emplace_back(n / i);
    }
    int ans = 1e9;
    for(int sz : factor) {
        int sum = 0;
        for(int i = 0; i < sz; i++) {
            memset(cnt, 0, sizeof cnt);
            int mx = 0;
            for(int j = i; j < n; j += sz) {
                cnt[s[j] - 'a']++;
                mx = max(mx, cnt[s[j] - 'a']);
            }
            sum += (n / sz) - mx;
        }
        ans = min(ans, sum);
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
peattpeaat
nononioo
*/