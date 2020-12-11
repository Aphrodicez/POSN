/*
    TASK    : 0
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string s, a;
string pre, star, suf;

int main(){
    setIO();
    int q, len, i = 0;
    cin >> q;

    cin >> s;

    len = s.size();

    for(; i < len; i++){
        if(s[i] == '*')
            break;
        pre += s[i];
    }
    star += '*';
    i++;
    for(; i < len; i++){
        suf += s[i];
    }
    while(q--){
        cin >> a;
        if(s.size() - 1 > a.size()){
            cout << "No\n";
            continue;
        }
        int i = 0, j = 0, k = 0, cnt1 = 0, cnt2 = 0;
        for(; i<s.size() && i < a.size(); i++){
            if(s[i]==a[i]){
                cnt1++;
            }
            else
                break;
        }
        j = s.size()-1, k = a.size()-1;
        for(; j >= 0 && k >= 0; j--, k--){
            if(s[j]==a[k])
                cnt2++;
            else
                break;
        }
        if(cnt1==pre.size() && cnt2==suf.size())
            cout << "Yes\n";
        else
        {
            cout << "No\n";
        }
        
        //cout << cnt1 << " " << cnt2 << "\n";
    }
    return 0;
}
/*
5
p*t
peat
peatt
mrpeatt
peatty
pot
*/