/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [ Longest Common Subsequence ] + Greedy Algorithm
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
const int MaxK = 1e2 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

char pattern[MaxK], text[MaxN];
int dp[2][MaxN];

void solve() {
    scanf(" %s", pattern + 1);
    scanf(" %s", text + 1);
    int k = strlen(pattern + 1);
    int n = strlen(text + 1);

    for(int state = 0; state <= 1; state++) {
        for(int i = 1; i <= n; i++) {
            dp[state][i] = 1e9;
        }
    }    
    for(int i = 1; i <= k; i++) {
        pattern[i] = tolower(pattern[i]);
    }
    for(int i = 1; i <= n; i++) {
        text[i] = tolower(text[i]);
        if(text[i] == pattern[1])
            dp[1][i] = 0;
    }
    int last;
    for(int state = 2; state <= k; state++) {
        last = 0;
        for(int i = 1; i <= n; i++) {
            dp[state & 1][i] = 1e9;
            if(text[i] == pattern[state] && last) {
                    dp[state & 1][i] = dp[state & 1 ^ 1][last] + (i - (last + 1));
            }
            if(dp[state & 1 ^ 1][i] != 1e9)
                last = i;
        }
    }
    int ans = 1e9;
    for(int i = 1; i <= n; i++) {
        ans = min(ans, dp[k & 1][i]);
    }
    if(ans == 1e9)
        printf("RIP ASIA\n");
    else
        printf("%d\n", ans);
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
save
AsiaLovesPeattvsZombies

FunO
FkO
*/