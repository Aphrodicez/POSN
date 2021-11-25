/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Recursion [ Permutation ]
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

const int MaxN = 8 + 1;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

bitset <MaxN> mark, ban;
vector <int> ans;

int n, m;

void permu(int state) {
    if(state == n) {
        for(int x : ans) {
            printf("%d ", x);
        }
        printf("\n");
        return ;
    }
    for(int i = 1; i <= n; i++) {
        if(!state && ban[i])
            continue;
        if(mark[i])
            continue;
        mark[i] = true;
        ans.push_back(i);
        permu(state + 1);
        ans.pop_back();
        mark[i] = false;
    }
}

void solve() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int val;
        scanf("%d", &val);
        ban[val] = true;    
    }
    permu(0);
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
4 
3 
1 2 3

4 
2 
3 2
*/