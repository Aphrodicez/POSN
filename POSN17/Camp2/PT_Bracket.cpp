/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: 
    Status	: 
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

const int N = 5e4 + 10;

struct A{
    int idx, sum, valid;
    bool operator < (const A &o) const{
        if(idx != o.idx)
            return idx > o.idx;
        return sum > o.sum;
    }
};

priority_queue <A> he;

int a[N], b[N];

void solve(){
    while(!he.empty())
        he.pop();
    //int m = 0;
    vector <int> vec;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '?')
            vec.push_back(i);
    for(int i : vec){
        cin >> a[i] >> b[i];
    }

    if(s[0] == '(')
        he.push({0, 0, 1});
    if(s[0] == ')' || (s.size() % 2 == 1)){
        cout << -1 << "\n";
        return ;
    }
    if(s[0] == '?')
        he.push({0, a[0], 1});

    for(int i = 1; i < s.size(); i++){
        while(!he.empty() && he.top().idx != i){
            //cout << he.top().idx << " " << he.top().sum << " " << he.top().valid << "\n";
            A tmp = he.top();
            he.pop();
            if(s[i] == '('){
                if(tmp.valid + 1 <= s.size() - i)
                    he.push({i, tmp.sum, tmp.valid + 1});
            }
            if(s[i] == ')'){
                if(tmp.valid - 1 >= 0)
                    he.push({i, tmp.sum, tmp.valid - 1});
            }
            if(s[i] == '?'){
                if(tmp.valid + 1 <= s.size() - i)
                    he.push({i, tmp.sum + a[i], tmp.valid + 1});
                if(tmp.valid - 1 >= 0)
                    he.push({i, tmp.sum + b[i], tmp.valid - 1});
            }
        }
        if(he.empty())
            break;
    }
    /*while(1){
        if( (he.top().idx == s.size() - 1) && (he.top().valid == 0) )
            break;
        he.pop();
    }
    */
    if(he.empty())
        cout << "-1";
    else
        cout << he.top().sum << "\n";
}

int main() {
    setIO();
    int q;
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