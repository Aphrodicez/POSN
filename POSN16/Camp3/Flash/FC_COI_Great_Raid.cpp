/*
    TASK    : 0
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

struct A{
    int u, v, w;
    bool operator < (const A& o) const{
        return w > o.w;
    }
};

int a[100010];

priority_queue <A> he;

int p[100010];

int fin(int i){
    if(p[i]==i)
        return i;
    return p[i] = fin(p[i]);
}

int main(){
    setIO();
    int n, m, u, v, w, ru, rv, sum = 0;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        p[i] = i;
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> u >> v;
        he.push({u, v, a[u] + a[v]});
    }
    while(!he.empty()){
        u = he.top().u;
        v = he.top().v;
        w = he.top().w;
        ru = fin(u);
        rv = fin(v);
        he.pop();
        if(ru==rv)
            continue;
        p[ru] = rv;
        sum += w;
    }
    cout << sum;
    return 0;
}
/*
10
1 2 1 2 3 1 2 1 2 1
15
5 1
10 8
5 4
7 10
10 9
2 5
8 4
6 10
7 8
8 5
3 8
6 8
3 1
2 3
3 5
*/