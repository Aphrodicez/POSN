/*
    TASK    : Cannon_TOI11
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

int n, m, k, l, a[1000010], num, L, i, r, last, sum;

int main(){
    setIO();
    cin >> n >> m >> k >> L;
    for(i=0; i<n; i++){
        cin >> a[i];
    }
    while(k--){
        last = sum = 0;
        for(i=0; i<m; i++){
            cin >> num;
            l = num - L;
            r = num + L;
            l = max(last + 1, l);
            sum += upper_bound(a, a+n, r) - a;
            sum -= lower_bound(a, a+n, l) - a;
            last = max(last, r);
        }
        cout << sum << "\n";
    }
    return 0;
}
/*
3 2 5 100
100 300 500
200 1000
199 1000
200 600
1000 1001
200 400
*/
