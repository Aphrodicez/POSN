/*
    TASK    : FC_RoadCube
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

struct A{
    int idx, val;
};

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

deque <A> deq;

int dp[110][10010];

int main(){
    //setIO();
    int r, c, range, mx = 0;
    cin >> r >> c >> range;
    for(int i=1; i<=r; i++){
        int k = 1;
        for(int j=1; j<=c; j++){
            cin >> dp[i][j];
            if(i==1)
                continue;
            while(k <= c && k <= j + range){
                while(!deq.empty() && deq.back().val < dp[i-1][k])
                    deq.pop_back();
                deq.push_back({k, dp[i-1][k]});
                k++;
            }
            while(!deq.empty() && deq.front().idx < j - range)
                deq.pop_front();
            dp[i][j] += deq.front().val;
            //cout << deq.front().val << " ";
            mx = max(mx, dp[i][j]);
        }        
        
        while(!deq.empty())
            deq.pop_back();
        //cout << "\n";

    }
    /*
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << mx;
    return 0;
}
/*
8 5 2
0 0 5 4 0
2 0 7 0 0
0 8 0 3 0
9 0 0 0 0
0 0 1 9 0
0 0 0 0 9
0 0 0 0 9
9 0 1 0 0
*/
/*
3 2 0
99 98
30 40
60 52
*/
/*
*/