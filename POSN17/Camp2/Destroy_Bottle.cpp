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

struct HEAP{
    int idx, val;
    bool operator < (const HEAP &o) const{
        return val < o.val;
    }
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

int mark[N];

priority_queue <HEAP> he;

void solve(int markk) {
    int ans = 0, press;
    scanf("%d", &press);
    while(!he.empty()){
        int idx = he.top().idx;
        int val = he.top().val;
        if(val <= press)
            break;
        he.pop();
        if(mark[idx] && mark[idx] != markk)
            continue;
        for(int i = idx - 1; i <= idx + 1; i++){
            if(mark[i])
                continue;
            mark[i] = markk;
            ans++;
        }
    }
    printf("%d\n", ans);
}

int main() {    
    int n, q, val;
    scanf("%d %d", &n, &q);
    mark[0] = mark[n + 1] = 1;
    for(int i = 1; i <= n; i++){
        scanf("%d", &val);
        he.push({i, val});
    }
    for(int i = 1; i <= q; i++)
        solve(i);
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
7 4
3
1
4
6
7
3
5
5
4
6
2
*/