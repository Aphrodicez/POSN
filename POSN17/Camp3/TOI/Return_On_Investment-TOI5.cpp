/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math + Brute Force
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

void solve() {
    double n;
    scanf("%lf", &n);
    int ans_cnt = -1, ans_sell = -1;
    double ans_bep = 1e9;
    for(int sell = 77; sell <= 144; sell++) {
        int cost = 100;
        for(double cnt = 1000; cnt <= 15000; cnt += 500) {
            double sold = ((100 - (0.8569 * exp(0.09 * (sell - 100)))) * cnt) / 100;
            double bep = (sell * sold) - n - (cost * cnt);
            if(bep > 0 && ans_bep > bep) {
                ans_cnt = cnt;
                ans_sell = sell;
                ans_bep = bep;
            }
            cost = (cost * 99) / 100;
        }
    }
    printf("%d\n%d\n%.2lf\n", ans_cnt, ans_sell, ans_bep);
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
30000

55000

70000
*/