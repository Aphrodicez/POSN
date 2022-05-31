/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Greedy Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e3 + 10;

priority_queue <pair <int, int>> a;
priority_queue <int> pq;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);
            a.emplace(make_pair(i + j, val));
        }
    }
    int ans = 0;
    for(int t = 2 * (n - 1); t >= 1; t--) {
        while(!a.empty() && a.top().first >= t) {
            pq.emplace(a.top().second);
            a.pop();
        }
        ans += pq.top();
        pq.pop();
    }
    printf("%d\n", ans);
    return 0;
}

/*
3
1 2 3
4 5 6
7 8 9
*/