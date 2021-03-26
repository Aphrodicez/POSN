/*
    TASK    : Monkey_TOI10
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

struct A{
    int idx, h;
    bool operator < (const A& o) const{
        return h < o.h;
    }
};

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int m, n, k, now, h, i, start, nans, mx;

int b[200010], st[200010], en[200010];
int st2[200010], en2[200010];

A rope[1000010];

int main(){
    setIO();
    cin >> m >> n >> k;
    for(i=1; i<=n; i++){
        cin >> b[i];
        st[i] = en[i] = st2[i] = en2[i] = i;
    }
    for(i=1; i<=k; i++)
        cin >> rope[i].idx >> rope[i].h;
    sort(rope + 1, rope + k + 1);
    for(i=1; i<=k; i++){
        swap(st[en[rope[i].idx]], st[en[rope[i].idx+1]]);
        swap(en[rope[i].idx], en[rope[i].idx+1]);
    }
    cin >> start;
    nans = b[st[start]];
    for(i=1; i<=k; i++){
        swap(st2[en2[rope[i].idx]], st2[en2[rope[i].idx + 1]]);
        swap(en2[rope[i].idx], en2[rope[i].idx + 1]);
        if(rope[i].h == rope[i+1].h)    continue;
        mx = max(mx, b[st[en2[st2[start] + 1]]]);
        mx = max(mx, b[st[en2[st2[start] - 1]]]);
    }

    if(nans >= mx){
        cout << nans << "\nNO";
    }

    else{
        cout << mx << "\nUSE";
    }

    return 0;
}
/*
20 5 6
7 5 3 9 4
1 5
1 6
2 10
1 12
3 6
3 13
1
*/
