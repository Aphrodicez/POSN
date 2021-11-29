/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Permutation
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

int n;
vector <char> ans;

void permutation(int a, int b) {
    if(a == n || b == n) {
        for(char x : ans) {
            printf("%c ", x);
        }
        printf("\n");
        return ;
    }
    ans.emplace_back('W');
    permutation(a + 1, b);
    ans.pop_back();
    ans.emplace_back('L');
    permutation(a, b + 1);
    ans.pop_back();
}

void solve() {
    scanf("%d", &n);
    int a, b;
    scanf("%d %d", &a, &b);
    permutation(a, b);
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
0 
1

2 
1 
0

3
0
0
*/