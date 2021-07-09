/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Disjoint Set Union + Math
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

struct TIME {
    int u, v;
    double Time;
    bool operator < (const TIME &o) const {
        return Time < o.Time;
    }
};

struct MERGE {
    int child, parent, w;
};

const int N = 7e2 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

double height[N * N], velocity[N * N];

int pa[N * N], cnt[N * N];

int find_root(int u) {
    if(pa[u] == u)
        return u;
    return pa[u] = find_root(pa[u]);
}

int n;

int id(int i, int j) {
    return (i - 1) * n + j; 
}

stack <MERGE> changeLog;

int ans = 1;

void revert() {
    while(!changeLog.empty()) {
        int child = changeLog.top().child;
        int parent = changeLog.top().parent;
        int w = changeLog.top().w;
        changeLog.pop();
        cnt[parent] -= w;
        pa[child] = child;
    }
}

void merge(int u, int v) {
    int ru = find_root(u);
    int rv = find_root(v);
    if(ru == rv)
        return;
    if(cnt[ru] >= cnt[rv]) {
        changeLog.push({rv, ru, cnt[rv]});
        cnt[ru] += cnt[rv];
        ans = max(ans, cnt[ru]);
        pa[rv] = ru;
    }
    else {
        changeLog.push({ru, rv, cnt[ru]});
        cnt[rv] += cnt[ru];
        ans = max(ans, cnt[rv]);
        pa[ru] = rv;
    }
}

vector <TIME> Time;

void compare(int u, int v) {
    if(velocity[u] != velocity[v]) {
        double t = (height[u] - height[v]) / (velocity[v] - velocity[u]);
        if(t < 0)
            return ;
        Time.push_back({u, v, t});
    }
    else if(height[u] == height[v]) {
        int ru = find_root(u);
        int rv = find_root(v);
        if(ru == rv)
            return;
        if(cnt[ru] >= cnt[rv]) {
            cnt[ru] += cnt[rv];
            ans = max(ans, cnt[ru]);
            pa[rv] = ru;
        }
        else {
            cnt[rv] += cnt[ru];
            ans = max(ans, cnt[rv]);
            pa[ru] = rv;
        }
    }
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int u = id(i, j);
            cin >> height[u];
            pa[u] = u;
            cnt[u] = 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int u = id(i, j);
            cin >> velocity[u];
            if(i > 1) {
                int v = id(i - 1, j);
                compare(u, v);
            }
            if(j > 1) {
                int v = id(i, j - 1);
                compare(u, v);
            }
        }
    }
    sort(Time.begin(), Time.end());
    Time.push_back({-1, -1, -1});
    for(int i = 0; i < Time.size() - 1; i++) {
        merge(Time[i].u, Time[i].v);
        if(Time[i].Time == Time[i + 1].Time)
            continue;
        revert();
    }
    cout << ans << "\n";
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
2
4 4
1 3
1 1
5 5
*/