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

const int MaxN = 127 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};


char encryptor[2][MaxN];
char key[MaxN];

int n, m;

char median(vector <char> vec) {
    nth_element(vec.begin(), vec.begin() + 1, vec.end());
    return vec[1];
}

void encrypt(int l, int r) {
    int j = 1;
    for(int i = l; i <= r; i++, j++) {
        if(i < 1 || i > n)
            continue;
        key[i] = median({encryptor[0][j], key[i], encryptor[1][j]});
    }
}

void solve() {
    scanf("%d %d", &m, &n);
    for(int i = 0; i < 2; i++) {
        scanf(" %s", encryptor[i] + 1);
    }
    scanf(" %s", key + 1);
    int l, r;
    r = n + m - 1;
    while(r) {
        int l = r - m + 1;
        encrypt(l, r);
        r--;
    }
    printf("%s\n", key + 1);
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
4 3
BOAT
HALF
KEY

1 4
A
Z
MAKE

3 1
ANT
FAN
J

2 2
AS
IT
AS
*/