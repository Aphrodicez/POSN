/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Mergesort [Inversion Count] + Dynamic Programming [Quicksum]
    Status	: Accepted
    Created	: 21 August 2021 [11:49]
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

struct CARD {
    int a, b;
};

bool cmpb(const CARD &a, const CARD &b) {
    return a.b < b.b;
}

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

CARD a[N], b[N];

i64 qs[N];

i64 ans = 0;

void mergeSort(int l, int r) {
    if(l >= r)
        return ;
    int mid = l + (r - l) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    for(int i = l; i <= r; i++)
        qs[i] = qs[i - 1] + a[i].a;
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r) {
        if(a[i].a <= a[j].a) {
            b[k] = a[i];
            i++;
            k++;
        }
        else {
            b[k] = a[j];
            ans += qs[mid] - qs[i - 1] + (mid - i + 1) * a[j].a;
            j++;
            k++;
        }
    }
    while(i <= mid)
        b[k++] = a[i++];
    while(j <= r)
        b[k++] = a[j++];
    for(int i = l; i <= r; i++)
        a[i] = b[i];
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].a >> a[i].b;
    sort(a + 1, a + n + 1, cmpb);
    for(int i = 1; i <= n; i++) {
        qs[i] = qs[i - 1] + a[i].a;
    }
    mergeSort(1, n);
    cout << ans << "\n";
}

int main() {
    setIO();
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
6
2 1 7 6 9 3 18 4 3 2 5 5

4
1 4 3 2 2 3 7 1
*/