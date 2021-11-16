/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Brute Force + Depth First Search
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

const int MaxN = 1e2 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

unordered_map <char, int> operators;
unordered_map <char, int> parenthesis;

char s[MaxN];
queue <pair <int, int>> qu;
map <pair <int, int>, vector <pair <int, int>>> g;
stack <int> query;

void gen_edge(int l, int r) {
    if(l >= r)
        return ;
    if(s[l] == '(' && s[r] == ')') {
        int depth = 0;
        for(int i = l + 1; i <= r - 1; i++) {
            depth += parenthesis[s[i]];
            if(depth < 0)
                break;
        }
        if(!depth) {
            g[make_pair(l, r)].emplace_back(l + 1, r - 1);
            return ;
        }
    }
    int depth = 0;
    int mn = 3;
    for(int i = l; i <= r; i++) {
        depth += parenthesis[s[i]];
        if(!depth && operators[s[i]])
            mn = min(mn, operators[s[i]]);
    }
    for(int i = l; i <= r;) {
        int j = i;
        int depth = 0;
        for(; j <= r; j++) {
            depth += parenthesis[s[j]];
            if(!depth && (operators[s[j]] == mn))
                break;
        }
        g[make_pair(l, r)].emplace_back(i, j - 1);
        i = j + 1;
    }
}

void solve() {
    operators['+'] = 1, operators['*'] = 2, operators['^'] = 3;
    parenthesis['('] = 1, parenthesis[')'] = -1;
    scanf(" %s", s);
    int len = strlen(s);
    qu.push({0, len - 1});
    while(!qu.empty()) {
        int l = qu.front().first;
        int r = qu.front().second;
        qu.pop();
        gen_edge(l, r);
        for(auto x : g[make_pair(l, r)]) {
            qu.push(x);
        }
        if(!g[make_pair(l, r)].size())
            g[make_pair(l, r)].emplace_back(l, r);
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        while(!query.empty())
            query.pop();
        pair <int, int> now = make_pair (0, len - 1);
        int idx = 1;
        bool ch = true;
        while(1) {
            scanf("%d", &idx);
            if(!idx)
                break;
            query.push(idx);
            if(!ch)
                continue;
            if(idx > (int)g[now].size()) {
                ch = false;
                continue;
            }
            now = g[now][idx - 1];
        }
        int sz = query.size();
        while(!query.empty()) {
            printf("op(%d,", query.top());
            query.pop();
        }
        printf("p");
        for(int i = 1; i <= sz; i++) {
            printf(")");
        }
        printf("=");
        if(!ch) {
            printf("null\n");
            continue;
        }
        for(int i = now.first; i <= now.second; i++)
            printf("%c", s[i]);
        printf("\n");
    }
}

int main() {
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
a*b^c+d*e^f
3
1 1 0
1 2 0
1 2 2 0

(x+y)+z
5
1 0
1 1 0
1 1 1 0
1 1 2 0
3 0

a*(z+b)*z+d^z+c*(z+a)+e+f+g^(d+z)
10
6 1 0
6 2 0
7 1 0
1 2 1 0
1 2 2 0
1 2 1 2 1 0
3 2 1 0
6 2 1 0
6 2 1 2 0
6 2 1 1 1 0

((b*c)+a)+d

(a+b)*(c+d)
*/