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

char opr[10];
unordered_map <char, pair <double, double> > mp;

void solve() {
    mp['N'] = make_pair(0, 1), mp['E'] = make_pair(1, 0);
    mp['S'] = make_pair(0, -1), mp['W'] = make_pair(-1, 0);

    pair <double, double> ans = make_pair(0, 0);
    while(1) {
        scanf(" %s", opr);
        if(opr[0] == '*') {
            break;
        }
        int len = strlen(opr);
        double val = atoi(opr);
        int st;
        for(int i = 1; i <= 2 && isalpha(opr[len - i]); st = len - i, i++);
        if(st == len - 2) {
            val /= sqrt(2);
        }
        pair <double, double> dir;
        pair <double, double> sum = make_pair(0, 0);
        for(int i = st; i < len; i++) {
            dir = mp[opr[i]];
            sum = make_pair(sum.first + (val * dir.first), sum.second + (val * dir.second));
        }
        ans = make_pair(ans.first + sum.first, ans.second + sum.second); 
    }
    printf("%.3lf %.3lf\n", ans.first, ans.second);
    printf("%.3lf\n", sqrt((ans.first * ans.first) + (ans.second * ans.second)));
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
3N 1E 1N 3E 2S 1W *

6NW *
*/