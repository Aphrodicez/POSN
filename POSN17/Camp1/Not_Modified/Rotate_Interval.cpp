#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int q, n, k, i, j, c;
    string s;

    cin >> q;
    
    while(q--){
        cin >> s;
        cin >> n >> k;
        k %= n;
        k = n - k;
        for(int j = 0; j < s.size(); j++){
            c = j - (j % n);
            i = j % n;
            i += k;
            i %= n;
            cout << s[c + i];
        }
        cout << "\n";
    }

    return 0;
}
/*
2
abcdefghi
3 1
abcdefghi
3 2
*/