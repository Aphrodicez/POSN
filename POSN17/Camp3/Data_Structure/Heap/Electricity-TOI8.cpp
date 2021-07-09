/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Heap
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

struct HEAP {
    int idx, val;
    bool operator < (const HEAP &o) const {
        if(val != o.val)
            return val > o.val;
        return idx > o.idx;
    }
};

const int N = 5e5 + 10;
const int M = 2e5 + 10;

int a[N];

priority_queue <HEAP> pq;

void solve() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    pq.push({1, a[1]});
    while(!pq.empty()) {
        int idx = pq.top().idx;
        int val = pq.top().val;
        pq.pop();
        while(!pq.empty() && pq.top().idx <= idx)
            pq.pop();
        for(int i = idx + 1; i <= idx + k; i++) {
            if(i == n){
                printf("%d\n", val + a[n]);
                return ;
            }
            pq.push({i, val + a[i]});
        }
    }
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
7 
3 
1 4 2 6 2 4 2

10 
4 
2 1 4 3 2 1 5 1 2 3
*/