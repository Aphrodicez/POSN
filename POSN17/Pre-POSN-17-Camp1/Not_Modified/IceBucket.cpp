#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int q, g, k;

    cin >> q;

    while(q--){
        int cnt = 1, ans = 0;
        cin >> g >> k;
        while(1){
            if(g - (100 * cnt) > 0){
                /// unfinished
                ans++;
                g -= 10;
                cnt--;
                cnt += k;
            }
            else{
                break;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}