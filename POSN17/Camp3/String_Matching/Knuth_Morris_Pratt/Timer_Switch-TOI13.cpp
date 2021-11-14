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

const int MaxN = 5e6 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

char pattern[2 * MaxN], tmp[MaxN];

int prefix[MaxN];

void solve() {
    int n;
    scanf("%d", &n);
    scanf("%s", (pattern + 1));
    strcpy(tmp + 1, pattern + 1);
    strcat(pattern + 1, tmp + 1);
    int j = 0;
    for(int i = 2; i <= n; i++) {
        while(j > 0 && (pattern[i] != pattern[j + 1])) {
            j = prefix[j];
        }
        if(pattern[i] == pattern[j + 1])
            j++;
        prefix[i] = j;
    }
    j = 0;
    for(int i = 2; i <= 2 * n; i++) {
        while(j > 0 && (pattern[i] != pattern[j + 1])) {
            j = prefix[j];
        }
        if(pattern[i] == pattern[j + 1])
            j++;
        if(j == n) {
            printf("%d\n", i - n);
            return ;
        }
    }
    printf("%d\n", n);
    return ;
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
10
1010101010

10
1000000010

5
00000

5
10000

7
ababaca
*/