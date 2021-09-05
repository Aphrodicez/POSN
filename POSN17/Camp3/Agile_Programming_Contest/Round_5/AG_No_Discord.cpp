/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Ad - Hoc] + Math [Inclusion-Exclusion + Prime Factorization] + Quicksum 1D
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

const int MxA = 5e3 + 10;
const int MxB = 5e3 + 10;
const int A = 5e3;
const int B = 5e3;
const int MOD = 1e9 + 7;

bool visited[MxB];
vector <pair <long long, bool>> prime_factor[MxB];
long long dp[MxA][MxB];
long long qs[MxA][MxB];

void power_factorization() {
    for(int i = 2; i <= B; i++) {
        if(visited[i])
            continue;
        visited[i] = true;
        for(int j = i; j <= B; j += i) {
            visited[j] = true;
            for(pair <long long, bool> x : prime_factor[j]) {
                prime_factor[j].push_back(make_pair(x.first * i, !x.second));
            }
            prime_factor[j].push_back(make_pair(i, true));
        }
    }
}

long long in_exclusion(int a, int b) {
    long long sum = 0;
    for(auto x : prime_factor[b]) {
        if(x.second)
            sum += dp[a][b / x.first];
        else
            sum -= dp[a][b / x.first];
        sum = (sum + MOD) % MOD;
    }
    return sum;
}

void TESTCASE() {
    int a, b;
    cin >> a >> b;
    cout << qs[a][b];
}

void solve() {
    power_factorization();
    dp[0][0] = 1;
    for(int i = 1; i <= A; i++) {
        for(int j = 1; j <= B; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % MOD;
            qs[i][j] = (qs[i][j - 1] + in_exclusion(i, j)) % MOD;
        }
    }
    int q = 1;
    cin >> q;
    while(q--) {
        TESTCASE();
        cout << "\n";
    }
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
3
2 6
2 12
3 3
*/