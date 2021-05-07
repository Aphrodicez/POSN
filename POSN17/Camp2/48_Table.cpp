/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Heap
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

struct A{
    int i, j, val, state;
    bool operator < (const A &o) const{
        if(val != o.val)
            return val > o.val;
        return state > o.state;
    }
};

const int R = 3e2 + 10;
const int C = 5e3 + 10;

int rowcount[R];

A row[R];

A table[R][C];

priority_queue <A> he;

void solve(){
    int r, c, m, opr, i, j, val;
    cin >> r >> c >> m;
    for(int i = 1; i <= r; i++){
        he.push({i, 0, 0, 0});
    }
    for(int state = 1; state <= m; state++){
        cin >> opr;
        if(opr == 1){
            cin >> i >> j >> val;            
            if(table[i][j].state <= row[i].state){
                rowcount[i]++;
            }
            table[i][j].state = state;
            table[i][j].val = val;
            he.push({i, j, val, state});
        }
        if(opr == 2){
            cin >> i >> val;
            row[i].state = state;
            row[i].val = val;
            rowcount[i] = 0;
            he.push({i, 0, val, state});
        }
        if(opr == 3){
            cin >> i >> j;
            if(table[i][j].state < row[i].state)
                cout << row[i].val << "\n";
            else
                cout << table[i][j].val << "\n";
        }
        if(opr == 4){
            while(!he.empty()){
                A tmp = he.top();
                if( (tmp.j == 0) && (tmp.state == row[tmp.i].state) && (rowcount[tmp.i] < c) )
                    break;
                else if( (tmp.j != 0) && (tmp.state == max(table[tmp.i][tmp.j].state, row[tmp.i].state)) )
                    break;
                he.pop();
            }
            A tmp = he.top();
            cout << tmp.val << "\n";
        }
    }
}

int main() {
    setIO();
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
3 3 14
3 1 2
4
2 1 100
2 2 10
2 3 40
4
1 2 1 50
1 2 3 200
4
1 3 3 25
3 3 2
4
1 2 2 60
4
*/