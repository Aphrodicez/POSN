/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Automata
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 2e1 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

string s, ss;
unordered_map <string, pair <int, int>> adj[5];

void solve() {
    adj[1]["00"] = make_pair(1, 0), adj[1]["11"] = make_pair(2, 1);
    adj[2]["10"] = make_pair(3, 0), adj[2]["01"] = make_pair(4, 1);
    adj[3]["11"] = make_pair(1, 0), adj[3]["00"] = make_pair(2, 1);
    adj[4]["01"] = make_pair(3, 0), adj[4]["10"] = make_pair(4, 1);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ss;
        s += ss;
    }
    int sz = s.size();
    int u = 1, sum = 0, cnt = 0;
    pair <int, int> next;
    for(int j = 0; j + 1 < sz; j += 2) {
        next = adj[u][s.substr(j, 2)];
        if(!next.first)
            continue;
        u = next.first;
        if(cnt == 8) {
            if(isupper(sum))
                cout << char(sum);
            cnt = 0;
            sum = 0;
        }
        cnt++;
        sum = (sum << 1) | next.second;
    }
    if(cnt == 8) {
        if(isupper(sum))
            cout << char(sum);
        cnt = 0;
        sum = 0;
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
3
0011100010000110
0100100010001000
1011

4
0011101100000011
1000101100001110
1111101100001101
0100101100111011
*/