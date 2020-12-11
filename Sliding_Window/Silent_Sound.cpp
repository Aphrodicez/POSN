/*
    TASK    : Silent_Sound
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

deque <int> ma, mi;

int n, range, target, i, ch = 1;

int a[1000010];

int main(){
    //setIO();
    scanf("%d %d %d", &n, &range, &target);
    for(i=1; i<=n; i++){
        scanf("%d", &a[i]);
        while(!ma.empty() && a[i] > a[ma.back()])
            ma.pop_back();
        while(!ma.empty() && i - range >= ma.front())
            ma.pop_front();
        while(!mi.empty() && a[i] < a[mi.back()])
            mi.pop_back();
        while(!mi.empty() && i - range >= mi.front())
            mi.pop_front();
        ma.push_back(i), mi.push_back(i);
        //printf("%d %d\n",a[ma.front()], a[mi.front()]);
        if(a[ma.front()]-a[mi.front()] <= target && i >= range){
            printf("%d\n", i - range + 1);
            ch = 0;
        }
    }
    if(ch){
        printf("NONE");
    }
    return 0;
}
/*
7 2 0
0 1 1 2 3 2 2
*/