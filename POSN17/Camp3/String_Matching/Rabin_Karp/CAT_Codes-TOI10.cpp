/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: String Matching [ Rabin Karp ] + Hash
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
const int MaxM = 1e6 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int HASH_SIZE = 1e6 + 3;

struct HASH {
    int mp[HASH_SIZE], realValue[HASH_SIZE];
    void insert(int idx, int val) {
        int it = val % HASH_SIZE;
        while(mp[it]) {
            it++;
            it %= HASH_SIZE;
        }
        mp[it] = idx;
        realValue[it] = val;
    }
    int find(int val) {
        int it = val % HASH_SIZE;
        int idx = 0;
        while(mp[it]) {
            if(realValue[it] == val) {
                idx = mp[it];
                break;
            }
            it++;
            it %= HASH_SIZE;
        }
        return idx;
    }
};

bool visited[MaxN];

char a[40], text[MaxM];

HASH mp;

void solve() {
    int k, sz;
    scanf("%d %d ", &k, &sz);
    int allbit = (1 << sz) - 1;
    for(int i = 1; i <= k; i++) {
        gets(a);
        int pattern = 0;
        for(int j = 0; j < sz; j++) {
            char val = a[j];
            pattern = ((pattern << 1) | (val - '0'));
        }
        mp.insert(i, pattern);
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        scanf("%d ", &n);
        gets(text);
        if(n < sz) {
            printf("OK\n");
            continue;
        }
        int hash_text = 0;
        for(int i = 0; i < sz; i++) {
            hash_text = (hash_text << 1) | (text[i] - '0');
        }
        int len = strlen(text);
        bool ch = false;
        for(int i = 0; i + sz - 1 < len; i++) {
            int idx = mp.find(hash_text);
            if(idx && !visited[idx]) {
                ch = true;
                visited[idx] = true;
            }
            hash_text = ((hash_text << 1) & allbit) | (text[i + sz] - '0');
        }
        if(!ch) {
            printf("OK\n");
            continue ;
        }
        for(int i = 1; i <= k; i++) {
            ch = true;
            if(visited[i])
                printf("%d ", i);
            visited[i] = false;
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
5 5
01001
10110
11100
10100
11111
2
15
101010101010101
20
11110110011111000010
*/