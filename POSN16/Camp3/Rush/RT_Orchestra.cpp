/*
    TASK    : 0
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main(){
    setIO();
    int n, m, k, num, i = 1, sum = 0;
    cin >> n >> m >> k;
    for(i=1; i<=n; i++){
        cin >> num;
    }
    i = 1;
    while(1){

        if(n<=(k+1))
            break;        
        sum += i * (k+1);
        n -= (k+1);
        i++;
        cout << i << "\n";
    }
    cout << sum;
    return 0;
}
/*
5 1 2
1 1 1 1 1
*/