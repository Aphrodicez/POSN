/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Queue
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

queue <int> quc, qus[20];
int mp[10010];

void solve() {
    int nc, ns;
    scanf("%d %d", &nc, &ns);
    int c, s;
    for(int i = 1; i <= ns; i++) {
        scanf("%d %d", &c, &s);
        mp[s] = c;
    }
    while(1) {
        char opr;
        scanf(" %c", &opr);
        if(opr == 'X') {
            printf("0\n");
            break;
        }
        if(opr == 'E') {
            int id;
            scanf("%d", &id);
            if(qus[mp[id]].empty())
                quc.push(mp[id]);
            qus[mp[id]].push(id);
            continue;
        }
        if(opr == 'D') {
            if(quc.empty()) {
                printf("empty\n");
                continue;
            }
            int c_id = quc.front();
            printf("%d\n", qus[c_id].front());
            qus[c_id].pop();
            if(qus[c_id].empty())
                quc.pop();
        }
    }
}

int main() {
    int q = 1;
    
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

/*
2 6
1 41
1 42
1 43
2 201
2 202
2 203
E 41
E 201
D
E 202
E 42
E 43
D
E 203
D
D
D
X
*/