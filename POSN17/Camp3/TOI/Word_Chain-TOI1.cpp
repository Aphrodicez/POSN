/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: String
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

string s, last;

void solve() {
    int n, q;
    cin >> n >> q;
    cin >> last;
    int cnt = 0;
    while(--q) {
        cin >> s;
        cnt = 0;
        for(int i = 0; i < n && cnt <= 2; i++) {
            cnt += (s[i] != last[i]);
        }
        if(cnt > 2)
            break;
        last = s;
    }
    cout << last << "\n";
}

int main() {
    setIO();
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
4
12
HEAD 
HEAP 
LEAP 
TEAR 
REAR
BAER
BAET
BEEP
JEEP
JOIP
JEIP
AEIO
*/

