/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Heap
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

const int MaxN = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct POINT {
    int idx, h, i;
    bool operator < (const POINT &o) const {
        if(idx != o.idx)
            return idx < o.idx;
        return h > o.h;
    }
};

vector <POINT> st;
vector<pair <int, int>> en; 
priority_queue <pair <int, int>> pq;

void solve() {
    int n;
    scanf("%d", &n);
    int l, h, r;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d %d %d", &l, &h, &r);
        if(l == r)
            continue;
        st.push_back({l, h, cnt++});
        en.emplace_back(make_pair(h, r));
    }
    sort(st.begin(), st.end());
    int last = 0, lastr = 0;
    for(auto x : st) {
        while(!pq.empty() && x.idx > pq.top().second) {
            while(!pq.empty() && lastr >= pq.top().second)
                pq.pop();
            if(pq.empty()) 
                break;
            int r = pq.top().second;
            lastr = r;
            while(!pq.empty() && lastr >= pq.top().second)
                pq.pop();
            int h = 0;
            if(!pq.empty())
                h = pq.top().first;
            printf("%d %d ", r, h);
            last = h;
            lastr = r;
        }
        pq.push(en[x.i]);
        if(en[x.i].first <= last)
            continue;
        last = en[x.i].first;
        lastr = x.idx;
        printf("%d %d ", x.idx, last);
    }
    while(!pq.empty()) {
        while(!pq.empty() && lastr >= pq.top().second)
            pq.pop();
        if(pq.empty())
            break;
        int r = pq.top().second;
        lastr = r;
        while(!pq.empty() && lastr >= pq.top().second)
            pq.pop();
        int h = 0;
        if(!pq.empty())
            h = pq.top().first;
        printf("%d %d ", r, h);
    }
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
2
1 11 5
2 6 7

8
1 11 5
2 6 7
12 7 16
14 3 25
19 18 22
3 13 9
23 13 29
24 4 28
*/