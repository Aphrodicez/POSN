/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Kruskal's MST
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

struct EDGES{
    int u, v, w;
    bool operator < (const EDGES & o) const{
        return w > o.w;
    }
};

struct SHOP{
    int w, price;
};

bool cmpshop(SHOP a, SHOP b){
    if(a.w != b.w)
        return a.w < b.w;
    return a.price > b.price;
}

const int N = 3e3 + 10;
const int M = 5e5 + 10;
const int P = 3e5 + 10;

int p[N];

vector <EDGES> g[N];

SHOP shop[P];

priority_queue <EDGES> mst;

int fr(int u){
    if(p[u] == u)
        return u;
    return p[u] = fr(p[u]);
}

void solve() {
    int n, m, u, v, w, used, q, ans = 0, edgeleft;
    scanf("%d %d", &n, &m);
    edgeleft = n - 1;
    for(int i = 1; i <= n - 1; i++)
        p[i] = i;
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d %d", &u, &v, &w, &used);
        if(used){
            int ru = fr(u);
            int rv = fr(v);
            if(ru == rv)
                continue;
            p[ru] = rv;
            edgeleft--;
            continue;
        }
        mst.push({u, v, w});
    }
    scanf("%d", &q);
    for(int i = 1; i <= q; i++){
        scanf("%d %d", &shop[i].w, &shop[i].price);
    }
    sort(shop + 1, shop + 1 + q, cmpshop);
    for(int i = q - 1; i >= 1; i--)
        shop[i].price = min(shop[i].price, shop[i + 1].price);
    while (!mst.empty()){
        if(!edgeleft)
            break;
        int u = mst.top().u;
        int v = mst.top().v;
        int w = mst.top().w;
        mst.pop();
        int ru = fr(u);
        int rv = fr(v);
        if(ru == rv)
            continue;
        int l = 1, r = q;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(shop[mid].w >= w)
                r = mid;
            else
                l = mid + 1;
        }        
        edgeleft--;
        p[ru] = rv;
        ans += shop[l].price; 
    }
    printf("%d", ans);
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}