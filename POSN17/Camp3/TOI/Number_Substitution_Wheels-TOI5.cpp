/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math
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

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

char s[256 + 10];
int start[5], change[5];

void solve() {
    scanf(" %s", s);
    for(int i = 0; i < 3; i++) {
        start[i] = change[i] = s[i] - '0';
        start[i]--;
    }
    change[1] = 8;
    scanf(" %s", s);
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        int now = s[i] - '1';
        for(int j = 0; j < 3; j++) {
            now = (start[j] + now) % 9;
            start[j] = (start[j] + change[j]) % 9;
        }
        printf("%d", now + 1);
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
486
59

486
26

382
33687493
*/