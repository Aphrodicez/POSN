#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int q, n;

    cin >> q;

    while(q--){

        cin >> n;

        for(int i = 1; i <= n + 2; i++){
            for(int j = 1; j <= n - i + 2; j++){
                cout << ".";
            }
            for(int j = 1; j <= i; j++){
                cout << "#";
            }
            for(int j = 1; j <= n+2; j++){
                if(j == 1 || j==n+2 || i == 1 || i == n+2)
                    cout << "+";
                else
                    cout << "#";
            }
            cout << "\n";
        }

        for(int i = 1; i <= n+2; i++){
            for(int j = 1; j <= n+2; j++){
                if(j == 1 || j==n+2 || i == 1 || i == n+2)
                    cout << "#";
                else
                    cout << "+";
            }
            for(int j = 1; j <= n - i + 3; j++){
                cout << "+";
            }
            for(int j = 1; j <= i - 1; j++){
                cout << ".";
            }
            cout << "\n";
        }
    }

    return 0;
}