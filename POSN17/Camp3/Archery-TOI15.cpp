/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Quicksum + Math
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

struct BOX {
    i64 h, hole;
    bool operator < (const BOX & o) const {
        return hole < o.hole;
    }
};

const int N = 5e5 + 10;
const int M = 2e5 + 10;

BOX a[N];

i64 qsNotBelow[N], qsBelow[N], hole[N];

void solve() {
    i64 n, MinH = 1e9 + 10;
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i].h);
        MinH = min(MinH, a[i].h);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i].hole);
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        qsNotBelow[i] = qsNotBelow[i - 1] + a[i].hole;
        qsBelow[i] = qsBelow[i - 1] + a[i].h + a[i].hole;
    }
    i64 ans, mn = qsBelow[n], cntBelow = 0, height, sum;
    for(int i = 1; i <= n; i++) {
        if(a[i].hole == a[i - 1].hole)
            continue;
        cntBelow = i - 1;
        height = a[i].hole;
        if(height > MinH)
            break;
        sum = (qsNotBelow[n] - qsNotBelow[cntBelow]) - (n - cntBelow) * height;
        sum += qsBelow[cntBelow] - cntBelow * height;
        if(sum < mn) {
            mn = sum;
            ans = height;
        }
    }
    printf("%lld %lld\n", ans, mn);
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
3
4 6 5
3 2 4

3
5 8 6
2 4 1

5
7 9 6 8 5
4 5 1 3 5

5
9 4 5 6 8
4 4 5 1 3

6 
2 2 2 2 2 2
1 2 1 2 1 2
*/