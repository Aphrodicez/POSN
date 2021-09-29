/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Topological Sort
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

const int MaxN = 1e2 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

string s[MaxN];

unordered_set <int> inDictionary; 

unordered_set <int> g[30];

int deg[30];

queue <int> qu;

void solve() {
    int n;
    cin >> n;
    cin >> s[1];
    for(char x : s[1]) {
        inDictionary.insert(x - 'a');
    }
    for(int i = 2; i <= n; i++) {
        cin >> s[i];
        bool ch = false;
        for(int j = 0; j < (int)s[i].size(); j++) {
            inDictionary.insert(s[i][j] - 'a');
            if(ch)
                continue;
            if(j >= (int)s[i - 1].size())
                continue;
            if(s[i - 1][j] != s[i][j]) {
                g[s[i - 1][j] - 'a'].insert(s[i][j] - 'a');
                ch = true;
            }
        }
    }
    for(int u : inDictionary) {
        for(int v : g[u]) {
            deg[v]++;
        }
    }
    for(int u : inDictionary) {
        if(!deg[u])
            qu.push(u);
    }
    if(qu.size() < 1) {
        cout << "!";
        return ;
    }
    bool ch = false;
    string ans;
    while(!qu.empty()) {
        if(qu.size() > 1)
            ch = true;
        int u = qu.front();
        qu.pop();
        ans += char(u + 'a');
        for(int x : g[u]) {
            deg[x]--;
            if(!deg[x])
                qu.push(x);
        }
    }
    if((int)ans.size() != (int)inDictionary.size()) {
        cout << "!";
        return ;
    }
    if(ch) {
        cout << "?";
        return ;
    }
    cout << ans;
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
5
ula
uka
klua
kula
al

3
jaja
baba
baja

3
man
tan
fan
*/