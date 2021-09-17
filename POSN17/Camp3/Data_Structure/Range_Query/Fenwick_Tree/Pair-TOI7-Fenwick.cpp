/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Fenwick Tree [Inversion Count]
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

struct TREE {
    long long val, cnt;
};

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

bool cmpb(const pair <long long, long long> &a, const pair <long long, long long> &b) {
    return a.second < b.second;
}

int n;

TREE tree[2 * MaxN];
pair <long long, long long> arr[MaxN];
long long sorted[MaxN];

unordered_map <long long, int> mapp;

void upd(int idx, long long val, long long cnt) {
    while(idx <= 2 * n) {
        tree[idx].val += val;
        tree[idx].cnt += cnt;
        idx += (idx & -idx);
    }
}

TREE query(int idx) {
    TREE sum = {0, 0};
    while(idx > 0) {
        sum.val += tree[idx].val;
        sum.cnt += tree[idx].cnt;
        idx -= (idx & -idx);
    }
    return sum;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
        sorted[i] = arr[i].first;
    }
    sort(sorted + 1, sorted + n + 1);
    sort(arr + 1, arr + n + 1, cmpb);
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(sorted[i] > sorted[i - 1]) {
            mapp[sorted[i]] = ++cnt;
        }
    }
    long long ans = 0;
    vector <long long> tmp;
    for(int i = n; i >= 1; i--) {
        TREE sum = query(mapp[arr[i].first] - 1);
        ans += (arr[i].first * sum.cnt) + sum.val;
        tmp.push_back(arr[i].first);
        if(arr[i].second == arr[i + 1].second)
            continue;
        for(int x : tmp) {
            upd(mapp[x], x, 1);
        }
        tmp.clear();
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
6
2 1 7 6 9 3 18 4 3 2 5 5

4
1 4 3 2 2 3 7 1
*/