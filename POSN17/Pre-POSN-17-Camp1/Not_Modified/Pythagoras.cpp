#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    double a, b, c;

    cin >> a >> b >> c;

    if(!c){
        cout << fixed << setprecision(2) << sqrt(a*a + b*b);
    }
    else{
        b = max(a, b);
        cout << fixed << setprecision(2) << sqrt(c*c - b*b);
    }

    return 0;
}