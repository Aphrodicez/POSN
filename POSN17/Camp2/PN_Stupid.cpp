/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Binary Search
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

using i64 = long long;

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void solve() {
    i64 sum, product;
    cin >> sum >> product;
    i64 l = 1, r = sum;
    while(l <= r){
        i64 mid = l + (r - l) / 2;
        if(mid * (sum - mid) > product || ((sum - mid) * mid / mid) != (sum - mid))
            r = mid - 1;
        else if(mid * (sum - mid) < product)
            l = mid + 1;
        else{
            cout << mid << " " << sum - mid << "\n";
            return ;
        }
    }
    cout << "No answer\n";
}

int main() {
    setIO();
    i64 q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
4
8 16
2022 1022117
10 20
2000000000 1000000000000000000
*/