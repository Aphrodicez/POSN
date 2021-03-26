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

int a[500010];

int n, m, val, l, r, idx, sum, i;

string s;

int main(){
    setIO();
    cin >> n >> m;
    while(m--){
        cin >> s;
        sum = 0;
        if(s=="Yoyo"){
            cin >> val >> l >> r;
            if(l > r)
                swap(l, r);
            for(i=l; i <= n; i += i & (-i)){
                a[i] += val;
            }
            for(i=r+1; i<=n; i += i & (-i)){
                a[i] -= val;
            }
        }
        else{
            cin >> idx;
            for(i=idx; i > 0; i -= i & (-i)){
                sum += a[i];
            }
            cout << sum << "\n";
        }
    }
    return 0;
}
/*
7 6
Yoyo 10 4 7
Yoyo 15 1 5
Ask 4
Yoyo 5 3 6
Ask 5
Ask 7
*/
