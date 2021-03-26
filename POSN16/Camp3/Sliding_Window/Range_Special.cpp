/*
    TASK    : Range_Special
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll n, l, r, i, j, sum;

ll a[1000010];

deque <ll> mi, ma;

int main(){
    //setIO();
    scanf("%lld %lld %lld", &n, &l, &r);
    j = 0;
    for(i=0; i<n; i++){
        scanf("%lld", &a[i]);
        while(!ma.empty() && a[i] > a[ma.back()])
            ma.pop_back();
        while(!mi.empty() && a[i] < a[mi.back()])
            mi.pop_back();
        ma.push_back(i);
        mi.push_back(i);
        while(!ma.empty() && !mi.empty() && a[ma.front()] - a[mi.front()] > r){
            j++;
            while(!ma.empty() && ma.front() < j)
                ma.pop_front();
            while(!mi.empty() && mi.front() < j)
                mi.pop_front();
        }
        sum += i - j + 1;
    }
    while(!ma.empty())
        ma.pop_back();
    while(!mi.empty())
        mi.pop_back();
    j = 0;
    for(i=0; i<n; i++){
        while(!ma.empty() && a[i] > a[ma.back()])
            ma.pop_back();
        while(!mi.empty() && a[i] < a[mi.back()])
            mi.pop_back();
        ma.push_back(i);
        mi.push_back(i);
        while(!ma.empty() && !mi.empty() && a[ma.front()] - a[mi.front()] > l - 1){
            j++;
            while(!ma.empty() && ma.front() < j)
                ma.pop_front();
            while(!mi.empty() && mi.front() < j)
                mi.pop_front();
        }
        sum -= i - j + 1;
    }
    printf("%lld\n", sum);
    return 0;
}
/*
7 4 6
1
7
4
3
9
6
8
*/