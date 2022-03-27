/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Recursion [ Permutation ] + Backtracking
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

int r, c;

double a[4][4];
bool mark[4][4];

double ans = 1e9;

void permu(int state, double sum) {
    if(state == r * c) {
        ans = min(ans, sum);
        return ;
    }
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(mark[i][j])
                continue;
            mark[i][j] = true;
            for(int k = 0; k < 8; k++) {
                int ii = i + di[k];
                int jj = j + dj[k];
                if(ii < 1 || jj < 1 || ii > r || jj > c)
                    continue;
                if(mark[ii][jj])
                    continue;
                a[ii][jj] += 0.1 * a[i][j];
            }
            permu(state + 1, sum + a[i][j]);
            mark[i][j] = false;
            for(int k = 0; k < 8; k++) {
                int ii = i + di[k];
                int jj = j + dj[k];
                if(ii < 1 || jj < 1 || ii > r || jj > c)
                    continue;
                if(mark[ii][jj])
                    continue;
                a[ii][jj] -= 0.1 * a[i][j];
            }
        }
    }
}

int main() {
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    permu(0, 0);
    printf("%.2lf\n", ans);
    return 0;
}

/*
2 2
500 750
1000 800

1 2
500 750

3 3
500000 750000 1000000
500000 1200000 1000000
1000000 800000 750000
*/