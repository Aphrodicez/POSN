/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming + Binary Search + Math
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

long long prefixMax[MaxN], prefixMin[MaxN], suffixMax[MaxN], suffixMin[MaxN]; 

vector <pair <long long, long long>> points;

void solve() {
    int n, q;
    cin >> n >> q;
    long long x, y;
    for(int i = 1; i <= n; i++) {
        cin >> x >> y;
        points.emplace_back(make_pair(x, y));
    }
    sort(points.begin(), points.end());
    prefixMin[0] = suffixMin[n + 1] = 1e18;
    prefixMax[0] = suffixMax[n + 1] = -1e18;
    for(int i = 1; i <= n; i++) {
        prefixMin[i] = min(prefixMin[i - 1], points[i - 1].y - points[i - 1].x);
        prefixMax[i] = max(prefixMax[i - 1], points[i - 1].y - points[i - 1].x);
    }
    for(int i = n; i >= 1; i--) {
        suffixMin[i] = min(suffixMin[i + 1], points[i - 1].y + points[i - 1].x);
        suffixMax[i] = max(suffixMax[i + 1], points[i - 1].y + points[i - 1].x);
    } 
    while(q--) {
        cin >> x;
        int idx = upper_bound(points.begin(), points.end(), make_pair(x, 0ll)) - points.begin();
        long long mn = min(prefixMin[idx] + x, suffixMin[idx + 1] - x);
        long long mx = max(prefixMax[idx] + x, suffixMax[idx + 1] - x);
        cout << mn << " " << mx << "\n";
    }
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
3 5
5 5
7 6
9 5
5
6
7
8
9
*/