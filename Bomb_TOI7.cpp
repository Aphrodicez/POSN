/*
    TASK    : Bomb_TOI7
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

struct A{
    int x, y;
    bool operator < (const A& o) const{
        if(x!=o.x)
            return x > o.x;
        return y < o.y;
    }
};

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int x, y, n, i, mx;

A a[1000010];

vector<pair<int, int>> vec;

int mark[1000010];

int main(){
    setIO();

    cin >> n;

    for(i=0; i<n; i++){
        cin >> a[i].x >> a[i].y;
    }

    sort(a, a+n);

    for(i=0; i<n; i++){
        mx = max(mx, a[i].y);
        if(a[i].y < mx)
            continue;
        vec.push_back({a[i].x, a[i].y});
    }
    sort(vec.begin(), vec.end());
    for(auto x: vec){
        cout << x.first << " " << x.second << "\n";
    }

    return 0;
}
/*
5
9 1
8 2
7 3
6 4
5 5
*/
/*
9
3 6
3 5
3 4
3 3
5 5
6 4
7 3
8 2
9 1
*/
