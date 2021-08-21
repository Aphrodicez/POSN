/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Mergesort [Inversion Count]
    Status	: Accepted
    Created	: 21 August 2021 [11:42]
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

struct GRAPH {
    
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int a[N], b[N];

i64 ans = 0;

void mergeSort(int l, int r) {
    if(l >= r)
        return ;
    int mid = l + (r - l) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r) {
        if(a[i] <= a[j]) {
            b[k] = a[i];
            i++;
            k++;
        }
        else {
            b[k] = a[j];
            ans += mid - i + 1;
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
        cin >> a[i];
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
5
2 4 1 3 5
*/