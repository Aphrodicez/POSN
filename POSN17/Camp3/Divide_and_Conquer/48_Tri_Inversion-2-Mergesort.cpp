/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 2 Mergesort [Inversion Count] + Dynamic Programming [Quicksum]
    Status	: Accepted
    Created	: 21 August 2021 [01:32]
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
#define dec(x) fixed << setprecision(x)
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct A {
    i64 idx, val;
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

i64 original[N], cnt[N], qs[N];

A a[N], b[N];

i64 ans = 0;

void mergeSort(int l, int r, int opr) {
    if(l >= r)
        return ;
    int mid = l + (r - l) / 2;
    mergeSort(l, mid, opr);
    mergeSort(mid + 1, r, opr);
    for(int i = l; i <= r; i++) 
        qs[i] = qs[i - 1] + cnt[a[i].idx];
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r) {
        if(a[i].val <= a[j].val) {
            b[k] = a[i];
            k++;
            i++;
        }
        else {
            b[k] = a[j];
            if(opr == 2)
                cnt[a[j].idx] += mid - i + 1;
            else
                ans += qs[mid] - qs[i - 1];
            k++;
            j++;
        }
    }
    while(i <= mid) {
        b[k++] = a[i++];
    }
    while(j <= r) {
        b[k++] = a[j++];
    }
    for(int i = l; i <= r; i++)
        a[i] = b[i];
}

void solve() {
    memset(cnt, 0, sizeof cnt);
    ans = 0;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> original[i];
        a[i] = {i, original[i]};
    }
    mergeSort(1, n, 2);
    for(int i = 1; i <= n; i++) {
        a[i] = {i, original[i]};
        qs[i] = qs[i - 1] + cnt[i];
    }
    mergeSort(1, n, 3);
    cout << ans << "\n";
}

int main() {
    setIO();
    int q = 1;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
3
4
9 7 5 3
4
1 4 3 2
3
2 3 1
*/