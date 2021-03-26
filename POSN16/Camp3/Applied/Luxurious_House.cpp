/*
    TASK    : 0
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct A{
    ll day, val;
    bool operator < (const A& o) const{
        if(val!=o.val)
            return val < o.val;
        return day < o.day;
    }
};

struct B{
    ll day, val;
    bool operator < (const B& o) const{
        return day < o.day;
    }
};

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

vector <B> vec;

priority_queue <A> he;

int main(){
    setIO();
    ll day, val, i, j, n, mxday = 0, sum = 0, cnt = 0;
    cin >> n;
    for(i=1; i<=n; i++){
        cin >> day >> val;
        vec.push_back({day, val});
        mxday = max(day, mxday); 
    }
    sort(vec.begin(), vec.end());
    j = vec.size() - 1;
    for(i=mxday; i>=1; i--){
        while(j >= 0 && vec[j].day >= i){
            he.push({vec[j].day, vec[j].val});
            j--;
        }
        if(!he.empty()){
            sum += he.top().val;
            he.pop();
            cnt++;
        }
    }
    cout << sum << "\n" << cnt;
    return 0;
}
/*
4
1 17
5 15
2 10
2 11
*/