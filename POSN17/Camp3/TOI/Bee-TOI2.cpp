/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Recursion
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

struct GRAPH {
    
};

pair <int, int> recursive(int n) {
    if(n == 0) {
        return make_pair(1, 2);
    }
    pair <int, int> res = recursive(n - 1);
    return make_pair(res.second, 1 + res.first + res.second);
}

void solve(int n) {
    pair <int, int> res = recursive(n);
    printf("%d %d\n", res.first, res.second);
}

int main() {
    int n = 1;
    while(1) {
        scanf("%d", &n);
        if(n == -1)
            break;
        solve(n);
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

/*
1 3 -1
*/