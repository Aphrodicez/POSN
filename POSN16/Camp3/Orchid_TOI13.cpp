/*
    TASK    : Orchid_TOI13
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

int n, i, num, idx, cnt;

int a[1000010];

int main(){
    setIO();
    cin >> n;
    for(i=0; i<n; i++){
        cin >> num;
        idx = upper_bound(a, a+cnt, num) - a;
        if(cnt==idx)
            cnt++;
        a[idx] = num;
    }
    cout << n - cnt;
    return 0;
}
