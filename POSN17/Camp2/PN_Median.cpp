/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Double Heap
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

struct A{
    double val;
    bool operator < (const A &o) const{
        return val > o.val;
    }
};

priority_queue <double> lHeap;

priority_queue <A> rHeap;

void solve(){
    int n;
    scanf("%d", &n);
    double num, suml, sumr, ans;
    for(int i = 1; i <= n; i++){
        scanf("%lf", &num);
        if(rHeap.size() < lHeap.size()){
            lHeap.push({num});
            rHeap.push({lHeap.top()});
            lHeap.pop();
        }
        else if(lHeap.size() < rHeap.size()){
            rHeap.push({num});
            lHeap.push({rHeap.top().val});
            rHeap.pop();
        }
        else{
            rHeap.push({num});
            lHeap.push({rHeap.top().val});
            rHeap.pop();
        }
        suml = sumr = 0;
        if(!lHeap.empty())
            suml = lHeap.top();
        if(!rHeap.empty())
            sumr = rHeap.top().val;
        if(i % 2){
            if(lHeap.size() > rHeap.size())
                ans = lHeap.top();
            else
                ans = rHeap.top().val;
        }
        else{
            ans = (suml + sumr) / 2;
        }
        printf("%.1lf\n", ans);
    }
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
10
1 4 2 5 2 3 1 6 3 4
*/