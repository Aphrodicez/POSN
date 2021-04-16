#include <bits/stdc++.h>
using namespace std;

bool solve(string s){
    string rs;
    int sum = 0, num;
    for(int i = 0; i < s.size(); i++){
        num = s[i] - '0';
        for(int j = 1; j <= i; j++){
            num *= s[i] - '0';
        }
        sum += num;
    }
    reverse(s.begin(), s.end());
    while(sum > 0){
        rs += (sum % 10) + '0';
        sum /= 10;
    }
    //cout << rs << "\n";
    if(rs == s)
        return true;
    return false;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int q = 5;

    string s, ans;

    while(q--){
        cin >> s;
        if(solve(s))
            ans += 'Y';
        else
            ans += 'N';
    }

    cout << ans;

    return 0;
}
/*
*/