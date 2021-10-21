/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math [ Least Common Multiple ]
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

string input[10], s[10];
long long dpLCM[10];
int mark[10];

long long __lcm(long long a, long long b) {
    long long gcd = __gcd(a, b);
    return ((a / gcd) * (b / gcd)) * gcd;
}

long long ans = 2e18;   

int n;
char target;

void recursive(int state, long long idx) {
    if(state == n + 1) {
        ans = min(ans, idx);
        return ;
    }
    for(long long i = idx; i - idx != dpLCM[state]  && i < ans; i += dpLCM[state - 1]) {
        if(s[state][i % s[state].size()] == target) {
            recursive(state + 1, i);
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> target;
    dpLCM[0] = 1;
    for(int i = 1; i <= n; i++) {
        cin >> input[i];
    }
    for(int it = 1; it <= n; it++) {
        long long mn = 2e18;
        int idx = 0;
        for(int i = 1; i <= n; i++) {
            if(mark[i])
                continue;
            if(__lcm(dpLCM[it - 1], (long long)input[i].size()) < mn) {
                mn = __lcm(dpLCM[it - 1], (long long)input[i].size());
                idx = i;
            }
        }
        mark[idx] = it;
        dpLCM[it] = mn;
        s[it] = input[idx];
    }
    recursive(1, 1);
    cout << ans << "\n";
    return 0;
}

/*
3 7
765416925789213
7598143287651097825694310681
72134529871278513269

3 7
75483
713295734
721832395273541
*/