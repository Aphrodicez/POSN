/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Heap + Greedy Algorithm
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

priority_queue <int> pq;

void solve() {
    while(!pq.empty())
        pq.pop();
    string s;
    cin >> s;
    bool ch = true;
    int cnt = 0;
    i64 sum = 0;
    for(int i = 0; i < s.size(); i++) {
        if(!ch)
            continue;
        if(s[i] == '(') {
            cnt++;
        }
        else if(s[i] == ')') {
            cnt--;
        }
        else {
            int x, y;
            cin >> x >> y;
            if(!ch)
                continue;    
            sum += y;
            cnt--;
            pq.push(y - x);
        }
        if(cnt < 0) {
            if(pq.empty()) {
                ch = false;
                continue;
            }
            sum -= pq.top();
            pq.pop();
            cnt += 2;
        }
    }
    if(cnt != 0)
        ch = false;
    cout << (ch ? sum : -1) << "\n";
}

int main() {
    setIO();
    int q;
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
1
(??)
1 2
2 8
*/