/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: 
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

stack <pair <int, int>> st;

void solve() {
    int n, q;
    cin >> n >> q;
    int num;
    vector <int> vec;
    for(int i = 1; i <= n; i++) {
        cin >> num;
        while (!st.empty() && st.top().first >= num)
            st.pop();
        int cost = 0;
        if(st.empty())
            st.push({num, cost});
        else {
            cost = max(num - st.top().first, st.top().second);
            st.push(make_pair(num, cost));
        }
        vec.push_back(cost);
    }
    sort(vec.begin(), vec.end());
    while (q--) {
        cin >> num;
        cout << n - (upper_bound(vec.begin(), vec.end(), num) - vec.begin()) << "\n";
    }
    
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
5 2
1
3
4
2
3
2
1
*/