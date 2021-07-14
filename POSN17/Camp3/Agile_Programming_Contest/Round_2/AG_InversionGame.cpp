/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Sweepline + Inversion Count [Fenwick Tree]
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

const int MOD = 1e9 + 7;

i64 tree[100003];

void upd(int idx, i64 val) {
    while(idx <= 100003) {
        tree[idx] += val;
        tree[idx] %= MOD;
        idx += (idx & -idx);
    }
}

int query(i64 idx) {
    i64 sum = 0;
    while(idx > 0) {
        sum += tree[idx];
        sum %= MOD;
        idx -= (idx & -idx);
    }
    return sum;
}

void solve() {
    memset(tree, 0, sizeof (tree));
    int n;
    cin >> n;
    int u, v;
    vector <int> swapIdx;
    vector <pair <int, int>> swapPair;
    for(int i = 1; i <= n; i++) {
        cin >> u >> v;
        if(u == v)
            continue;
        swapPair.push_back(make_pair(u, v));
        swapIdx.push_back(u);
        swapIdx.push_back(u + 1);
        swapIdx.push_back(v);
        swapIdx.push_back(v + 1);
    }
    sort(swapIdx.begin(), swapIdx.end());
    int idx = 1;
    vector <pair <int, i64>> realPair;
    vector <int> searchVec;
    unordered_map <int, int> mapp;
    int it = 1;
    for(int i = 0; i < swapIdx.size(); i++) {
        if(idx == swapIdx[i])
            continue;
        searchVec.push_back(idx);
        mapp[idx] = it++;
        realPair.push_back(make_pair(idx, swapIdx[i] - idx));
        idx = swapIdx[i];
    }
    for(auto x : swapPair) {
        int l = mapp[x.first] - 1;
        int r = mapp[x.second] - 1;
        swap(realPair[l], realPair[r]);
    }
    reverse(realPair.begin(), realPair.end());
    i64 ans = 0;
    for(auto x : realPair) {
        ans += (query(mapp[x.first]) % MOD) * (x.second % MOD);
        ans %= MOD;
        upd(mapp[x.first], x.second % MOD);
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    int q;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
1
2
5 9
6 5
*/