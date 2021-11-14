/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: String Matching [ Knuth Morris Pratt ]
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

const int MaxN = 1e6 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

char pattern[MaxN], text[MaxN];
int prefix[MaxN];

void solve() {
    scanf(" %s", (text + 1));
    scanf(" %s", (pattern + 1));
    int j = 0;
    int n = strlen(pattern + 1);
    for(int i = 2; i <= n; i++) {
        while(j > 0 && (pattern[i] != pattern[j + 1])) {
            j = prefix[j];
        }
        if(pattern[i] == pattern[j + 1])
            j++;
        prefix[i] = j;
    }
    int len = strlen(text + 1);
    j = 0;
    for(int i = 1; i <= len; i++) {
        while(j > 0 && (text[i] != pattern[j + 1])) {
            j = prefix[j];
        }
        if(text[i] == pattern[j + 1])
            j++;
        if(j == n) {
            printf("Lucky\n");
            return ;
        }
    }
    printf("Unlucky\n");
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
peatthandsome
peatt

peatt12345
peatt2
*/