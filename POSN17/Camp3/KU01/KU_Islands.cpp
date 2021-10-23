/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Sorting + Math
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

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    long long sum = 0;
    vector <long long> water;
    for(int i = 1; i <= n; i++) {
        long long val;
        scanf("%lld", &val);
        if(val > 0) {
            if(sum > 0)
                water.push_back(sum);
            sum = 0;
            continue;
        }
        sum += 1 - val;
    }
    if(sum > 0)
        water.push_back(sum);
    sort(water.begin(), water.end());
    long long ans = 0;
    for(int i = 0; i < (int)water.size() - (k + 1); i++) {
        ans += water[i];
    }
    printf("%lld\n", ans);
}

int main() {
    setIO();
    int q = 1;
    scanf("%d", &q);
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
15 2
-5 -2 1 2 -2 -1 -1 4 3 -15 -12 10 -1 3 -7
15 1
-5 -2 1 2 -2 -1 -1 4 3 -15 -12 10 -1 3 -7
*/