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

const int N = 2e6 + 10;
const int M = 2e5 + 10;

int a[N];

stack <int> st;

void solve() {
    int n, mx = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int l = 0, r = mx, tmp;
    while(l < r){
        int mid = l + (r - l) / 2;
        bool ch = true;
        for(int i = 0; i < n; i++){
            if(mid >= a[i])
                continue;
            if(st.empty()){
                st.push(a[i]);
                continue;
            }
            int top = st.top();
            st.pop();
            if(top != a[i]){
                ch = false;
                break;
            }
        }
        if(ch)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << "\n";
}

int main() {
    setIO();
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
6
3
3
2
5
5
2

6
3
5
2
2
5
3
*/