/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Infix To Propostfix
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

const int N = 1e5 + 10;
const int M = 2e5 + 10;

stack <int> stnum;
stack <int> stopr;

void solve() {
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(isalpha(s[i]))
            stnum.push(20);
        else{
            if(s[i] == '[')
                stopr.push(-1);
            else if(s[i] == ']'){
                while (!stopr.empty()){
                    int opr = stopr.top();
                    stopr.pop();
                    if(opr == -1)
                        break;
                    int v = stnum.top();
                    stnum.pop();
                    int u = stnum.top();
                    stnum.pop();
                    int sum = ((u + v) * (100 + (1 << (opr + 1) )) / 100);
                    stnum.push(sum);
                }
            }
            else{
                while (!stopr.empty() && stopr.top() >= (s[i] - '0')) {
                    int opr = stopr.top();                    
                    if(opr == -1)
                        break;
                    stopr.pop();
                    int v = stnum.top();
                    stnum.pop();
                    int u = stnum.top();
                    stnum.pop();
                    int sum = ((u + v) * (100 + (1 << (opr + 1) )) / 100);
                    stnum.push(sum);
                }
                stopr.push(s[i] - '0');
            }
        }
    }
    while(!stopr.empty()){
        int opr = stopr.top();
        stopr.pop();
        int v = stnum.top();
        stnum.pop();
        int u = stnum.top();
        stnum.pop();
        int sum = ((u + v) * (100 + (1 << (opr + 1) )) / 100);
        stnum.push(sum);
    }
    cout << stnum.top() << "\n";
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
*/