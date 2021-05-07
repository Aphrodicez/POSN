/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Heap
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

struct A{
    int idx, val;
    bool operator < (const A &o) const{
        if(val != o.val)
            return val > o.val;
        return idx < o.idx;
    }
};

priority_queue <A> he;

const int N = 5e5 + 10;

int a[N];

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    he.push({1, a[1]});
    while(!he.empty()){
        int idx = he.top().idx, val = he.top().val;
        he.pop();
        while(!he.empty() && he.top().idx <= idx)
            he.pop();
        for(int i = idx + 1; i <= min(n, idx + k); i++){
            if(i == n){
                cout << val + a[n] << "\n";
                exit(0);
            }
            he.push({i, val + a[i]});
        }
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
10
4
2 1 4 3 2 1 5 1 2 3
*/