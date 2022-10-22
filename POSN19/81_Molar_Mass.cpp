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
            if(isalpha(s[i])) {
                st.push(mp[s[i]]);
            }
            else if(isdigit(s[i])) {
                int top = st.top();
                st.pop();
                st.push(top * (s[i] - '0'));
            }
            else if(s[i] == '(') {
                st.push(-1);
            }
            else if(s[i] == ')') {
                int sum = 0;
                while(!st.empty()) {
                    int top = st.top();
                    st.pop();
                    if(top == -1)
                        break;
                    sum += top;
                }
                st.push(sum);
            }
        }
        int ans = 0;
        while(!st.empty()) {
            int top = st.top();
            ans += top;
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