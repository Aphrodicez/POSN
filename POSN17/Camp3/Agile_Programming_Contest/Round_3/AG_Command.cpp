/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math + Greedy Algorithm
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

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

void solve() {
    int t, n;
    cin >> t >> n;
    int realN = n;
    vector <int> factor;
    while(n % 4 == 0) {
        factor.push_back(4);
        n /= 4;
    }
    while(n % 6 == 0) {
        factor.push_back(6);
        n /= 6;
    }
    for(int i = 2; i <= sqrt(realN); i++) {
        if(i == 4 || i == 6) {
            continue;
        }
        while(n % i == 0) {
            factor.push_back(i);
            n /= i;
        }
    }
    if(n > 1)
        factor.push_back(n);
    sort(all(factor));
    string ans;
    for(int x : factor) {
        ans += "AC";
        for(int i = 0; i < x; i++) {
            ans += "V";
        }
    }
    cout << ans << "\n";
    return ;
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
0 2

1 9

2 30

3 512

4 1219

5 50220

6 124609

7 508394

8 649424

9 882660

10 945595

11 9009000

12 14348907

13 56360304

14 140849280

15 479001600
*/