#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int n;

    cin >> n;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j <= i; j++){
            cout << "*";
        }
        for(int j = 0; j < 2*n - 3 - (2 * i); j++){
            cout << "-";
        }
        for(int j = 0; j <= i; j++){
            cout << "*";
        }
        cout << "\n";
    }
    for(int j = 0; j < 2 * n - 1; j++)
        cout << "*";
    cout << "\n";

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            cout << "*";
        }

        for(int j = 0; j < 1 + (2 * i); j++){
            cout << "-";
        }

        for(int j = 0; j < n - i - 1; j++){
            cout << "*";
        }
        cout << "\n";
    }
    

    return 0;
}