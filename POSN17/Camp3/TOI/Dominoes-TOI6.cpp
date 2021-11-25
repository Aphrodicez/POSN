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

const int MaxN = 13 + 1;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

vector <char> ans;

int n;

void permu(int state) {
    if(state > n)
        return ;
    if(state == n) {
        for(char x : ans) {
            for(int i = 1; i <= 2; i++) {
                printf("%c", x);
            }
            printf("\n");
        }
        printf("E\n");
        return;
    }
    ans.push_back('-');
    permu(state + 1);
    ans.pop_back();
    ans.push_back('|');
    permu(state + 2);
    ans.pop_back();
}

void solve() {
    scanf("%d", &n);
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
2

3
*/