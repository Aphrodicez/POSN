/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Simulation
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

const int MaxN = 1e1 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    int i, j;
};

char a[MaxN][MaxN];

queue <GRAPH> qu;

int r, c;

int ans = 0;

void bfs(int sti, int stj) {
    while(!qu.empty())
        qu.pop();
    char name = a[sti][stj];
    qu.push({sti, stj});
    a[sti][stj] = '-';
    ans += 5;
    while(!qu.empty()) {
        int i = qu.front().i;
        int j = qu.front().j;
        qu.pop();
        for(int k = 0; k < 4; k++) {
            int ii = i + d4i[k];
            int jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj] != name)
                continue;
            a[ii][jj] = '-';
            ans += 5;
            qu.push({ii, jj});
        }
    }
}

bool reset() {
    for(int i = 1; i <= r - 1; i++) {
        for(int j = 1; j <= c; j++) {
            if(isalpha(a[i][j]) && a[i + 1][j] == '-')
                swap(a[i][j], a[i + 1][j]);
        }
    }
    bool loop = false;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(isalpha(a[i][j])) {
                bool explode = false;
                for(int k = 0; k < 4; k++) {
                    int ii = i + d4i[k];
                    int jj = j + d4j[k];
                    if(ii < 1 || jj < 1 || ii > r || jj > c)
                        continue;
                    explode |= (a[ii][jj] == a[i][j]);
                }
                if(explode)
                    bfs(i, j);
                loop |= explode;
            }
        }
    }
    return loop;
}

void solve() {
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            scanf(" %c", &a[i][j]);
        }
    }
    while(reset());
    int q;
    scanf("%d", &q);
    while(q--) {
        int i, j;
        char opr;
        scanf("%d %d %c", &i, &j, &opr);
        i++, j++;
        int ii, jj;
        ii = i;
        if(opr == 'L')
            jj = j - 1;
        else
            jj = j + 1;
        ans -= 5;
        if(!isalpha(a[i][j]))
            continue;
        if(jj < 1 || jj > c)
            continue;
        if(a[ii][jj] != '-')
            continue;
        ans += 5;
        swap(a[i][j], a[ii][jj]);
        while(reset());
    }
    printf("%d\n", ans);
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            printf("%c ", a[i][j]);
        }
        printf("\n");
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
4 5
# A - - #
# # - B #
# A B # #
# # # # #
2
1 3 L
0 1 R

5 5
# A – B #
# B - A #
# # - B #
# A B # #
# # # # #
3
0 1 L
0 3 L
0 1 R

*/