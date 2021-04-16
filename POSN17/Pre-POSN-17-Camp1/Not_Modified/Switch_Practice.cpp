#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    string s[] = {" ", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    int n;
    cin >> n;
    if(n < 1 || n > 7){
        cout << "Not a day";
        return 0;
    }
    cout << s[n];
    return 0;
}