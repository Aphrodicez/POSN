/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: String Matching [ Rabin Karp ]
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
const int MaxM = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int HASH_SIZE = 1e6 + 3;

char text[MaxM], s[30 + 10], opr[5];
int dp[MaxM];

int n, sz, m;
int allbit;
int ans = 0;

struct HASH {
    int mp[HASH_SIZE], realValue[HASH_SIZE];
    int next_key(int key, int tmp) {
        return (key + (1ll * tmp * tmp) % HASH_SIZE) % HASH_SIZE;
    }
    void insert(int idx, int val) {
        int key = val % HASH_SIZE;
        int tmp = 1;
        while(mp[key]) {
            key = next_key(key, tmp);
            tmp++; 
        }
        mp[key] = 1;
        realValue[key] = val;
    }
    int find(int val) {
        int key = val % HASH_SIZE;
        int tmp = 1;
        while(mp[key]) {
            if(realValue[key] == val) {
                return mp[key];
            }
            key = next_key(key, tmp);
            tmp++;
        }
        return 0;
    }
};

HASH mp;

void flip(int l, int r, int idx) {
    text[idx] = ((text[idx] - '0') ^ 1) + '0';
    l = max(l, 1);
    r = min(r, m);
    int now = 0;
    for(int i = l; i <= r && i <= l + sz - 1; i++) {
        now = (now << 1) | (text[i] - '0');
    }
    for(int i = l; i + sz - 1 <= r; i++) {
        int found = (mp.find(now) != 0);
        ans += found - dp[i];
        dp[i] = found;
        now = ((now << 1) & (allbit)) | (text[i + sz] - '0');
    }
}

void solve() {
    scanf("%d %d %d", &n, &sz, &m);
    scanf(" %s", (text + 1));
    allbit = (1 << sz) - 1;
    for(int i = 1; i <= n; i++) {
        scanf(" %s", (s + 1));
        int pattern = 0;
        for(int j = 1; j <= sz; j++) {
            pattern = (pattern << 1) | (s[j] - '0');
        }
        mp.insert(i, pattern);
    }
    flip(1, m, 0);
    int q;
    scanf("%d", &q);
    while(q--) {
        scanf(" %s", opr + 1);
        int idx;
        if(opr[2] == 'l') {
            scanf("%d", &idx);
            idx++;
            flip(idx - sz + 1, idx + sz - 1, idx);
        }
        if(opr[2] == 'i') {
            printf("%d\n", ans);
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
3 5 30
010100101010111101010101110100
11010
10101
00100
8
Find
Flip 10
Find
Flip 22
Find
Flip 6
Flip 5
Find
*/