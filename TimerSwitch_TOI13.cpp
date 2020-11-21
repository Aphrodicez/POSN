/*
    TASK    : Timer_Switch_TOI13
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

/*void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}*/

int n, i, len, it, mx;

// it = iterator

char a[10000010];

int pre[5000010];

int main(){
    //setIO();
    scanf("%d", &n);
    scanf(" %s", a + 1);
    for(i=1; i<=n; i++){
        a[i+n] = a[i];
    }
    for(i=2; i<=n*2; i++){
        while(it > 0 && a[it+1] != a[i])
            it = pre[it];
        if(a[it+1]==a[i])
            it++;
        pre[i] = it;
        if(it==n){
            printf("%d", i - n);
            return 0;
        }
    }
    return 0;
}
/*
10
1010101010
*/
/*
10
1000000010
*/
/*
8
10011001
*/
/*
4
1100
*/
/*
10
1000100000
*/
/*
6
010101
*/
