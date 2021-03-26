#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int check(string s){
    if(mp[s])
        return mp[s];
    return -1;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int q, ans;
    string s, ss;

    mp["M"] = 1000, mp["CM"] = 900, mp["D"] = 500, mp["CD"] = 400;
    mp["C"] = 100, mp["XC"] = 90, mp["L"] = 50, mp["XL"] = 40;
    mp["X"] = 10, mp["IX"] = 9, mp["V"] = 5, mp["IV"] = 4;
    mp["I"] = 1;

    cin >> q;

    while(q--){
        ans = 0;
        cin >> s;
        for(int i = 0; i < s.size(); i++){
            if(i < s.size() - 1){
                ss = "";
                ss += s[i];
                ss += s[i + 1];
                if(check(ss) != -1){
                    ans += check(ss);
                    //cout << ss << " " << check(ss) << "\n";
                    i++;
                    continue;
                }
            }
            ss = "";
            ss += s[i];
            ans += check(ss);
        }
        cout << ans << "\n";
    }

    return 0;
}
/*
3
DCCXXVI
XLIX
MMCDLXXXIX
*/