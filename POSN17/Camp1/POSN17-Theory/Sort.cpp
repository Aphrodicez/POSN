/*
Sort Every F***in thing
int Max -> Min
double Min -> Max
char Max -> Max
string Min -> Max
*/

#include <bits/stdc++.h>
using namespace std;

struct A{
    int intt;
    double doublee;        
    char charr;
    char stringg[510];
    bool operator < (const A & o) const{
        if(intt != o.intt)
            return intt > o.intt;
        if(doublee != o.doublee)
            return doublee < o.doublee;
        if(charr != o.charr)
            return charr > o.charr;       
        if(strcmp(stringg, o.stringg) < 0)
            return true;
        else
            return false;
    }
};

A a[10010];

int main(){
    int n;
    for(int i = 0; i < n; i++){
        scanf("%d %lf %c %s", &a[i].intt, &a[i].doublee, &a[i].charr, a[i].stringg);
    }
    sort(a, a + n);
    return 0;
}
