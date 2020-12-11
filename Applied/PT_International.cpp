/*
    TASK    : PT_International
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
    int idx, cty;
    bool operator < (const A& o) const{
        return idx < o.idx;
    }
};

A a[50010];

map <int, int> mp;

int main(){
    setIO();
    int n, q, l, cnt, mn, ctylen;
    cin >> q;
    while(q--){
        cin >> n;
        mp.clear();
        for(int i=1; i<=n; i++){
            cin >> a[i].idx >> a[i].cty;
            mp[a[i].cty]++;
        }
        ctylen = mp.size();
        mp.clear();
        sort(a + 1, a + 1 + n);
        l = 1, cnt = 0, mn = 1e9;
        for(int r = 1; r <= n; r++){
            if(!mp[a[r].cty])
                cnt++;
            mp[a[r].cty]++;
            while(cnt == ctylen){
                mn =  min(mn, a[r].idx - a[l].idx + 1);
                mp[a[l].cty]--;
                if(!mp[a[l].cty])
                    cnt--;
                l++;
            }
        }
        cout << mn << "\n";
    }
    return 0;
}
/*
1
6
20 1
15 9
16 1
5 1
12 5
10 1
*/