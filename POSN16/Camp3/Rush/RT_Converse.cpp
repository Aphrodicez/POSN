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

//int a[100010], b[100010], 
int cnt1[6], cnt2[6];

int main(){
    //setIO();
    //cin >> q;
    int q, n, i, a, b;
    scanf("%d", &q);
    while(q--){
        int ans = 0, ch = 1, usea = 0, useb = 0;
        memset(cnt1, 0, sizeof cnt1);
        memset(cnt2, 0, sizeof cnt2);
        scanf("%d", &n);
        for(i=0; i<n; i++){
            scanf("%d", &a);
            cnt1[a]++;
        }
        for(i=0; i<n; i++){
            scanf("%d", &b);
            cnt2[b]++;
        }
        for(i=1; i<=5; i++){
            if((cnt1[i]+cnt2[i])%2!=0){
                //printf("%d\n", cnt2[i]);
                ch = 0;
                break;
            }
            ans += (cnt2[i] - cnt1[i]) / 2;
            if(cnt1[i] > cnt2[i]){
                usea += (cnt1[i] - cnt2[i]) / 2;
            }
            else{
                useb += (cnt2[i] - cnt1[i]) / 2;
            }
        }
        if(ch && usea==useb){
            printf("%d\n", usea);
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}
/*
2
9
1 2 4 1 4 1 4 4 1
2 3 5 2 5 3 2 3 3
5
1 2 3 4 5
1 1 2 3 5
*/