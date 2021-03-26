/*
    TASK    : Raider_TOI10
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

#define MOD 2520

struct A{
    long long i, j, state;
};

long long dis[2530][110][110];

queue<A> bfs;

A now;

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

long long a[110][110], di[] = {0, -1, -1, 0, 1, 1};
long long dj[2][6] = {{1, 1, 0, -1, 0, 1}, {1, 0, -1, -1, -1, 0}};

long long r, c, i, j, sum, k, nexti, nextj, nextstate, cnt;

int main(){
    setIO();
    cin >> r >> c;
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            cin >> a[i][j];
        }
    }

    memset(dis, -1, sizeof dis);

    for(i=-1; i<=1; i++){
        sum = (r-1)/2 + i;
        if(a[sum][0]==1){
            bfs.push({sum, 0, 1});
            dis[1][sum][0] = 1;
        }
    }

    while(!bfs.empty()){
        now = bfs.front();
        bfs.pop();

        if(now.i == (r-1)/2 && now.j==c-1){
            cout << dis[now.state % MOD][now.i][now.j] << "\n";
            return 0;
        }
        for(k=0; k<6; k++){
            nexti = now.i + di[k], nextj = now.j + dj[now.i%2][k], nextstate = now.state + 1;
            if(nexti < 0 || nexti >= r || nextj < 0 || nextj >= c)
                continue;
            if(!a[nexti][nextj])
                continue;
            if(nextstate % a[nexti][nextj] != 0)
                continue;
            if(dis[nextstate%MOD][nexti][nextj] != -1)
                continue;
            dis[nextstate%MOD][nexti][nextj] = nextstate;

            bfs.push({nexti, nextj, nextstate});
        }
    }
    return 0;
}
/*
5
4
1 1 3 8
0 1 1 0
1 6 5 7
1 3 2 3
2 5 2 0
*/
