/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Depth First Search
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

const int MaxN = 3e1 + 10;
const int MaxM = 1e2 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct DFS {
    int i, j, state;
};

char a[MaxN][MaxN];
char s[MaxM];

stack <DFS> st;

int r, c, len;

bool dfs(int i, int j, int state, int dir) {
    if(state == len - 1) {
        return true;
    }
    int ii = i + d8i[dir];
    int jj = j + d8j[dir];
    if(ii < 0 || jj < 0 || ii > r - 1 || jj > c - 1)
        return false;
    if(a[ii][jj] != s[state + 1])
        return false;
    return dfs(ii, jj, state + 1, dir);
}

void solve() {
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++) {
        scanf("%s", a[i]);
        for(int j = 0; j < c; j++) {
            a[i][j] = tolower(a[i][j]);
        }
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        scanf(" %s", s);
        len = strlen(s);
        for(int i = 0; i < len; i++) {
            s[i] = tolower(s[i]);
        }
        bool ans = false;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(a[i][j] == s[0]) {
                    for(int k = 0; k < 8; k++) {
                        ans = dfs(i, j, 0, k);
                        if(ans) {
                            printf("%d %d\n", i, j);
                            break;
                        }
                    }

                }                    
                if(ans)
                    break;
            }
            if(ans)
                break;
        }
    }
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
8 11
ascDEFGhigg
hTqkComPutk
FayUcompuTm
FcsierMqsrc
bkoArUePeyv
Klcbqwekumk
sreTNIophtb
yUiqlxcnBje
4
Compute
Queue
stack
Pointer
*/