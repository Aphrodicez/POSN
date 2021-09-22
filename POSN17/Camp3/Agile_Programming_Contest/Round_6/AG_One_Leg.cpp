/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: 
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

struct PAIR {
    int idx;
    long long val;
};

const int MaxN = 2e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

long long n;

long long a[MaxN], sorted[MaxN];

unordered_map <long long, long long> mp;

long long tree[MaxN], inversion[MaxN];

vector <long long> vec;

void upd(long long idx, long long val) {
    while(idx <= n) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

long long query (long long idx) {
    long long sum = 0;
    while(idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void solve() {
    memset(a, 0, sizeof a);
    memset(sorted, 0, sizeof sorted);
    memset(tree, 0, sizeof tree);
    memset(inversion, 0, sizeof inversion);
    mp.clear();
    vec.clear();
    long long k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sorted[i] = a[i];
    }
    sort(sorted + 1, sorted + n + 1);
    long long cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(sorted[i] > sorted[i - 1])
            mp[sorted[i]] = ++cnt;
    }
    for(int i = n; i >= 1; i--) {
        inversion[mp[a[i]]] = query(mp[a[i]] - 1);
        upd(mp[a[i]], 1);
    }
    int lidx = -1;
    for(int i = 1; i <= n; i++) {
        if(k > inversion[mp[sorted[i]]]) {
            k -= inversion[mp[sorted[i]]];
            continue;
        }
        lidx = sorted[i];
        break;
    }
    if(lidx == -1) {
        cout << -1 << "\n";
        return;
    }
    int i;
    for(i = 1; i <= n && a[i] != lidx; i++);
    int ridx;
    for(; i <= n; i++) {
        if(a[i] < lidx) {
            vec.push_back(a[i]);
        }
    }
    sort(vec.begin(), vec.end());
    cout << lidx << " " << vec[k - 1] << "\n";
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
1
6 8
4 6 3 2 1 5
*/