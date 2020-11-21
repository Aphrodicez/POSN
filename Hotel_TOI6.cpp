/*
    TASK    : Hotel_TOI6
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

int n, ans;

int main(){
    setIO();
    cin >> n;

    if(n>=15)
        ans += 3000*(n/15), n %= 15;
    if(n>=9)
        ans += 3000, n -= 15;
    if(n>=4)
        n -= 5, ans += 1500;
    if(n>=2)
        n -= 2, ans += 800;
    if(n>=1)
        n -= 1, ans += 500;

    cout << ans;
    return 0;
}
