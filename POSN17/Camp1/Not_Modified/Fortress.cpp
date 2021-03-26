#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int q = 20, n, m, centre;

    while(q--){
        cin >> n >> m;
        centre = n - 2*m;
        centre /= 2;
        if(centre < 0 || 4*centre > n){
            cout << 0 << "\n";
            continue;
        }
        n -= 4 * centre;
        n /= 2;
        cout << n + 1 << "\n";
    }

    return 0;
}
/*
40 15
30 12
60 40
50 18
66 26
36 11
36 16
36 18
56 20
56 22
44 18
32 14
42 20
36 16
38 14
38 16
34 20
36 16
44 14
34 14
*/