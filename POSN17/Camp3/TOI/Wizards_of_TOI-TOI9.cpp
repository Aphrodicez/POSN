/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Hash Table
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

const int MaxN = 15e2 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

const int HASH_SIZE = 5e6 + 11;

struct HASH {
    int mp[HASH_SIZE];
    pair <int, int> realValue[HASH_SIZE];
    int mod(int val) {
        return ((val % HASH_SIZE) + HASH_SIZE) % HASH_SIZE;
    }
    int quad_prob(int key, int cnt) {
        return mod(mod(key) + mod(cnt * cnt));
    }
    void insert(int idx, int sumx, int sumy) {
        int key = mod(3 * sumx + sumy);
        int cnt = 0;
        pair <int, int> val = make_pair(sumx, sumy);
        while(mp[key]) {
            key = quad_prob(key, ++cnt);
        }
        mp[key] = idx;
        realValue[key] = val;
    }
    int find(int sumx, int sumy) {
        int key = mod(3 * sumx + sumy);
        int cnt = 0;
        pair <int, int> val = make_pair(sumx, sumy);
        while(mp[key]) {
            if(realValue[key] == val) {
                return mp[key];
            }
            key = quad_prob(key, ++cnt);
        }
        return 0;
    }
};

int x[4][MaxN], y[4][MaxN];

HASH mp;

void solve() {
    int ansx, ansy;
    scanf("%d %d", &ansx, &ansy);
    int n;
    scanf("%d", &n);
    for(int k = 0; k < 4; k++) {
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &x[k][i], &y[k][i]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            mp.insert(i * n + (j + 1), x[0][i] + x[1][j], y[0][i] + y[1][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int idx = mp.find(ansx - (x[2][i] + x[3][j]), ansy - (y[2][i] + y[3][j]));
            if(idx) {
                idx--;
                printf("%d %d\n", x[0][idx / n], y[0][idx / n]);    
                printf("%d %d\n", x[1][idx % n], y[1][idx % n]);    
                printf("%d %d\n", x[2][i], y[2][i]);    
                printf("%d %d\n", x[3][j], y[3][j]);
                return ;    
            }
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
-1 3 
3
1 -10 16 3 -11 -10 
-17 7 -15 -2 -7 9 
-2 6 -18 -15 5 19 
9 -18 -7 -17 19 4

-1 3 
3
1 -10 16 3 -11 -10 
-17 7 -15 -2 -7 9 
-2 6 -18 -15 5 19 
9 -18 -7 -17 19 4

-10 10 
2
1 8 -2 -5 
-5 -5 -5 2 
9 0 -1 4 
10 8 -5 3 
*/