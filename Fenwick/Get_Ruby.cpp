/*
    TASK    : Get_Ruby
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

int n, m, opr, i, a[750010], val, idx, l, r, sum;

string s;

int main(){
    setIO();


    cin >> n >> m;
    while(m--){
        cin >> s;
        sum = 0;
        if(s=="Bury"){
            cin >> val >> idx;
            for(i=idx; i<=n; i += i & (-i)){
                a[i] += val;
            }
        }
        if(s=="Find"){
            cin >> l >> r;
            for(i=r; i>0; i -= i & (-i)){
                sum += a[i];
            }
            for(i=l-1; i>0; i -= i & (-i)){
                sum -= a[i];
            }
            cout << sum << "\n";
        }
    }

    return 0;
}
/*
10 5
Bury 5 5
Bury 10 7
Find 3 7
Bury 20 8
Find 6 10
*/
