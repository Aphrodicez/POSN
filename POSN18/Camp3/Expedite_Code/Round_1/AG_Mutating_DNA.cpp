/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Prefix Sum + Math
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;

char a[MaxN], b[MaxN];
unordered_map <char, int> mp;
int qs[3][3][MaxN];

int main() {
    mp['A'] = 0;
    mp['C'] = 1;
    mp['T'] = 2;
    int n, q;
    scanf("%d %d", &n, &q);
    scanf(" %s", a + 1);
    scanf(" %s", b + 1);
    for(int k = 1; k <= n; k++) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                qs[i][j][k] += qs[i][j][k - 1];
            }
        }
        qs[mp[a[k]]][mp[b[k]]][k]++;
    }
    while(q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        l++, r++;
        vector <vector <int>> sum(3, vector <int> (3, 0));
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i == j)
                    continue;
                sum[i][j] = qs[i][j][r] - qs[i][j][l - 1];
            }
        }
        int ans = 0;
        int left[3] = {0, 0, 0};
        for(int i = 0; i < 3; i++) {
            for(int j = i + 1; j < 3; j++) {
                int mn = min(sum[i][j], sum[j][i]);
                sum[i][j] -= mn;
                sum[j][i] -= mn;
                ans += mn;
                left[i] += sum[i][j];
                left[j] += sum[j][i];
            }
        }
        if(*min_element(left, left + 3) != *max_element(left, left + 3))
            printf("-1\n");
        else
            printf("%d\n", ans + 2 * left[0]);
    }
    return 0;
}

/*
6 3
ATACAT
ACTATA
1 3
4 5
3 5
*/