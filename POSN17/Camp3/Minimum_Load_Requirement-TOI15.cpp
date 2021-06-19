/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Permutation + Branch and Bound + Binary Search + Quicksum
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

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct GRAPH {
    
};

const int N = 1e1 + 10;
const int M = 1e7 + 10;

i64 n, m, q;

i64 lift[N], a[N], t[N], group[N], chooseA[N], chooseGroup[N], qs[M];

i64 mark[N][N][N];

i64 check(int tc, int i, int aidx, int studentidx) {
    if(mark[i][aidx][studentidx] != -1)
        return mark[i][aidx][studentidx];
    i64 cnt = 0;
    i64 l = group[studentidx], r = group[studentidx + 1];
    while(l < r) {
        int nextl = upper_bound(qs + l, qs + r, qs[l - 1] + lift[i] - a[aidx]) - qs;
        if(l == nextl) {
            for(int j = i; j >= 1; j--){
                for(int k = aidx; k <= n; k++){
                    mark[j][k][studentidx] = 0;
                }
            }
            return mark[i][aidx][studentidx] = 0;
        }
        l = nextl;
        cnt++;
        if(cnt > t[tc]) {
            for(int j = i; j >= 1; j--){
                for(int k = aidx; k <= n; k++){
                    mark[j][k][studentidx] = 0;
                }
            }
            return mark[i][aidx][studentidx] = 0;
        }
    }
    for(int j = i; j <= n; j++) {
        for(int k = aidx; k >= 1; k--) {
            mark[j][k][studentidx] = 1;
        }
    }
    return mark[i][aidx][studentidx] = 1;
}

bool solve(int tc) {
    memset(mark, -1, sizeof mark);
    for(int i = 1; i <= n; i++) {
        cin >> group[i];
        chooseGroup[i] = i;
    }
    group[n + 1] = m + 1;
    do{
        bool ch = true;
        for(int i = 1; i <= n; i++) {
            ch = check(tc, i, chooseA[i], chooseGroup[i]);
            if(!ch)
                break;
        }
        if(ch)
            return ch;
    }while (next_permutation(chooseGroup + 1, chooseGroup + n + 1));
    return false;
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &lift[i]);
    }
    sort(lift + 1, lift + n + 1);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        chooseA[i] = 1;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= m; i++) {
        scanf("%lld", &qs[i]);
        qs[i] += qs[i - 1];
    }
    for(int i = 1; i <= q; i++) {
        scanf("%lld", &t[i]);
    }
    for(int i = 1; i <= q; i++) {
        printf(solve(i) ? "P" : "F");
        printf("\n");
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
2 10 3
230 300
56 65
160 120 35 80 42 87 72 45 55 63
2 2 1
1 4
1 3
1 6

3 8 1
150 100 200
45 60 55
80 45 50 62 48 40 68 55
2
1 3 5
*/