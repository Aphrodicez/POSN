/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Sieve of Eratosthenes
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
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

const int MaxN = 5e5 + 10;
const int MaxP = 8e6;

void TESTCASE() {
    
}

bitset <MaxP + 10> mark;
int prime[MaxN];

int cnt = 0;

void gen_prime() {
    mark[2] = 1;
    prime[++cnt] = 2;
    int i = 3;
    for(i = 3; i <= sqrt(MaxP) && cnt <= 500000; i += 2) {
        if(mark[i])
            continue;
        mark[i] = 1;
        prime[++cnt] = i;
        for(int j = i * i; j <= MaxP; j += i) {
            if(mark[j])
                continue;
            mark[j] = 1;
        }
    }
    for(; i <= MaxP && cnt <= 500000; i += 2) {
        if(mark[i])
            continue;
        prime[++cnt] = i;
    }
}

void solve() {
    gen_prime();
    int n;
    cin >> n;
    cout << prime[n] << "\n";
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

*/