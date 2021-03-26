#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int r, c, bricks;

    cin >> r >> c;

    char a[r + 1][c + 1];

    int firststone[c + 1];

    for(int j = 1; j <= c; j++){
        firststone[j] = r + 1;
    }

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> a[i][j];
            if(a[i][j] == 'O'){
                if(firststone[j] > i){
                    firststone[j] = i;
                }
            }
        }
    }

    for(int j = 1; j <= c; j++){
        cin >> bricks;
        for(int i = max(1, firststone[j]) - 1; i >= 1 && bricks > 0; i--, bricks--){
            a[i][j] = '#';
        }
    }

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cout << a[i][j];
        }
        cout << "\n";
    }

    return 0;
}
/*
8 5
.....
.....
.OO..
.....
.O...
...O.
.....
.....
1 1 3 2 0
*/