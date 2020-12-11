/*
    TASK    :
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
    int opr, val;
};

A a[300010];

map <int, int> mp;

int tree[300010];

vector <int> comp;

void upd(int idx, int val){
    while(idx <= 300003){
        tree[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx){
    int sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int main(){
    //setIO();
    int n, i;
    cin >> n;
    comp.push_back(0);
    for(i=1; i<=n; i++){
        cin >> a[i].opr >> a[i].val;
        if(a[i].opr==1)
            comp.push_back(a[i].val);
    }
    sort(comp.begin(), comp.end());
    for(int i = 1; i < comp.size(); i++)
        mp[comp[i]] = i;
    for(int i = 1; i<=n; i++){
        if(a[i].opr==1)
            upd(mp[a[i].val], 1);
        else
            cout << query(mp[a[i].val]) << "\n";
    }
    return 0;
}
/*
12
1 5
1 6
1 4
2 4
2 5
2 6
1 8
1 1
2 5
2 1
2 4
2 6
*/
