/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Rabin Karp Algorithm + Binary Search
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define i first
#define j second
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define pc(x) putchar(x)
#define MP make_pair
#define dec(x) fixed << setprecision(x)
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct GRAPH {
    
};

const int N = 1e6 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

const int HASH = 1e9 + 7;

i64 hashDPL[N], hashDPR[N], HASH_POWER[N];

char s[N];

i64 palin[N];

void solve() {
    int n;
    cin >> n;
    cin >> (s + 1);
    unordered_map <char, int> mapp;
    
    mapp['A'] = 0;
    mapp['T'] = 1;
    mapp['C'] = 2;
    mapp['G'] = 3;
    HASH_POWER[0] = 1;

    for(int i = 1; i <= n; i++) {
        hashDPL[i] = hashDPL[i - 1] * HASH;
        hashDPL[i] += mapp[s[i]];
        HASH_POWER[i] = HASH_POWER[i - 1] * HASH;
    }
    for(int i = n; i >= 1; i--) {
        hashDPR[i] = hashDPR[i + 1] * HASH;
        hashDPR[i] += mapp[s[i]];
    }
    
    for(int i = 1; i <= n; i++) {
        int lsz = 1;
        int rsz = min(i, n - i + 1);
        while(lsz < rsz) {
            int midsz = lsz + (rsz - lsz + 1) / 2;
            i64 LString = hashDPL[i] - (hashDPL[i - midsz] * HASH_POWER[midsz]);
            i64 RString = hashDPR[i] - (hashDPR[i + midsz] * HASH_POWER[midsz]);
            if(LString == RString)
                lsz = midsz;
            else
                rsz = midsz - 1;
        }
        palin[2 * lsz - 1]++;
    }
    for(int i = 1; i <= n - 1; i++) {
        if(s[i] != s[i + 1])
            continue;
        int lsz = 1;
        int rsz = min(i, n - i);
        while(lsz < rsz) {
            int midsz = lsz + (rsz - lsz + 1) / 2;
            i64 LString = hashDPL[i] - (hashDPL[i - midsz] * HASH_POWER[midsz]);
            i64 RString = hashDPR[i + 1] - (hashDPR[i + midsz + 1] * HASH_POWER[midsz]);
            if(LString == RString)
                lsz = midsz;
            else
                rsz = midsz - 1;
        }
        palin[2 * lsz]++;
    }
    for(int i = n - 2; i >= 1; i--)
        palin[i] += palin[i + 2];
    for(int i = 1; i <= n; i++) {
        cout << palin[i] << "\n";
    }
}

int main() {
    setIO();
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
5
ATATA
*/