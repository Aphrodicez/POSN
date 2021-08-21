/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Divide and Conquer
    Status	: Accepted
    Created	: 19 August 2021 [12:12]
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

int Quadrant[] = {0, 1, 2, 3};

const int di[] = {-1, -1, 1, 1};
const int dj[] = {-1, 1, -1, 1};

vector <tuple<int, int, int>> ans;

void divide(int n, int midi, int midj, int holei, int holej) {
    int Qi = holei >= midi;
    int Qj = holej >= midj;
    int idx = Qi * 2 + Qj;
    ans.push_back(make_tuple(Quadrant[idx], midj - 1, midi - 1));
    if(n == 2)
        return ;
    for(int k = 0; k < 4; k++) {
        int nextholei = midi + min(di[k], 0);
        int nextholej = midj + min(dj[k], 0);
        if(idx == k) {
            nextholei = holei;
            nextholej = holej;
        }
        divide(n / 2, midi + (n / 4) * di[k], midj + (n / 4) * dj[k], nextholei, nextholej);
    }
}

void solve() {
    int n, i, j;
    cin >> n >> j >> i;
    divide(n, n / 2, n / 2, i, j);
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for(auto x : ans) {
        cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << "\n";
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
4 1 2
2 0 1
*/