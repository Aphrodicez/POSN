/*
    TASK    : 0
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

struct A{
    int i, j, w;
    bool operator < (const A& o) const{
        return w > o.w;
    }
};

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int a[1010][1010];

priority_queue <A> he;
A now;

int dis[1010][1010];

int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

int main(){
    setIO();
    int n, ch = 1, i, j, sti, stj;
    cin >> n;
    memset(dis, -1, sizeof dis);
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cin >> a[i][j];
            if(a[i][j]==0 && ch){
                sti = i;
                stj = j;
                he.push({sti, stj, 0});
                dis[i][j] = 0;
                ch = 0;
            }
        }
    }
    while(!he.empty()){
        now = he.top();
        he.pop();
        if(a[now.i][now.j]==0 && now.i!=sti && now.j!=stj){
            cout << now.w << endl;
            return 0;
        }
        for(int k = 0; k < 4; k++){
            i = now.i + di[k], j = now.j + dj[k];
            if(i < 1 || j < 1 || i > n || j > n)
                continue;
            if(dis[i][j] != -1)
                continue;
            if(i==sti && j==stj)
                continue;
            dis[i][j] = max(now.w, a[i][j]);
            he.push({i, j, dis[i][j]});
        }
    }
    return 0;
}
/*
3
10 100 10
0 10 100
12 5 0
*/
/*
5
1 1 1 0 1
3 1 1 1 1
0 3 4 3 2
1 1 1 4 1
1 4 2 2 2
*/