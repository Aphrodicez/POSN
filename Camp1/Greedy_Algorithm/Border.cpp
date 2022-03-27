/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Greedy Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

struct BOX {
    int u, d, l, r;
};

BOX a[110][110];
vector <int> vec;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int it = 1; it <= 2 * n + 1; it++) {
        int i, val;
        if(it % 2 == 1) {
            i = (it / 2) + 1;
            for(int j = 1; j <= n; j++) {
                scanf("%d", &val);
                a[i][j].u = val;
                a[i - 1][j].d = val;
            }
        }
        else {
            i = (it / 2);
            for(int j = 1; j <= n + 1; j++) {
                scanf("%d", &val);
                a[i][j].l = val;
                a[i][j - 1].r = val;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            vec.push_back(((a[i][j].l - a[i][j].r) * 5) + ((a[i][j].u - a[i][j].d) * 3));
        }
    }
    sort(vec.begin(), vec.end());
    int ans = 0;
    for(int i = 0; i < k; i++) {
        ans += vec[i];
    }
    printf("%d\n", ans);
    return 0;
}

/*
4 5
11 42 30 56
49 85 23 37 15
70 9 81 60
39 2 42 98 6
57 10 55 77
14 32 28 29 30
27 64 83 1
71 85 53 99 48
5 97 68 45
*/