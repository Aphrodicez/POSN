/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Greedy Algorithm + Dynamic Programming
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

struct NODE {
    int i, j, w;
    bool operator < (const NODE &o) const {
        return w > o.w;
    }
};

const int MaxN = 1e2 + 10;

int a[MaxN][MaxN];
vector <NODE> vec;
int dp[MaxN][MaxN];

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            dp[i][j] = 1;
            scanf("%d", &a[i][j]);
            vec.push_back({i, j, a[i][j]});
        }
    }
    sort(vec.begin(), vec.end());
    for(auto x : vec) {
        int i = x.i;
        int j = x.j;
        for(int k = 0; k < 4; k++) {
            int ii = i + di[k];
            int jj = j + dj[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj] >= a[i][j])
                continue;
            dp[ii][jj] = max(dp[ii][jj], dp[i][j] + 1);
        }
    }
    int ans = 0;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}

/*
3 3
1 2 3
4 5 6
7 8 9

2 3
1 2 1
2 1 2
*/