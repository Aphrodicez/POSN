/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Stack 
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

char s[110];

stack <int> st;

map <char, int> mp;

int main() {
    mp['H'] = 1;
    mp['C'] = 12;
    mp['O'] = 16;
    int q;
    scanf("%d", &q);
    while(q--) {
        scanf(" %s", s);
        int len = strlen(s);
        for(int i = 0; i < len; i++) {
            if(s[i] == '(') {
                st.push(-1);
                continue;
            }
            if(isdigit(s[i])) {
                int top = st.top();
                st.pop();
                st.push(top * (s[i] - '0'));
                continue;
            }
            if(s[i] == ')') {
                int sum = 0;
                while(!st.empty() && st.top() != -1) {
                    sum += st.top();
                    st.pop();
                }
                st.pop();
                st.push(sum);
                continue;
            }
            st.push(mp[s[i]]);
        }
        int ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
2
COOH
(C(H2O)2)3
*/