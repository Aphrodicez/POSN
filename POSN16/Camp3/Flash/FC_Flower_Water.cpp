/*
    TASK    : 0
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

#define fi(a, b) for(int i=a; i<=b; i++)

#define pb push_back

struct A{
    int idx, val;
    bool operator < (const A& o) const{
        return val < o.val;
    }
};

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int p[100010];

int fin(int i){
    if(p[i]==i)
        return i;
    return p[i] = fin(p[i]);
}

vector <A> x, y;

int main(){
    setIO();
    int q, n, nowx, nowy, ru, rv;
    unordered_set <int> mset;
    cin >> q;
    while(q--){
        mset.clear();
        x.clear();
        y.clear();
        int ans = 0;
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> nowx >> nowy;
            x.pb({i, nowx});
            y.pb({i, nowy});
            p[i] = i;   
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        for(int i=0; i < n - 1; i++){
            if(x[i].val == x[i+1].val){
                ru = fin(x[i].idx);
                rv = fin(x[i+1].idx);
                if(ru==rv)
                    continue;
                p[ru] = rv;
            }
        }
        for(int i=0; i < n - 1; i++){
            if(y[i].val == y[i+1].val){
                ru = fin(y[i].idx);
                rv = fin(y[i+1].idx);
                if(ru==rv)
                    continue;
                p[ru] = rv;
            }
        }
        for(int i = 1; i <= n; i++){
            ru = fin(i);
            mset.insert(p[i]);
        }
        if(mset.size()%2!=0)
            ans++;
        ans += mset.size() / 2;
        cout << ans << "\n";
    }
    return 0;
}
/*
2
4
1 2
2 1
2 3
3 2
9
2 1
1 2
2 3
2 5
1 6
2 7
4 3
5 4
4 5
*/