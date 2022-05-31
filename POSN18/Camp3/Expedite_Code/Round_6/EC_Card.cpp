/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Greedy Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e4 + 10;

bitset <2 * MaxN> isOpponent;

vector <int> me;
vector <int> opponent[2];

void solve() {
    isOpponent = 0;
    me.clear();
    for(int i = 0; i < 2; i++) {
        opponent[i].clear();
    }
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        isOpponent[val] = true;
        opponent[i & 1].emplace_back(val);
    }
    sort(opponent[0].begin(), opponent[0].end());
    sort(opponent[1].begin(), opponent[1].end(), greater<int>());
    for(int i = 1; i <= 2 * n; i++) {
        if(!isOpponent[i])
            me.emplace_back(i);
    }
    int ans = 0;
    int i;
    i = 0;
    for(auto x : opponent[0]) {
        if(me[i] > x)
            continue;
        ans++;
        i++;
    }
    i = me.size() - 1;
    for(auto x : opponent[1]) {
        if(me[i] < x)
            continue;
        ans++;
        i--;
    }
    printf("%d\n", ans);
}

int main() {
    int q = 1;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

/*
3
8
12 10 9 2 7 8 3 5
6
6 5 7 9 2 3
6
9 6 8 2 5 4
*/