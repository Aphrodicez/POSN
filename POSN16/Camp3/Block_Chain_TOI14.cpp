/*
    TASK    : Block_Chain_TOI14
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair <int, int>

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int t, q, i, j, n, u, v;

vector <pii> g;

map<vector <pii>, int> mp;

int main(){
    setIO();
    cin >> t >> q;
    for(j=1; j<=t; j++){
        cin >> n;
        g.clear();
        for(i=1; i<n; i++){
            cin >> u >> v;
            g.push_back({min(u, v), max(u,v)});
        }
        sort(g.begin(), g.end());
        mp[g]++;
    }
    for(j=1; j<=q; j++){
        cin >> n;
        g.clear();
        for(i=1; i<n; i++){
            cin >> u >> v;
            g.push_back({min(u, v), max(u, v)});
        }
        sort(g.begin(), g.end());
        cout << mp[g] << "\n";
    }
    return 0;
}
/*
3 2
10
1 2
6 4
2 5
3 5
8 6
2 7
5 8
8 9
4 10
6
1 4
2 4
4 3
5 4
5 6
10
1 2
2 7
2 5
3 5
8 6
4 6
5 8
8 9
4 10
6
1 4
2 4
4 3
5 4
1 6
10
1 2
2 7
2 5
3 5
8 6
4 6
5 8
8 9
4 10
*/
