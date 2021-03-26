#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int q, n;

    cin >> q;

    while(q--){
        cin >> n;
        for(int i = 1; i <= 1 + 2 * n; i++){
            for(int j = 1; j <= 1 + 2*n; j++){
                if(i == 1 || j == 1){
                    cout << "*";
                }
                else if(i % 2 == 1){
                    if(j <= i){
                        cout << "*";
                    }
                    else if(j % 2 == 1){
                        cout << "*";
                    }
                    else{
                        cout << "-";
                    }
                }
                else if(i <= j){
                    if(j % 2 == 1)
                        cout << "*";
                    else
                        cout << "-";
                }
                else
                    cout << "-";
            }
            cout << "\n";
        }
    }
    return 0;
}