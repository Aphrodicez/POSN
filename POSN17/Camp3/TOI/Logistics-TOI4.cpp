/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Linked List
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

const int MaxN = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct NODE {
    char val;
    NODE *l, *r;
    NODE *createNode(char val) {
        NODE *tmp = new NODE;
        tmp->val = val;
        tmp->l = NULL;
        tmp->r = NULL;
        return tmp;
    }
    void addedge(NODE *u, NODE *v) {
        if(u->l != v && u->r != v) {
            if(u->l == NULL)
                u->l = v;
            else
                u->r = v;
        }
        if(v->l != u && v->r != u) {
            if(v->l == NULL)
                v->l = u;
            else
                v->r = u;
        }
    }
};

unordered_map <char, NODE*> mp;
unordered_map <char, bool> visited;
map <pair<char, char>, vector <double>> edge;

NODE node;

void solve() {
    int n;
    scanf("%d", &n);
    char u, v;
    double w;
    for(int i = 1; i <= n; i++) {
        scanf(" %c %c %lf", &u, &v, &w);
        if(!mp[u])
            mp[u] = node.createNode(u);
        if(!mp[v])
            mp[v] = node.createNode(v);
        node.addedge(mp[u], mp[v]);
        edge[minmax(u, v)].emplace_back(w);
    }
    NODE *now = mp['X'];
    while(now != NULL) {
        visited[now->val] = true;
        NODE *next = NULL;    
        if(now->l != NULL && !visited[now->l->val])
            next = now->l;
        else if(now->r != NULL && !visited[now->r->val])
            next = now->r;
        now = next;
    }
    if(!visited['Y']) {
        printf("broken\n");
        return ;
    }
    visited.clear();
    double ans = 0;
    now = mp['X'];
    while(now != NULL) {
        visited[now->val] = true;
        NODE *next = NULL;
        if(now->l != NULL && !visited[now->l->val])
            next = now->l;
        else if(now->r != NULL && !visited[now->r->val])
            next = now->r;
        if(now->val == 'Y')
            break;
        auto vec = edge[minmax(now->val, next->val)];
        sort(vec.begin(), vec.end());
        double w;
        int sz = vec.size();
        if(sz % 2) 
            w = vec[sz / 2];
        else
            w = (vec[sz / 2 - 1] + vec[sz / 2]) / 2;
        printf("%c %c %.1lf\n", now->val, next->val, w);
        ans += w;
        now = next;
    }
    printf("%.1lf\n", ans);
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
6
X a 1
a b 4
b a 1
b Y 3
b Y 2
Y b 6

3
X a 2
c b 3
b Y 3

5
q Y 3 
X a 1
a b 2
t b 4
q t 5
*/