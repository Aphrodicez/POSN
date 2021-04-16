#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int k, delta, up = 0, down = 0, leftt = 0, rightt = 0, ans;
    string s;
    cin >> s;
    cin >> k;
    for(char c: s){
        if(c == 'N')
            up++;
        else if(c == 'E')
            rightt++;
        else if(c == 'S')
            down++;
        else
            leftt++;
    }
    if(up >= down){
        delta = min(k, down);
        down -= delta;
        k -= delta;
    }
    else{
        delta = min(k, up);
        up -= delta;
        k -= delta;
    }
    if(rightt >= leftt){
        delta = min(k, leftt);
        leftt -= delta;
        k -= delta;
    }
    else{
        delta = min(k, rightt);
        rightt -= delta;
        k -= delta;
    }
    ans = abs(up - down) + abs(rightt - leftt) - k;
    cout << ans * 2;
    return 0;
}
/*
NNEESW
2
NE
2
NWSSSSE
1
*/