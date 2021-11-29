/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Longest Increasing Subsequence
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

const int MaxN = 1e6 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

bool cmp(const pair <long long, long long> &a, const pair <long long, long long> &b) {
    if(a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

vector<pair <long long, long long>> vec;

long long lis[MaxN];

void solve() {
    int n;
    long long s0;
    scanf("%d %lld", &n, &s0);
    for(int i = 1; i <= n; i++) {
        long long s, t;
        scanf("%lld %lld", &s, &t);
        if(abs(s - s0) <= t)
            vec.emplace_back(make_pair(s - t, s + t));
    }
    sort(vec.begin(), vec.end(), cmp);
    int cnt = 0;
    for(auto x : vec) {
        int idx = upper_bound(lis, lis + cnt, x.second) - lis;
        if(idx == cnt)
            cnt++;
        lis[idx] = x.second;
    }
    printf("%d\n", cnt);
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
5 0
0 10
-5 25
5 44
6 49
13 57

5 -5
-6 37
-12 25
3 2
-11 45
-4 12
*/