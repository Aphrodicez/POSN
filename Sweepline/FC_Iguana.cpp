/*
    TASK    : 0
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



vector <pair<int, int>> vec;

int main(){
    //setIO();
    int n, m, l, r, want, i, sum = 0, ans = 0, now, amt;
    char col;
    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%d %d", &l, &r);
        vec.push_back({l, 1});
        vec.push_back({r+1, -1});
    }
    vec.push_back({1, 0});
    vec.push_back({n + 1, 0});    
    sort(vec.begin(), vec.end());
    scanf(" %c", &col);
    if(col == 'R')
        want = 0;
    else if(col == 'G')
        want = 1;
    else if(col == 'B')
        want = 2;
    for(i=0; i<vec.size() - 1; i++){
        sum += vec[i].second;
        amt =  vec[i+1].first - vec[i].first;
        now = sum % 3;
        ans += ((want-now+3)%3) * amt;
    }
    printf("%d\n", ans);
    return 0;
}
/*
3 2
1 2
2 3
R
*/