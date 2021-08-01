/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: 
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

const int N = 3e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

double a[N], qs[N], qsmn[N];

void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    double lb = 0, rb = 1e6;
    while(rb - lb > 1e-6) {
        double mid = (lb + rb + 1e-6) / 2;
        bool ch = false;
        for(int i = 1; i <= n; i++) {
            qs[i] = qs[i - 1] + a[i] - mid;
            qsmn[i] = min(qsmn[i - 1], qs[i]);
            if(i - k < 0)
                continue;
            if(qs[i] - qsmn[i - k] >= 1e-6) {
                ch = true;
                break;
            }
        }
        if(ch)
            lb = mid;
        else
            rb = mid - 1e-6;
    }
    cout << fixed << setprecision(1) << lb << "\n";
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
4 2
4 3 4 2

6 3
6 3 1 2 1 7
*/