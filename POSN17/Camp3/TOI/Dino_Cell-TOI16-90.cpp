/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Inclusion Exclusion
    Status	: Rejected [90]
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

const int MaxN = 1e6 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int a[MaxN];
vector <int> prime_factor;
vector <pair <int, int>> factor;

void solve() {
    int z, k, n;
    scanf("%d %d %d", &z, &k, &n);
    for(int i = 2; i <= 10000000 && k > 1; i++) {
        if(k % i == 0)
            prime_factor.emplace_back(i);
        while(k % i == 0) {
            k /= i;
        }
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int mask = 1; mask < (1 << prime_factor.size()); mask++) {
        int sum = 1;
        int sign = -1;
        for(int j = 0; j < prime_factor.size(); j++) {
            if(mask & (1 << j)) {
                sum *= prime_factor[j];
                sign *= -1;
            }
        }
        factor.emplace_back(make_pair(sum, sign));
    }
    sort(factor.begin(), factor.end());
    // 0 = Plus 1 = Minus
    vector <int> ans = {0, 0};
    a[0] = 1;
    int mnplus = 0;
    int mnminus = 0;
    for(int i = 1; i <= n; i++) {
        int tmp = 0;
        int plus = 0;
        for(int j = 0; j < factor.size() && factor[j].first <= a[i]; j++) {
            tmp |= (a[i] % factor[j].first == 0);
            plus += (a[i] / factor[j].first) * factor[j].second;
        }
        int minus = a[i] - plus;
        if(i > 1) {
            ans[0] = max(ans[0], plus - minus - mnplus);
            ans[1] = max(ans[1], minus - plus - mnminus);
        }
        plus -= tmp;
        minus = (a[i] - 1) - plus;
        if(i == 1) {
            mnplus = plus - minus;
            mnminus = minus - plus;
            continue;
        }
        mnplus = min(mnplus, plus - minus);
        mnminus = min(mnminus, minus - plus);
    }
    printf("%d\n", max(ans[0], ans[1]));
}

int main() {
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
10 6 3
5 7 10

11 6 5
1 2 7 10 11

13 7 4
2 7 8 12

15 24 5
2 5 12 13 14
*/