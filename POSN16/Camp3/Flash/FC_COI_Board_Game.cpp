/*
    TASK    : 0
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

struct A{
    int i, j, w, nowbit;
};

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

char a[510][510];

int bw[10];

queue <A> bfs;

A now;

int dis[1<<4][510][510];

int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

int main(){
    //setIO();
    int r, c, ii, jj, nextbit;
    cin >> r >> c;
    bw[0] = 1;
    for(int i=1; i<=4; i++){
        bw[i] = bw[i-1] * 2;
    }
    memset(dis, -1, sizeof dis);
    for(int i=1; i<=r; i++){
        cin >> a[i] + 1;
        for(int j=1; j<=c; j++){
            if(a[i][j]=='S'){
                bfs.push({i, j, 0, 0});
                dis[0][i][j] = 0;
            }
        }
    }
    while(!bfs.empty()){
        now = bfs.front();
        bfs.pop();
        //cout << now.i << " " << now.j << " " << now.w << " " << now.nowbit << "\n";
        if(a[now.i][now.j] == 'E'){
            cout << now.w;
            return 0;
        }

        for(int k = 0; k < 4; k++){
            ii = now.i + di[k], jj = now.j + dj[k];
            nextbit =  0;
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj]=='#')
                continue;
            if(isupper(a[ii][jj])){
                if(a[ii][jj]=='J')
                    nextbit = bw[0];
                else if(a[ii][jj]=='B')
                    nextbit = bw[1];
                else if(a[ii][jj]=='P')
                    nextbit = bw[2];

                if(nextbit & now.nowbit != nextbit){
                    cout << "LMAO " << ii << " " << jj << "\n";
                    continue;
                }
                cout << ii << " " << jj << " " << now.nowbit << " " << nextbit << "\n";
                nextbit = 0;
            }
            else if(islower(a[ii][jj])){
                nextbit = 0;
                if(a[ii][jj]=='j'){
                    nextbit = bw[0];
                }
                else if(a[ii][jj]=='b'){
                    nextbit = bw[1];
                }
                else if(a[ii][jj]=='p'){
                    nextbit = bw[2];
                }
            }

            if(dis[now.nowbit | nextbit][ii][jj]!=-1)
                continue;
            dis[now.nowbit | nextbit][ii][jj] = now.w + 1;
            bfs.push({ii, jj, now.w + 1, now.nowbit | nextbit});
        }
    }
    return 0;
}
/*
2 5
S.J.b
.jB.E
*/
