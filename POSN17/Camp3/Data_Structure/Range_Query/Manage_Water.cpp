/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Fenwick Tree [ Range Query 2D ]
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

const int MaxN = 2e3 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

long long tree[MaxN][MaxN];

int n;

void upd(int x, int y, long long val) {
    for(int i = y; i <= n; i += (i & -i)) {
        for(int j = x; j <= n; j += (j & -j)) {
            tree[i][j] += val;
        }
    }
}

long long query(int x, int y) {
    long long sum = 0;
    for(int i = y; i > 0; i -= (i & -i)) {
        for(int j = x; j > 0; j -= (j & -j)) {
            sum += tree[i][j];
        }
    }
    return sum;
}

void solve() {
    int opr;
    cin >> opr >> n;
    while(1) {
        cin >> opr;
        int x1, y1, x2, y2;
        long long val;
        if(opr == 1) {
            cin >> x1 >> y1 >> val;
            x1++, y1++;
            upd(x1, y1, val);
            continue;
        }
        if(opr == 2) {
            cin >> x1 >> y1 >> x2 >> y2;
            x1++, y1++, x2++, y2++;
            if(x1 > x2)
                swap(x1, x2);
            if(y1 > y2)
                swap(y1, y2);
            cout << query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1) << "\n";
            continue;
        }
        break;
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
0 4
1 1 2 3
2 0 0 2 2
1 1 1 2
1 1 2 -1
2 1 1 2 3
3
*/