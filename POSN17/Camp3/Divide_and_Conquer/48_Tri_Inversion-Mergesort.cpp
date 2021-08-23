/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Mergesort [Inversion Count] + Math
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

i64 original[N], leftInversion[N], rightInversion[N];

A a[N], b[N];

i64 ans = 0;

void mergeSort(int l, int r) {
    if(l >= r)
        return ;
    int mid = l + (r - l) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r) {
        if(a[i].val <= a[j].val) {
            rightInversion[a[i].idx] += (j - 1) - (mid + 1) + 1;
            b[k] = a[i];
            k++;
            i++;
        }
        else {
            leftInversion[a[j].idx] += mid - i + 1;
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while(i <= mid) {
        rightInversion[a[i].idx] += r - (mid + 1) + 1;
        b[k++] = a[i++];
    }
    while(j <= r)
        b[k++] = a[j++];
    for(int i = l; i <= r; i++)
        a[i] = b[i];
}

void solve() {
    memset(leftInversion, 0, sizeof leftInversion);
    memset(rightInversion, 0, sizeof rightInversion);
    ans = 0;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> original[i];
        a[i] = {i, original[i]};
    }
    mergeSort(1, n);
    for(int i = 1; i <= n; i++) {
        ans += leftInversion[i] * rightInversion[i];
    }
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