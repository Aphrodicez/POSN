/*
    TASK    : Barrier_TOI12
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

struct A{
    ll idx, qs;
};

deque <A> deq;

ll n, w, i, l, lqs, mx = -1e12, range;

ll qs[6000010];

int main(){
    setIO();
    cin >> n >> w;
    deq.push_back({0, 0});
    for(i=1; i<=n; i++){
        cin >> qs[i];
        qs[i] += qs[i-1];
        while(!deq.empty() && deq.back().qs > qs[i])
            deq.pop_back();
        while(!deq.empty() && deq.front().idx + w < i)
            deq.pop_front();
        if(deq.empty())
            l = 0, lqs = 0;
        else
            l = deq.front().idx, lqs = deq.front().qs;
        if(qs[i] - lqs > mx){
            mx = qs[i] - lqs;
            range = i - l;
        }
        else if(qs[i] - lqs == mx){
            range = min(range, i - l);
        }
        deq.push_back({i, qs[i]});
    }
    mx = max(mx, 0ll);
    cout << mx << "\n";
    if(!mx)
        range = 0;
    cout << range;

    return 0;
}
/*
7 4
3
2
5
1
4
-7
10
*/
