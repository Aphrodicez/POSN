/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Map Iteration
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

const int N = 1e5 + 10;
const int M = 2e5 + 10;

map <int, int> mp;

int L, R, n;

void solve() {
    int idx;
    scanf("%d", &idx);
    mp[idx] = 1;
    map <int, int> :: iterator it, lit, rit;
    it = mp.find(idx);
    lit = rit = it;
    rit++;
    if(rit == mp.end() && it == mp.begin()){
        printf("%d\n", R);
        return ;
    }
    if(it == mp.begin()){
        int rval = rit -> first;
        printf("%d\n", rval - idx);
        return ;
    }
    lit--;
    if(rit == mp.end()){
        int lval = lit -> first;
        printf("%d\n", idx - lval);
        return ;
    }
    int lval = lit -> first;    
    int rval = rit -> first;
    printf("%d\n", min(idx - lval, rval - idx));
}

int main() {
    scanf("%d %d", &R, &n);
    L = 1;
    for(int i = 1; i <= n; i++){
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
11 3
3
6
10

20 7
3
18
14
6
5
10
12
*/