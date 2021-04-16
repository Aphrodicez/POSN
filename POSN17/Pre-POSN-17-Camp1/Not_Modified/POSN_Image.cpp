#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int q;

    cin >> q;

    while(q--){

        int n;

        cin >> n;

        for(int i = 1; i <= 1; i++){
            for(int j = 1; j <= n; j++){
                cout << "*";
            }
            cout << "-";
            for(int j = 1; j <= n; j++){
                cout << "*";
            }
            cout << "-";
            for(int j = 1; j <= n; j++){
                cout << "*";
            }
            cout << "-";
            for(int j = 1; j <= n; j++){
                if(j == 1 || j == n)
                    cout << "*";
                else
                    cout << "-";
            }
            cout << "\n";
        }

        for(int i = 2; i <= n/2; i++){
            for(int j = 1; j <= n; j++){
                if(j == 1 || j == n)
                    cout << "*";
                else
                    cout << "-";
            }
            cout << "-";
            for(int j = 1; j <= n; j++){
                if(j == 1 || j == n)
                    cout << "*";
                else
                    cout << "-";
            }
            cout << "-";
            for(int j = 1; j <= n; j++){
                if(j==1)
                    cout << "*";
                else
                    cout << "-";
            }
            cout << "-";
            for(int j = 1; j <= n; j++){
                if(j == i || j == 1 || j == n)
                    cout << "*";
                else
                    cout << "-";
            }
            cout << "\n";
        }
        for(int i = n/2 + 1; i <= n/2 + 1; i++){
            for(int j = 1; j <= n; j++){
                cout << "*";
            }
            cout << "-";
            for(int j = 1; j <= n; j++){
                if(j==1 || j==n)
                    cout << "*";
                else
                    cout << "-";
            }
            cout << "-";
            for(int j = 1; j <= n; j++){
                cout << "*";
            }
            cout << "-";
            for(int j = 1; j <= n; j++){
                if(j == 1 || j == n || j == i)
                    cout << "*";
                else    
                    cout << "-";
            }
            cout << "\n";
        }

        for(int i = n/2 + 2; i <= n - 1; i++){
            for(int j = 1; j <= n; j++){
                if(j==1)
                    cout << "*";
                else
                    cout << "-";
            }
            cout << "-";
            for(int j = 1; j <= n; j++){
                if(j==1 || j==n)
                    cout << "*";
                else
                    cout << "-";
            }
            cout << "-";
            for(int j = 1; j <= n; j++){
                if(j == n)
                    cout << "*";
                else
                    cout << "-";
            }
            cout << "-";
            for(int j = 1; j <= n; j++){
                if(j == 1 || j==n || j == i)
                    cout << "*";
                else
                    cout << "-";
            }
            cout << "\n";
        }

        for(int i = n; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(j == 1)
                    cout << "*";
                else
                    cout << "-";
            }
            cout << "-";
            for(int j = 1; j <= n ; j++){
                cout << "*";
            }
            cout << "-";
            for(int j = 1; j <= n ; j++){
                cout << "*";
            }
            cout << "-";
            for(int j = 1; j <= n; j++){
                if(j == 1 || j == n || j==i)
                    cout << "*";
                else
                    cout <<  "-";
            }
            cout << "\n";
        }
    }
    return 0;
}