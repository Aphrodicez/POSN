/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Stack
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

struct A{
    char type; // '(' or ')'
    int level;
};

stack <A> st;

int anslvl[110];

void solve(){
    int n, level = 0, ans = 0, cntlvl = 0;
    char c;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == '('){
            st.push({c, 0});
            continue;
        }
        level = 0;
        while(1){
            A top = st.top();
            st.pop();
            if(top.type == '(')
                break;
            level = max(level, top.level);
        }
        anslvl[level + 1]++;
        st.push({')', level + 1});
    }
    for(int i = 1; i <= 100; i++){
        if(!anslvl[i])
            break;
        ans += anslvl[i];
        cntlvl++;
    }
    cout << ans << "\n" << cntlvl << "\n";
    for(int i = 1; i <= cntlvl; i++){
        cout << anslvl[i] << " ";
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
16
((())(()((()))))
*/