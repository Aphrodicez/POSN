#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int n, num;

    cin >> n;

    while(n--){
        cin >> num;
        while(num >= 1000)
            cout << 'M', num -= 1000;
        while(num >= 900)
            cout << "CM", num -= 900;
        while(num >= 500)
            cout << 'D', num -= 500;
        while(num >= 400)
            cout << "CD", num -= 400;
        while(num >= 100)
            cout << 'C', num -= 100;
        while(num >= 90)
            cout << "XC", num -= 90;
        while(num >= 50)
            cout << 'L', num -= 50;
        while(num >= 40)
            cout << "XL", num -= 40;
        while(num >= 10)
            cout << 'X', num -= 10;
        while(num >= 9)
            cout << "IX", num -= 9;
        while(num >= 5)
            cout << 'V', num -= 5;
        while(num >= 4)
            cout << "IV", num -= 4;
        while(num >= 1)
            cout << 'I', num -= 1;
        cout << "\n";
    }

    return 0;
}