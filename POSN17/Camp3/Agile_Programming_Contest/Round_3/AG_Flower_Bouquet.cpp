/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Observation + Brute Force + Binary Search
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

const int N = 3e4 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int n;

int a[N];

int ans[N];

int group[N];

void grouping(int sz) {
    memset(group, 0, sizeof group);
    int groupIdx = 1;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(group[a[i]] != groupIdx) {
            if(cnt == sz) {
                groupIdx++;
                cnt = 0;
            }
            cnt++;
        }
        group[a[i]] = groupIdx;
    }
    ans[sz] = groupIdx;
}

void BinarySearchGroup(int sz) {
    int l = sz, r = n;
    while(l < r) {
        int mid = l + (r - l + 1) / 2;
        if(!ans[mid])
            grouping(mid);
        if(ans[mid] == ans[sz])
            l = mid;
        else
            r = mid - 1;
    }
    for(int i = sz; i <= l; i++) {
        ans[i] = ans[sz];
    }
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int sqn = sqrt(n);
    for(int sz = 1; sz <= n; sz++) {
        if(!ans[sz]) {
            grouping(sz);
            if(sz > sqn)
                BinarySearchGroup(sz);
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    setIO();
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
6
4 6 1 6 6 6
*/