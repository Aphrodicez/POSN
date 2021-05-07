/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Stack Implementation
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

const int N = 1e5 + 10;

int a[N], dp[N];

stack <int> st;

void solve(){
    int n, q, num, mn, last;
    cin >> n >> q;
    cin >> a[1];
    st.push(1);
    for(int i = 2; i <= n; i++){
        cin >> a[i];
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if(st.empty())
            dp[i] = 0;
        else
            dp[i] = max(dp[st.top()], a[i] - a[st.top()]);
        st.push(i);
    }
    sort(dp + 1, dp + n + 1);
    while(q--){
        cin >> num;
        cout << n - (upper_bound(dp + 1, dp + n + 1, num) - dp - 1) << "\n";
    }
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
5 2
1
3
4
2
3
2
1
*/