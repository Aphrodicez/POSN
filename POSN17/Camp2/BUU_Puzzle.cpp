/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Bitmasking
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
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const int R = 5e0 + 10;
const int C = 5e4 + 10;

int mask[13] = {0, 1, 2, 4, 5, 8, 9, 10, 16, 17, 18, 20, 21};

int a[R][C], dp[R][C];

void solve() {
    memset(dp, 0, sizeof dp);
    int c;
    scanf("%d", &c);
    for(int i = 0; i < 5; i++){
        for(int j = 1; j <= c; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int j = 1; j <= c; j++){
        for(int now = 0; now < 13; now++){
            int sum = 0;
            for(int i = 0; i < 5; i++)
                if(mask[now] & (1 << i))
                    sum += a[i][j];

            for(int last = 0; last < 13; last++)
                if(!(mask[now] & mask[last]))
                    dp[now][j] = max(dp[now][j], dp[last][j - 1] + sum);
        }
    }
    int ans = 0;
    for(int i = 0; i < 13; i++){
        ans = max(ans, dp[i][c]);
    }
    printf("%d\n", ans);
}

int main() {
    int q;
    scanf("%d", &q);
    while(q--){
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
2
6
1 0 0 0 0 0
0 1 1 10 1 0
1 10 0 0 5 10
0 1 1 10 0 0
1 0 0 0 1 10
5
1 0 0 0 1
0 1 1 1 0
0 1 1 1 0
0 1 1 1 0
1 0 0 0 1
*/