#include <bits/stdc++.h>
using namespace std;

struct A{
    int x, y;
};

A ans;

map<char, A> mp;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    string s;

    cin >> s;

    mp['N'] = {0, 1}, mp['E'] = {1, 0}, mp['S'] = {0, -1}, mp['W'] = {-1, 0};

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'Z'){
            ans = {0, 0};
        }
        else{
            ans.x += mp[s[i]].x;
            ans.y += mp[s[i]].y;
        }
    }

    cout << ans.x << " " << ans.y << "\n";

    return 0;
}
/*
NNEESWZEE
NNEESW
NWSSSSE
*/