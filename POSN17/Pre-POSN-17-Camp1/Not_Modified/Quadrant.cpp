#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    n %= 360;

    n = (n + 360) % 360;

    if(n % 90 == 0){
        if(n % 180 == 0)
            cout << "x-axis";
        else
            cout << "y-axis";
    }
    else{
        cout << n / 90 + 1; 
    }

    return 0;
}