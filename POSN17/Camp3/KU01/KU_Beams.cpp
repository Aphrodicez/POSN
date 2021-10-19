/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Two Pointers + Brute Force
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

int a[510], b[510];

void solve() {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int j = 1; j <= m; j++) {
        scanf("%d", &b[j]);
    }
    int ans = 1;
    int i = 1, j = 1;
    while(i + 1 <= n || j + 1 <= m) {
        if(i + 1 <= n && a[i] <= b[j]) {
            if(i % 2 == j % 2 && a[i] < b[j]) {
                ans++;
            }
            else if(a[i] != b[j - 1] && a[i + 1] <= b[j]) {
                ans++;
            }
            i++;
        }
        else if(j + 1 <= m && b[j] < a[i]) {
            if(i % 2 == j % 2 && b[j] < a[i]) {
                ans++;
            }
            else if(b[j] != a[i - 1] && b[j + 1] <= a[i]) {
                ans++;
            }
            j++;
        }
        else
            break;
    }
    printf("%d\n", ans);
}

int main() {
    int q = 1;
    scanf("%d", &q);
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
4
5 7
2 7 8 15 20
3 4 5 7 10 16 21
3 3
10 20 30
1 10 20
2 4
10 20
5 10 15 20
4 8
10 20 30 40
5 10 15 20 25 30 35 40
*/