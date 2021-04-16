#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int n, it;

    cin >> n;

    for(int i = 1; i <= n; i++){
        cout << i << " ";
    }
    cout << "\n";
    it = n;
    while(it > 0){
        cout << it-- << " ";
    }
    cout << "\n";
    it = 2;
    do{
        if(n < 2)
            break;
        cout << it << " ";
        it += 2;
    }while(it <= n);
    cout << "\n";

    for(int i = n - (n % 2); i > 1; i-=2){
        cout << i << " ";
    }
    cout << "\n";

    it = 1;

    while(it <= n){
        cout << it << " ";
        it += 2;
    }

    cout << "\n";

    it = n - !(n%2);

    do{
        cout << it << " ";
        it -= 2;
    }while(it >=1);

    return 0;
}