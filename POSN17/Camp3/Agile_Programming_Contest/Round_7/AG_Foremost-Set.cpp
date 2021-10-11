/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Set
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
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

const int MaxN = 2e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

long long a[MaxN], sorted[MaxN];

unordered_map <long long, long long> mp;

multiset <long long> LeftHS, RightHS;

long long sumLeft = 0, sumRight = 0;

void addSum(long long valLeft, long long valRight) {
    sumLeft += valLeft;
    sumRight += valRight;
}

void balanceMedian() {
    while((long long)RightHS.size() - (long long)LeftHS.size() > 1) {
        auto it = RightHS.begin();
        addSum(*it, -*it);
        LeftHS.insert(*it);
        RightHS.erase(it);
    }
    while((long long)LeftHS.size() - (long long)RightHS.size() > 0) {
        auto it = LeftHS.end();
        it--;
        addSum(-*it, *it);
        RightHS.insert(*it);
        LeftHS.erase(it);
    }
}

void addValue(long long val) {
    RightHS.insert(val);
    addSum(0, val);

    auto it = RightHS.begin();
    addSum(*it, -*it);
    LeftHS.insert(*it);
    RightHS.erase(it);
    
    it = LeftHS.end();
    it--;
    addSum(-*it, *it);
    RightHS.insert(*it);
    LeftHS.erase(it);

    balanceMedian();
}

void removeValue(long long val) {
    if(val < *RightHS.begin()) {
        auto it = LeftHS.find(val);
        addSum(-*it, 0);
        LeftHS.erase(it);
    }
    else {
        auto it = RightHS.find(val);
        addSum(0, -*it);
        RightHS.erase(it);
    }
    balanceMedian();
}

void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k - 1; i++) { 
        cin >> a[i];
        addValue(a[i]);
    }
    for(int i = k; i <= n; i++) {
        if(i - k > 0) {
            removeValue(a[i - k]);
        }
        cin >> a[i];
        addValue(a[i]);
        long long ansLeft = 1e18, ansRight = 1e18;
        if(LeftHS.size()) {
            long long leftMed = *LeftHS.rbegin();
            ansLeft = (leftMed * LeftHS.size() - sumLeft) + (sumRight - leftMed * RightHS.size());
        }
        long long rightMed = *RightHS.begin();
        ansRight = (rightMed * LeftHS.size() - sumLeft) + (sumRight - rightMed * RightHS.size());
        cout << min(ansLeft, ansRight) << " ";
    }
}

int main() {
    setIO();
    int q = 1;
    
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

/*
8 3
2 4 3 5 8 1 2 1
*/