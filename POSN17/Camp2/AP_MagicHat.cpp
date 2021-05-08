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

struct HAT{
    int w, val, life, idx;
    bool operator < (const HAT &o) const{
        if(w != o.w)
            return w > o.w;
        if(val != o.val)
            return val < o.val;
        return life > o.life;
    }
};

struct TIME{
    int w, val, life, idx;
    bool operator < (const TIME &o) const{
        return life > o.life;
    }
};

const int N = 2e5 + 10;
const int M = 2e5 + 10;

int mark[N];

priority_queue <HAT> hat;
priority_queue <TIME> timee;

void solve() {
    int n, m, opr, w, val, life, neww, type;
    cin >> n >> m;
    n += m;
    for(int i = 0; i < n; i++){
        cin >> opr;
        if(opr == 1){
            cin >> type;
            if(type == 1){
                cin >> w >> val;
                hat.push({w, val, (int)2e5 + 10, i});
            }
            if(type == 2){
                cin >> w >> val >> life;
                hat.push({w, val, life, i});
            }
            if(type == 3){
                cin >> w >> val >> life >> neww;
                hat.push({w, val, life, i});
                timee.push({neww, val, life, i});
            }
        }
        if(opr == 2){
            while(!hat.empty() && hat.top().life <= i)
                hat.pop();
            while(!hat.empty() && mark[hat.top().idx])
                hat.pop();
            while(!timee.empty() && timee.top().life <= i){
                TIME tmp = timee.top();
                timee.pop();
                if(mark[tmp.idx])
                    continue;
                hat.push({tmp.w, tmp.val, (int) 2e5 + 10, tmp.idx});
            }
            if(hat.empty()){
                cout << "0\n";
                continue;
            }
            cout << hat.top().val << "\n";
            mark[hat.top().idx] = 1;
            hat.pop();
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
5 4
1 1 10 20
1 2 30 10 3
2
2
1 3 40 20 7 5
1 1 30 30
1 2 25 50 7
2
2
*/