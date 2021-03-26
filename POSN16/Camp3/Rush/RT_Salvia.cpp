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

string s;

int a[30], alp[27], n, cnt;

void permu(int state, int nowbit){
    if(state >= n){
        if(nowbit == (1<<26) - 1)
            cnt++;
        return ;
    }
    permu(state+1, nowbit | a[state]);
    permu(state+1, nowbit);
    return;
}

int main(){
    setIO();
    int q, i;
    cin >> q;
    while(q--){
        cin >> n;     
        cnt = 0;
        memset(a, 0, sizeof a);
        for(int i = 0; i < n; i++){
            cin >> s;
            for(int j = 0; j < s.size(); j++){
                a[i] |= (1 << (s[j] - 'a'));
            }
        }
        permu(0, 0);
        cout << cnt << "\n";
    }
    return 0;
}
/*
2
9
the
quick
brown
fox
jumps
over
a
lazy
dog
3
abcdefghijklmnopqrstuvwx
abcdefghijklmnopqrstuvwxy
abcdefghijklmnopqrstuvwxyz
*/