/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Brute Force
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

const int N = 1e5 + 10;
const int M = 2e5 + 10;

int idx[N], val[N];

void solve() {
    int n;
    scanf("%d", &n);
    int now = 0, cnt = 0, mx = -1, ans = 1, st = 1;
    char dir = 'L';
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &idx[i], &val[i]);
        if(now <= idx[i]){
            if(cnt > mx){
                mx = cnt;
                ans = st;
                dir = 'R';
            }
            st = i;
            cnt = 1;
            now = idx[i] + val[i];
        }
        else{
            cnt++;
            now = max(now, idx[i] + val[i]);
        }
    }
    if(mx < cnt)
        mx = cnt, ans = st, dir = 'R';
    now = 1e9 + 10;
    cnt = 0;
    for(int i = n; i >= 1; i--){
        if(now >= idx[i]){
            if(cnt > mx){
                mx = cnt;
                ans = st;
                dir = 'L';
            }
            else if(cnt == mx && ans >= st){
                mx = cnt;
                ans = st;
                dir = 'L';
            }
            st = i;
            cnt = 1;
            now = idx[i] - val[i];
        }
        else{
            cnt++;
            now = min(now, idx[i] - val[i]);
        }
    }
    if(mx < cnt)
        mx = cnt, ans = st, dir = 'L';
    else if(cnt == mx && ans >= st)
        mx = cnt, ans = st, dir = 'L';
    printf("%d %c", ans, dir);
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
5
1 1
3 3
5 4
7 15
10 3
*/