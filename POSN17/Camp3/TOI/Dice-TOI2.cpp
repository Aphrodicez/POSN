/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Brute Force
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

const int MaxN = 1e3 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

char a[MaxN];
unordered_map <char, vector <int>> mp;

void solve() {
    mp['F'] = {0, 1, 5, 3};
    mp['B'] = {3, 5, 1, 0};
    mp['L'] = {0, 2, 5, 4};
    mp['R'] = {4, 5, 2, 0};
    mp['C'] = {1, 2, 3, 4};
    mp['D'] = {4, 3, 2, 1};

    int q;
    scanf("%d", &q);
    while(q--) {
        scanf(" %s", a);
        int len = strlen(a);    
        vector <int> dice = {1, 2, 3, 5, 4, 6};
        vector<int> tmp;
        for(int i = 0; i < len; i++) {
            tmp = dice;
            for(int k = 0; k < 4; k++) {
                tmp[mp[a[i]][(k + 1) % 4]] = dice[mp[a[i]][k]];
            }
            dice = tmp;
        }    
        printf("%d ", dice[1]);
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
3
D
FFBB
BBFFR
*/